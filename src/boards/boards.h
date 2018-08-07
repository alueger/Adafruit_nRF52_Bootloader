/* Copyright (c) 2014 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */
#ifndef BOARDS_H
#define BOARDS_H

#include <stdbool.h>
#include <stdint.h>
#include "nrf_gpio.h"

#if defined BOARD_FEATHER52840
  #include "boards/feather52840.h"
#elif defined BOARD_PCA10056
  #include "boards/pca10056.h"
#elif defined BOARD_FEATHER52832
  #include "boards/feather52832.h"
#else
  #error No boards defined
#endif

// Make sure we have at least two buttons (DFU + FRESET since DFU+FRST=OTA)
#if BUTTONS_NUMBER < 2
#error "At least two buttons required in the BSP (see 'BUTTONS_NUMBER')"
#endif

#define LED_RED     LED_1
#define LED_BLUE    LED_2

#define bit(b) (1UL << (b))

static inline void led_control(uint32_t pin, bool state)
{
  nrf_gpio_pin_write(pin, state ? LED_STATE_ON : (1-LED_STATE_ON));
}

static inline void led_on(uint32_t pin)
{
  led_control(pin, true);
}

static inline void led_off(uint32_t pin)
{
  led_control(pin, false);
}

#endif