#include "led.h"

static void toggle_sys(void);
static void on_sys(void);
static void off_sys(void);

struct Led sys_led = {
    .off    = off_sys,
    .on     = on_sys,
    .toggle = toggle_sys};

/// @brief led FreeRTOS 任务函数
/// @param pvParameters
void led_task(void *pvParameters)
{
    uint32_t num = 0;
    uint32_t ul_notify_value;
    while (1) {
        ul_notify_value = ulTaskNotifyTake(pdTRUE, 0);
        if (ul_notify_value > 0) {
            sys_led.toggle();
        }
    }
}
/// @brief 反转系统指示 led
/// @param  void
void toggle_sys(void)
{
    SYS_LED_GPIOX->odt ^= SYS_LED_PIN;
}
/// @brief 打开系统指示 led
/// 低电平打开，高电平关闭
/// @param void
void on_sys(void)
{
    io_set_level(SYS_LED_GPIOX, SYS_LED_PIN, FALSE);
}

/// @brief 关闭系统指示 led
/// 低电平打开，高电平关闭
/// @param void
void off_sys(void)
{
    io_set_level(SYS_LED_GPIOX, SYS_LED_PIN, TRUE);
}