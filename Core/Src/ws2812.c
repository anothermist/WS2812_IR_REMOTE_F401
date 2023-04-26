#include "ws2812.h"

extern TIM_HandleTypeDef TIMER_WS2812;

uint16_t BUF_DMA[ARRAY_LEN] = { 0 };

void ws2812_pixel_rgb_to_buf_dma(uint8_t Rpixel, uint8_t Gpixel, uint8_t Bpixel, uint16_t posX) {
	volatile uint16_t i;
	for (i = 0; i < 8; i++) {
		if (BitIsSet(Rpixel,(7 - i)) == 1)
			BUF_DMA[DELAY_LEN + posX * 24 + i + 8] = H;
		else
			BUF_DMA[DELAY_LEN + posX * 24 + i + 8] = L;

		if (BitIsSet(Gpixel,(7 - i)) == 1)
			BUF_DMA[DELAY_LEN + posX * 24 + i + 0] = H;
		else
			BUF_DMA[DELAY_LEN + posX * 24 + i + 0] = L;

		if (BitIsSet(Bpixel,(7 - i)) == 1)
			BUF_DMA[DELAY_LEN + posX * 24 + i + 16] = H;
		else
			BUF_DMA[DELAY_LEN + posX * 24 + i + 16] = L;
	}
}

void ws2812_light(void) {
	HAL_TIM_PWM_Start_DMA(&TIMER_WS2812, TIMER_WS2812_CH, (uint32_t*) &BUF_DMA, ARRAY_LEN *2);
}

