add_library(system STATIC
    clock.c
    internal/hal_tim_base.c
    internal/system_it.c
    internal/syscalls.c
    internal/rtos_hook.c
)

target_include_directories(system PUBLIC ${APP_SRC} ${APP_INC})

target_compile_definitions(system PUBLIC ${COMMON_DEFS})
target_compile_options(system PRIVATE ${COMMON_OPTS})
target_link_libraries(system PUBLIC stm32_hal freertos_kernel)
