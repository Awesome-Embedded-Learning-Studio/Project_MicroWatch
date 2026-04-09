add_library(app STATIC
    app.c
    app_init.c
    led.app.c
)

target_include_directories(app PUBLIC ${APP_SRC} ${APP_INC})

target_compile_definitions(app PUBLIC ${COMMON_DEFS})
target_compile_options(app PRIVATE ${COMMON_OPTS})
target_link_libraries(app PUBLIC device freertos_kernel)
