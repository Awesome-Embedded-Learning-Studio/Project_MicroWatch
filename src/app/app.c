#include "app.h"
#include "app/app_settings.h"
#include "portable.h"

static void app_task_entry(void* param) {
    WatchApp* app = (WatchApp*)param;
    while (app->running) {
        app->on_tick(app->ctx);
    }
    vTaskDelete(NULL);
}

WatchApp* watch_app_register(AppTickFn tick_fn, void* ctx, const char* name) {
    WatchApp* app = pvPortMalloc(sizeof(WatchApp));
    app->on_tick = tick_fn;
    app->ctx = ctx;
    app->running = true;

    xTaskCreate(app_task_entry, name, APP_COMMOB_STACK_SZ, app, APP_COMMON_PRIORITY,
                &app->native_handle);

    return app;
}

void watch_app_stop(WatchApp* app) {
    app->running = false;
}

void watch_app_delay_ms(const uint16_t delay_ms) {
    vTaskDelay(pdMS_TO_TICKS(delay_ms));
}
