#ifndef __XTP_CREATE_TASK_H
#define __XTP_CREATE_TASK_H

void         led_task(void* pvParameters);  /* 任务函数 */

void xtp_create_task(void);

#endif // !__XTP_CREATE_TASK_H