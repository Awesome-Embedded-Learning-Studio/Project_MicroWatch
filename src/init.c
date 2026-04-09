/**
 * @file init.c
 * @author Charliechen114514 (chengh1922@mails.jlu.edu.cn)
 * @brief Expose only one thing, hardwares setups
 * @version 0.1
 * @date 2026-04-09
 *
 * @copyright Copyright (c) 2026
 *
 */

#include "device/device_init.h"
#include "stm32g4xx_hal.h"
#include "system/clock.h"
void system_init(void) {
    // HAL Should be enabled all the first
    HAL_Init();
    watch_clock_setup();

    /*
     * Init devices
     */
    watch_device_init();
}
