#include "stm32g4xx_hal.h"

/* ── TIM6：HAL timebase ─────────────────────────────────────────── */
extern TIM_HandleTypeDef htim6;

void TIM6_DAC_IRQHandler(void) {
    HAL_TIM_IRQHandler(&htim6);
}

/* HAL 每次 TIM6 溢出都会回调此函数，内部递增 uwTick */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim) {
    if (htim->Instance == TIM6) {
        HAL_IncTick();
    }
}