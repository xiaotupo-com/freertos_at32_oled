#ifndef __LED_H
#define __LED_H

#include "FreeRTOS.h"
#include "task.h"
#include "at32f413.h"

#include "xtp_gpio.h"


struct Led
{
    void (*toggle)(void);
    void (*on)(void);
    void (*off)(void);
};

#endif