#include "xtp_defines.h"
#include "xtp_gpio.h"
#include <stdbool.h>
int global_num_1 = 0;

/**
 * @brief 定义系统参数变量 
 * 
 */
struct xtp_system_t xtp_system = {
    .global_num_1 = 0,
    .key_count = 0,
    .key_buffer = {
        {
            .buffer = 0xffff,
            .previous_state = false,
            .down_count = 0,
        },
        {
            .buffer = 0xffff,
            .previous_state = false,
            .down_count = 0
        }
    },
    .key_gpiox = {
        {
            .gpiox = OK_KEY_GPIOX,
            .pin = OK_KEY_PIN
        },
        {
            .gpiox = LEFT_KEY_GPIOX,
            .pin = LEFT_KEY_PIN
        }
    }
};
