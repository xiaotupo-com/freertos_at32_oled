/**
 * @file xtp_gpio.h
 * @date 2024-1-30
 */

#ifndef __XTP_GPIO_H
#define __XTP_GPIO_H

#include "xtp_defines.h"
#include "xtp_cross_platform.h"

// IO 宏定义 ===================================
#define SYS_LED_GPIOX      GPIOA
#define SYS_LED_PIN        GPIO_PINS_0
#define SYS_LED_CRM_CLOCK  CRM_GPIOA_PERIPH_CLOCK

#define OK_KEY_GPIOX       GPIOB
#define OK_KEY_PIN         GPIO_PINS_5
#define OK_KEY_CRM_CLOCK   CRM_GPIOB_PERIPH_CLOCK

#define LEFT_KEY_GPIOX     GPIOB
#define LEFT_KEY_PIN       GPIO_PINS_6
#define LEFT_KEY_CRM_CLOCK CRM_GPIOB_PERIPH_CLOCK

// 函数声明 ===================================
void xtp_gpio_init(void);

#endif // !__XTP_GPIO_H