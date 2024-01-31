#include "xtp_cross_platform.h"

#ifdef AT32
xtp_io_set_level_t io_set_level = gpio_bits_write;
xtp_io_get_level_t io_get_level = gpio_input_data_bit_read;
#endif