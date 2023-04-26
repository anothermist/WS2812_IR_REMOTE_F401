#ifndef INC_WS2812_H_
#define INC_WS2812_H_

#include "stm32f4xx_hal.h"
#include "main.h"

#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define TIMER_WS2812    htim1
#define TIMER_WS2812_CH TIM_CHANNEL_1

#define DELAY_LEN 48
#define LED_COUNT 30*3
#define ARRAY_LEN DELAY_LEN + LED_COUNT*24
#define L 26
#define H 65

#define BitIsSet(reg, bit) ((reg & (1<<bit)) != 0)

void ws2812_pixel_rgb_to_buf_dma(uint8_t Rpixel , uint8_t Gpixel, uint8_t Bpixel, uint16_t posX);

void ws2812_light(void);

#endif /* INC_WS2812_H_ */
