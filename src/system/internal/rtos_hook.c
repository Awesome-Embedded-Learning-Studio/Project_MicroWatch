#include "FreeRTOS.h"
#include "task.h"

void vApplicationMallocFailedHook(void) {
    taskDISABLE_INTERRUPTS();
    for (;;)
        ;
}

/** configCHECK_FOR_STACK_OVERFLOW = 2 */
void vApplicationStackOverflowHook(TaskHandle_t xTask, char* pcTaskName) {
    (void)xTask;
    (void)pcTaskName;
    taskDISABLE_INTERRUPTS();
    for (;;)
        ;
}

void vApplicationIdleHook(void) {
    // Entering hooks
}