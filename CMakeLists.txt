cmake_minimum_required(VERSION 3.20)

# ── 工具链 ──────────────────────────────────────────────────────────
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER   arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_OBJCOPY      arm-none-eabi-objcopy)
set(CMAKE_SIZE         arm-none-eabi-size)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# STM32G431 = Cortex-M4F，硬件 FPU
set(CPU_FLAGS "-mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard")

set(CMAKE_C_FLAGS_INIT           "${CPU_FLAGS}")
set(CMAKE_ASM_FLAGS_INIT         "${CPU_FLAGS} -x assembler-with-cpp")
set(CMAKE_EXE_LINKER_FLAGS_INIT  "${CPU_FLAGS} -specs=nano.specs -Wl,--no-warn-rwx-segments")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(stm32g431_freertos C ASM)

# ── 路径 ────────────────────────────────────────────────────────────
set(CUBE      ${CMAKE_SOURCE_DIR}/third_party/STM32CubeG4)
set(CMSIS_INC ${CUBE}/Drivers/CMSIS/Include)
set(DEV_INC   ${CUBE}/Drivers/CMSIS/Device/ST/STM32G4xx/Include)
set(DEV_SRC   ${CUBE}/Drivers/CMSIS/Device/ST/STM32G4xx/Source/Templates)
set(HAL_INC   ${CUBE}/Drivers/STM32G4xx_HAL_Driver/Inc)
set(HAL_SRC   ${CUBE}/Drivers/STM32G4xx_HAL_Driver/Src)
set(RTOS      ${CUBE}/Middlewares/Third_Party/FreeRTOS/Source)

set(APP_INC   ${CMAKE_SOURCE_DIR}/src/config)
set(APP_SRC   ${CMAKE_SOURCE_DIR}/src)

# ── 公共编译定义 ────────────────────────────────────────────────────
set(COMMON_DEFS STM32G431xx USE_HAL_DRIVER)
set(COMMON_OPTS -ffunction-sections -fdata-sections -Os -Wall)

# ── FreeRTOS 内核 ──────────────────────────────────────────────────
add_library(freertos_kernel STATIC
    ${RTOS}/tasks.c
    ${RTOS}/queue.c
    ${RTOS}/list.c
    ${RTOS}/timers.c
    ${RTOS}/event_groups.c
    ${RTOS}/stream_buffer.c
    ${RTOS}/portable/GCC/ARM_CM4F/port.c
    ${RTOS}/portable/MemMang/heap_4.c
)

target_include_directories(freertos_kernel PUBLIC
    ${RTOS}/include
    ${RTOS}/portable/GCC/ARM_CM4F
    ${CMSIS_INC}
    ${DEV_INC}
    ${HAL_INC}
    ${APP_INC}
)

target_compile_definitions(freertos_kernel PUBLIC ${COMMON_DEFS})
target_compile_options(freertos_kernel PRIVATE ${COMMON_OPTS})

# ── STM32 HAL 静态库 ───────────────────────────────────────────────
file(GLOB_RECURSE HAL_ALL_SRC
    ${HAL_SRC}/*.c
    ${DEV_SRC}/*.c
)
list(FILTER HAL_ALL_SRC EXCLUDE REGEX ".*_template\\.c$")

add_library(stm32_hal STATIC ${HAL_ALL_SRC})

target_include_directories(stm32_hal PUBLIC
    ${CMSIS_INC}
    ${DEV_INC}
    ${HAL_INC}
    ${APP_INC}
)

target_compile_definitions(stm32_hal PUBLIC ${COMMON_DEFS})
target_compile_options(stm32_hal PRIVATE ${COMMON_OPTS})

# ── 子目录 ──────────────────────────────────────────────────────────
add_subdirectory(${APP_SRC}/device)
add_subdirectory(${APP_SRC}/app)
add_subdirectory(${APP_SRC}/system)

# ── 应用可执行文件 ─────────────────────────────────────────────────
add_executable(firmware.elf
    ${DEV_SRC}/gcc/startup_stm32g431xx.s
    ${APP_SRC}/main.c
    ${APP_SRC}/init.c
)

target_include_directories(firmware.elf PRIVATE ${APP_SRC} ${APP_INC})
target_link_libraries(firmware.elf PRIVATE
    -Wl,--whole-archive
    app system stm32_hal freertos_kernel
    -Wl,--no-whole-archive
)
target_compile_options(firmware.elf PRIVATE ${COMMON_OPTS} -Wextra)

target_link_options(firmware.elf PRIVATE
    -T${APP_SRC}/stm32g431.ld
    -Wl,--gc-sections
    -Wl,-Map=firmware.map
)

# ── 生成 .bin 并打印大小 ──────────────────────────────────────────
add_custom_command(TARGET firmware.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary firmware.elf firmware.bin
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_SOURCE_DIR}/cmake/print_size.cmake
            firmware.elf firmware.bin
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# ── OpenOCD 烧录（ST-Link）─────────────────────────────────────────
find_program(OPENOCD openocd)

add_custom_target(flash
    DEPENDS firmware.elf
    COMMAND ${OPENOCD}
        -f interface/stlink.cfg
        -f target/stm32g4x.cfg
        -c "program ${CMAKE_BINARY_DIR}/firmware.bin 0x08000000 verify reset exit"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Flashing firmware.bin via OpenOCD + ST-Link ..."
)
