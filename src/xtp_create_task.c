#include "xtp_create_task.h"

#include "FreeRTOS.h"
#include "task.h"

#define      USER_LED_TASK_PRIO 2           /* 定义任务优先级 */
#define      USER_LED_TASK_STACK_SIZE 120   /* 定义任务堆栈大小 */
TaskHandle_t user_led_handle;               /* 定义任务句柄 */

void xtp_create_task(void)
{
    xTaskCreate(
        (TaskFunction_t)led_task,
        (const char*)"led_task",
        (uint16_t)USER_LED_TASK_STACK_SIZE,
        (void*)NULL,
        (UBaseType_t)USER_LED_TASK_PRIO,
        (TaskHandle_t*)user_led_handle
  );
}