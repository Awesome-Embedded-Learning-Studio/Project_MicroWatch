#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/* 让 FreeRTOS 读取实际系统时钟，必须在时钟配置后才准确 */
#include "stm32g4xx_hal.h"

/* ── 调度器基础 ─────────────────────────────────────────────────── */
#define configUSE_PREEMPTION 1
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 0
#define configUSE_TICKLESS_IDLE 0
#define configCPU_CLOCK_HZ (SystemCoreClock)
#define configTICK_RATE_HZ (1000)
#define configMAX_PRIORITIES (7)
#define configMINIMAL_STACK_SIZE (128)
#define configMAX_TASK_NAME_LEN (16)
#define configUSE_16_BIT_TICKS 0
#define configIDLE_SHOULD_YIELD 1
#define configUSE_TASK_NOTIFICATIONS 1
#define configTASK_NOTIFICATION_ARRAY_ENTRIES 3
#define configUSE_MUTEXES 1
#define configUSE_RECURSIVE_MUTEXES 1
#define configUSE_COUNTING_SEMAPHORES 1
#define configQUEUE_REGISTRY_SIZE 8
#define configUSE_QUEUE_SETS 0
#define configUSE_TIME_SLICING 1

/* ── 内存 ───────────────────────────────────────────────────────── */
/* STM32G431 共 32KB SRAM，按需调整 */
#define configTOTAL_HEAP_SIZE ((size_t)(6 * 1024))
#define configSUPPORT_DYNAMIC_ALLOCATION 1
#define configSUPPORT_STATIC_ALLOCATION 0

/* ── Hook 函数 ──────────────────────────────────────────────────── */
#define configUSE_IDLE_HOOK 0
#define configUSE_TICK_HOOK 0
#define configCHECK_FOR_STACK_OVERFLOW 2 /* 方法2：更严格的检查 */
#define configUSE_MALLOC_FAILED_HOOK 1

/* ── 软件定时器 ─────────────────────────────────────────────────── */
#define configUSE_TIMERS 1
#define configTIMER_TASK_PRIORITY (2)
#define configTIMER_QUEUE_LENGTH 10
#define configTIMER_TASK_STACK_DEPTH (configMINIMAL_STACK_SIZE * 2)

/* ── 运行时统计（可选，开启需提供计时器）────────────────────────── */
#define configGENERATE_RUN_TIME_STATS 0
#define configUSE_TRACE_FACILITY 0
#define configUSE_STATS_FORMATTING_FUNCTIONS 0

/* ── Cortex-M4 中断优先级（关键，不能随意改）────────────────────── */
/* STM32G4 使用 4-bit 优先级（0-15），数值越小优先级越高            */
/* FreeRTOS 的 SVC/PendSV/SysTick 必须使用最低优先级（15）          */
/* fromISR 系列 API 只能在优先级 >= 5 的 ISR 中调用                 */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY 15
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY 5
#define configKERNEL_INTERRUPT_PRIORITY                                        \
  (configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - 4))
#define configMAX_SYSCALL_INTERRUPT_PRIORITY                                   \
  (configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - 4))

/* ── INCLUDE 宏（用到哪个功能就开哪个）──────────────────────────── */
#define INCLUDE_vTaskPrioritySet 1
#define INCLUDE_uxTaskPriorityGet 1
#define INCLUDE_vTaskDelete 1
#define INCLUDE_vTaskSuspend 1
#define INCLUDE_xResumeFromISR 1
#define INCLUDE_vTaskDelayUntil 1
#define INCLUDE_vTaskDelay 1
#define INCLUDE_xTaskGetSchedulerState 1
#define INCLUDE_xTaskGetCurrentTaskHandle 1
#define INCLUDE_uxTaskGetStackHighWaterMark 1

/* ── 中断向量映射：FreeRTOS port.c → 启动文件 weak 符号 ──────────── */
#define vPortSVCHandler        SVC_Handler
#define xPortPendSVHandler     PendSV_Handler
#define xPortSysTickHandler    SysTick_Handler

#endif /* FREERTOS_CONFIG_H */