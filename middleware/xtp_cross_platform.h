#ifndef __XTP_CROSS_PLATFORM_H
#define __XTP_CROSS_PLATFORM_H

#include "xtp_defines.h"

#ifdef AT32
#include "at32f413.h"

#define io_status flag_status

typedef void (*xtp_io_set_level_t)(gpio_type *, uint16_t, confirm_state);
extern xtp_io_set_level_t io_set_level;

typedef io_status (*xtp_io_get_level_t)(gpio_type *, uint16_t);
extern xtp_io_get_level_t io_get_level;

#endif // !AT32

#endif // !__XTP_CROSS_PLATFORM_H