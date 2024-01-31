/**
 **************************************************************************
 * @file     main.c
 * @brief    main program
 **************************************************************************
 * 单片机型号：at32f413CCU7
 * 我们要用 GCC 目录下的对应平台中的 port.c 和 portmacro.h
 * Arm Compiler 选择 v6 版本的
 * C 版本选择 C11，暂未发现问题
 * C++ 版本选择 C++11, 暂未发现问题
 * FreeRTOS Kernel V10.5.1
 ***************************************************************************
 * FreeRTOS 任务优先级排序：FreeRTOS的任务优先级是，任务优先级数值越小，任务优先级越低。
 * AT32 中断优先级排序：
 */

#include "at32f413_clock.h"
#include "FreeRTOS.h"
#include "task.h"
#include "xtp_gpio.h"
#include "led.h"
#include "xtp_defines.h"
#include "xtp_create_task.h"

/**
 * @brief  main function.
 * @param  none
 * @retval none
 */
int main(void)
{
    system_clock_config();

    xtp_gpio_init();   // 所有 io 初始化
    xtp_create_task(); // 创建 FreeRTOS 任务
    /* 开启任务调度器 */
    vTaskStartScheduler();

    while (1) {
    }
}

void vApplicationTickHook(void)
{

    for (int i = 0; i < KEY_PCS; i++) {
        xtp_system.key_buffer[i].buffer = (xtp_system.key_buffer[i].buffer << 1) |
                                          (!io_get_level(xtp_system.key_gpiox[i].gpiox, xtp_system.key_gpiox[i].pin));

        if (xtp_system.key_buffer[i].buffer == (uint16_t)0x0000) {
            xtp_system.key_buffer[i].previous_state = true;
        } else if (xtp_system.key_buffer[i].buffer == (uint16_t)0xffff && xtp_system.key_buffer[i].previous_state == true) {
            xtp_system.key_buffer[i].previous_state = false;
            xTaskNotifyGive(xTaskGetHandle("led_task"));
        } else {
            /* 按键抖动发生了 */
        }
    }
}
