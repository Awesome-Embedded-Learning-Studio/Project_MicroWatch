#pragma once
#include "FreeRTOS.h"
#include "task.h"
#include <stdbool.h>
#include <stdint.h>

typedef void (*AppTickFn)(void* ctx);

typedef struct WatchApp {
    AppTickFn on_tick;
    void* ctx;
    volatile bool running;
    TaskHandle_t native_handle;
} WatchApp;

WatchApp* watch_app_register(AppTickFn tick_fn, void* ctx, const char* name);
void watch_app_stop(WatchApp* app);

void watch_app_delay_ms(const uint16_t delay_ms);
