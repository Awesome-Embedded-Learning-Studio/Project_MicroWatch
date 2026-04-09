#include "watch_leds.h"
#include "stm32g4xx_hal.h"
#include <stdint.h>

typedef struct {
    GPIO_TypeDef* led_base;
    uint16_t led_pin;
} LEDHandle;

static const LEDHandle led0 = {.led_base = GPIOB, .led_pin = GPIO_PIN_0};
static const LEDHandle led1 = {.led_base = GPIOC, .led_pin = GPIO_PIN_4};

static const LEDHandle* fromEnum(WatchLED led) {
    switch (led) {
        case LED0:
            return &led0;
        case LED1:
            return &led1;
    }
    return NULL;
}

void watch_device_led_setup(void) {
    /* OK, setup the LEDs */
    GPIO_InitTypeDef gpio = {0};

    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    gpio.Mode = GPIO_MODE_OUTPUT_PP;
    gpio.Pull = GPIO_NOPULL;
    gpio.Speed = GPIO_SPEED_FREQ_LOW;

    gpio.Pin = led0.led_pin;
    HAL_GPIO_Init(led0.led_base, &gpio);

    gpio.Pin = led1.led_pin;
    HAL_GPIO_Init(led1.led_base, &gpio);
    watch_device_led_set(LED1, 0);
}

void watch_device_led_set(WatchLED led, int is_on) {
    const LEDHandle* handle = fromEnum(led);
    HAL_GPIO_WritePin(handle->led_base, handle->led_pin, (GPIO_PinState)!is_on);
}

void watch_device_led_toggle(WatchLED led) {
    const LEDHandle* handle = fromEnum(led);
    HAL_GPIO_TogglePin(handle->led_base, handle->led_pin);
}
