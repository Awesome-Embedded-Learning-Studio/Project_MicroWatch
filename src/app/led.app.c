#include "led.app.h"
#include "app/app.h"
#include "device/watch_leds.h"

static void led0_blink_tick(void* ctx) {
    (void)ctx;
    watch_device_led_toggle(LED0);
    watch_app_delay_ms(500);
}

static void led1_blink_tick(void* ctx) {
    (void)ctx;
    watch_device_led_toggle(LED1);
    watch_app_delay_ms(500);
}

void registe_led_app(void) {
    watch_app_register(led0_blink_tick, NULL, "led0");
    watch_app_register(led1_blink_tick, NULL, "led1");
}
