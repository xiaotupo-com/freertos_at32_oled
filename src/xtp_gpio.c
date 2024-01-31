#include "xtp_gpio.h"

void xtp_gpio_init(void)
{
    /* 定义 GPIO 初始化结构体 */
    gpio_init_type gpio_init_struct;

    /* 使能 GPIOA 外设时钟 */
    crm_periph_clock_enable(SYS_LED_CRM_CLOCK, TRUE);
    crm_periph_clock_enable(OK_KEY_CRM_CLOCK, TRUE);

    /* 设置默认参数 */
    gpio_default_para_init(&gpio_init_struct);

                                                                          /* 配置 GPIO 参数 */
    gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;  /* 较大电流推动/吸入能力 */
    gpio_init_struct.gpio_out_type       = GPIO_OUTPUT_PUSH_PULL;         /* 推挽输出 */
    gpio_init_struct.gpio_mode           = GPIO_MODE_OUTPUT;
    gpio_init_struct.gpio_pins           = SYS_LED_PIN;
    gpio_init_struct.gpio_pull           = GPIO_PULL_NONE;
    gpio_init(SYS_LED_GPIOX, &gpio_init_struct);

    // OK 键 io 配置
    gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
    gpio_init_struct.gpio_pins = OK_KEY_PIN | LEFT_KEY_PIN;
    gpio_init_struct.gpio_pull = GPIO_PULL_UP;
    gpio_init(OK_KEY_GPIOX, &gpio_init_struct);
}