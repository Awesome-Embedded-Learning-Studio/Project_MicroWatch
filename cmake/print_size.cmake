# cmake/print_size.cmake — 构建后大小报告
# 用法: cmake -P cmake/print_size.cmake <elf> <bin>
cmake_minimum_required(VERSION 3.20)

set(ELF_FILE "${CMAKE_ARGV3}")
set(BIN_FILE "${CMAKE_ARGV4}")

# ── 读取 .bin 文件大小
file(SIZE "${BIN_FILE}" BIN_SIZE)

# ── 用 size 工具获取 berkeley 格式输出
execute_process(
    COMMAND arm-none-eabi-size --format=berkeley "${ELF_FILE}"
    OUTPUT_VARIABLE SIZE_RAW
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# ── 用正则提取 text / data / bss
string(REGEX MATCH "([0-9]+)[\t ]+([0-9]+)[\t ]+([0-9]+)[\t ]+([0-9]+)" _ "${SIZE_RAW}")
set(TEXT_SIZE "${CMAKE_MATCH_1}")
set(DATA_SIZE "${CMAKE_MATCH_2}")
set(BSS_SIZE  "${CMAKE_MATCH_3}")

# ── 计算占用
math(EXPR FLASH_USED  "${TEXT_SIZE} + ${DATA_SIZE}")
math(EXPR RAM_USED    "${DATA_SIZE} + ${BSS_SIZE}")
math(EXPR FLASH_TOTAL "128 * 1024")
math(EXPR RAM_TOTAL   "32  * 1024")
math(EXPR FLASH_PCT   "${FLASH_USED} * 100 / ${FLASH_TOTAL}")
math(EXPR RAM_PCT     "${RAM_USED}  * 100 / ${RAM_TOTAL}")

# ── 格式化输出
message("")
message("  ========================================")
message("  |       Firmware Build Summary        |")
message("  ========================================")
message("")
message("    text    data     bss")
message("    ------  ------  ------")
message("    ${TEXT_SIZE}    ${DATA_SIZE}    ${BSS_SIZE}")
message("")
message("    .bin :  ${BIN_SIZE} bytes")
message("    Flash:  ${FLASH_USED} / ${FLASH_TOTAL}  (${FLASH_PCT}%)")
message("    RAM:    ${RAM_USED} / ${RAM_TOTAL}  (${RAM_PCT}%)")
message("")
