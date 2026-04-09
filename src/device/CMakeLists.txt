add_library(device STATIC
    device_init.c
    watch_leds.c
)

target_include_directories(device PUBLIC
    ${APP_SRC}
    ${APP_INC}
)

target_compile_definitions(device PUBLIC ${COMMON_DEFS})
target_compile_options(device PRIVATE ${COMMON_OPTS})
target_link_libraries(device PUBLIC stm32_hal)
