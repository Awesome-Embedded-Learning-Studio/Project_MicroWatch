#include "FreeRTOS.h"
#include "stm32g4xx_hal.h"
#include "system/clock.h"
#include "task.h"

/**
 * @brief Make these clear
 *
 */
void system_init(void);
void app_init(void);

/* ================================================================== */
/*  main                                                               */
/* ================================================================== */
int main(void) {
    /* HAL 初始化：内部调用 HAL_InitTick() → 初始化 TIM6 */
    system_init();

    app_init();

    /* 启动调度器，此后不返回 */
    vTaskStartScheduler();

    for (;;)
        ;
}
