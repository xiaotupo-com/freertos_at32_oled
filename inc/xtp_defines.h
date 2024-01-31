#ifndef __XTP_DEFINES_H
#define __XTP_DEFINES_H

#include "at32f413.h"
#include <stdbool.h>

#define USE_FREERTOS (1) // 1:使用 FreeRTOS 0:不使用 FreeRTOS
#define AT32

#define KEY_PCS 2 // 按键个数

struct key_buffer_t {
    uint16_t buffer;     // 按键 buff
    bool previous_state; // 以前的状态
    uint32_t down_count; // 按下计数（ms）
};

struct key_gpiox_t {
    gpio_type *gpiox;
    uint16_t pin;
};

struct xtp_system_t {
    int32_t global_num_1;
    int32_t key_count;
    struct key_buffer_t key_buffer[KEY_PCS];
    struct key_gpiox_t key_gpiox[KEY_PCS];
};

extern struct xtp_system_t xtp_system;

#endif /* __XTP_DEFINES_H */
