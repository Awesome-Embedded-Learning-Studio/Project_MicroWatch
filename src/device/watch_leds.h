/**
 * @file watch_leds.h
 * @author Charliechen114514 (chengh1922@mails.jlu.edu.cn)
 * @brief Watch LEDs setups usage
 * @version 0.1
 * @date 2026-04-09
 *
 * @copyright Copyright (c) 2026
 *
 */
#pragma once

void watch_device_led_setup(void);

typedef enum WatchLED { LED0, LED1 } WatchLED;

void watch_device_led_set(WatchLED led, int is_on);
void watch_device_led_toggle(WatchLED led);
