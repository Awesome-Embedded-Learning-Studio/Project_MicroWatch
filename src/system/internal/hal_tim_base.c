/**
 * TIM6 作为 HAL 的 timebase 来源，替代 SysTick。
 * FreeRTOS 独占 SysTick；HAL_Delay / HAL_GetTick 由 TIM6 驱动。
 */
#include "stm32g4xx_hal.h"

TIM_HandleTypeDef htim6;

/**
 * 覆盖 HAL 中的 weak HAL_InitTick()。
 * HAL_Init() 和 SystemClock_Config() 内部都会调用此函数。
 */
HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority) {
    RCC_ClkInitTypeDef clk = {0};
    uint32_t pFLatency, uwTimclock, uwPrescaler;

    __HAL_RCC_TIM6_CLK_ENABLE();

    HAL_RCC_GetClockConfig(&clk, &pFLatency);

    /* STM32G4: APB1 定时器时钟 = PCLK1 × 2（当 APB1 预分频 > 1 时）*/
    uwTimclock = 2U * HAL_RCC_GetPCLK1Freq();
    uwPrescaler = (uint32_t)((uwTimclock / 1000000U) - 1U);

    htim6.Instance = TIM6;
    htim6.Init.Period = (1000000U / 1000U) - 1U; /* 1 ms */
    htim6.Init.Prescaler = uwPrescaler;
    htim6.Init.ClockDivision = 0U;
    htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

    if (HAL_TIM_Base_Init(&htim6) != HAL_OK) {
        return HAL_ERROR;
    }

    /* TIM6 中断优先级必须 >= configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY
     * 即数值 >= 5，否则在 ISR 中调用 HAL_Delay 会触发断言失败             */
    HAL_NVIC_SetPriority(TIM6_DAC_IRQn, TickPriority, 0U);
    HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);

    return HAL_TIM_Base_Start_IT(&htim6);
}

/** 覆盖 weak HAL_SuspendTick()：FreeRTOS 进入低功耗时调用 */
void HAL_SuspendTick(void) {
    __HAL_TIM_DISABLE_IT(&htim6, TIM_IT_UPDATE);
}

/** 覆盖 weak HAL_ResumeTick() */
void HAL_ResumeTick(void) {
    __HAL_TIM_ENABLE_IT(&htim6, TIM_IT_UPDATE);
}