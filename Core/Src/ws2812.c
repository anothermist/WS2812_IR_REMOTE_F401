#include "ws2812.h"

extern TIM_HandleTypeDef TIM_LED;

uint16_t BUF_DMA[ARRAY_LEN] = { 0 };
uint8_t rgb_t[15][3];
uint16_t DMA_BUF_TEMP[24];

//void led_init(void) {
//	uint16_t i;
//	for (i = DELAY_LEN; i < ARRAY_LEN; i++) BUF_DMA[i] = LO;
//}

void led_rgb_to_buf_dma(uint8_t pixR, uint8_t pixG, uint8_t pixB, uint16_t posX) {
	volatile uint16_t i;
	for (i = 0; i < 8; i++) {
		if (BitIsSet(pixR,(7-i)) == 1) BUF_DMA[DELAY_LEN + posX * 24 + i + 8] = HI;
		else BUF_DMA[DELAY_LEN + posX * 24 + i + 8] = LO;

		if (BitIsSet(pixG,(7-i)) == 1) BUF_DMA[DELAY_LEN + posX * 24 + i + 0] = HI;
		else BUF_DMA[DELAY_LEN + posX * 24 + i + 0] = LO;

		if (BitIsSet(pixB,(7-i)) == 1) BUF_DMA[DELAY_LEN + posX * 24 + i + 16] = HI;
		else BUF_DMA[DELAY_LEN + posX * 24 + i + 16] = LO;
	}
}

void led_prepareValue(uint8_t r00, uint8_t g00, uint8_t b00, uint8_t r01,
		uint8_t g01, uint8_t b01, uint8_t r02, uint8_t g02, uint8_t b02,
		uint8_t r03, uint8_t g03, uint8_t b03, uint8_t r04, uint8_t g04,
		uint8_t b04, uint8_t r05, uint8_t g05, uint8_t b05, uint8_t r06,
		uint8_t g06, uint8_t b06, uint8_t r07, uint8_t g07, uint8_t b07,
		uint8_t r08, uint8_t g08, uint8_t b08, uint8_t r09, uint8_t g09,
		uint8_t b09, uint8_t r10, uint8_t g10, uint8_t b10, uint8_t r11,
		uint8_t g11, uint8_t b11, uint8_t r12, uint8_t g12, uint8_t b12,
		uint8_t r13, uint8_t g13, uint8_t b13, uint8_t r14, uint8_t g14,
		uint8_t b14) {
	rgb_t[0][0] = r00;
	rgb_t[0][1] = g00;
	rgb_t[0][2] = b00;
	rgb_t[1][0] = r01;
	rgb_t[1][1] = g01;
	rgb_t[1][2] = b01;
	rgb_t[2][0] = r02;
	rgb_t[2][1] = g02;
	rgb_t[2][2] = b02;
	rgb_t[3][0] = r03;
	rgb_t[3][1] = g03;
	rgb_t[3][2] = b03;
	rgb_t[4][0] = r04;
	rgb_t[4][1] = g04;
	rgb_t[4][2] = b04;
	rgb_t[5][0] = r05;
	rgb_t[5][1] = g05;
	rgb_t[5][2] = b05;
	rgb_t[6][0] = r06;
	rgb_t[6][1] = g06;
	rgb_t[6][2] = b06;
	rgb_t[7][0] = r07;
	rgb_t[7][1] = g07;
	rgb_t[7][2] = b07;
	rgb_t[8][0] = r08;
	rgb_t[8][1] = g08;
	rgb_t[8][2] = b08;
	rgb_t[9][0] = r09;
	rgb_t[9][1] = g09;
	rgb_t[9][2] = b09;
	rgb_t[10][0] = r10;
	rgb_t[10][1] = g10;
	rgb_t[10][2] = b10;
	rgb_t[11][0] = r11;
	rgb_t[11][1] = g11;
	rgb_t[11][2] = b11;
	rgb_t[12][0] = r12;
	rgb_t[12][1] = g12;
	rgb_t[12][2] = b12;
	rgb_t[13][0] = r13;
	rgb_t[13][1] = g13;
	rgb_t[13][2] = b13;
	rgb_t[14][0] = r14;
	rgb_t[14][1] = g14;
	rgb_t[14][2] = b14;
}

void led_setValue(void) {
	uint8_t n = 0;
	for (n = 0; n < 20; n++) {
		led_rgb_to_buf_dma(rgb_t[0][0], rgb_t[0][1],   rgb_t[0][2],  n * 15);
		led_rgb_to_buf_dma(rgb_t[1][0], rgb_t[1][1],   rgb_t[1][2],  n * 15 + 1);
		led_rgb_to_buf_dma(rgb_t[2][0], rgb_t[2][1],   rgb_t[2][2],  n * 15 + 2);
		led_rgb_to_buf_dma(rgb_t[3][0], rgb_t[3][1],   rgb_t[3][2],  n * 15 + 3);
		led_rgb_to_buf_dma(rgb_t[4][0], rgb_t[4][1],   rgb_t[4][2],  n * 15 + 4);
		led_rgb_to_buf_dma(rgb_t[5][0], rgb_t[5][1],   rgb_t[5][2],  n * 15 + 5);
		led_rgb_to_buf_dma(rgb_t[6][0], rgb_t[6][1],   rgb_t[6][2],  n * 15 + 6);
		led_rgb_to_buf_dma(rgb_t[7][0], rgb_t[7][1],   rgb_t[7][2],  n * 15 + 7);
		led_rgb_to_buf_dma(rgb_t[8][0], rgb_t[8][1],   rgb_t[8][2],  n * 15 + 8);
		led_rgb_to_buf_dma(rgb_t[9][0], rgb_t[9][1],   rgb_t[9][2],  n * 15 + 9);
		led_rgb_to_buf_dma(rgb_t[10][0], rgb_t[10][1], rgb_t[10][2], n * 15 + 10);
		led_rgb_to_buf_dma(rgb_t[11][0], rgb_t[11][1], rgb_t[11][2], n * 15 + 11);
		led_rgb_to_buf_dma(rgb_t[12][0], rgb_t[12][1], rgb_t[12][2], n * 15 + 12);
		led_rgb_to_buf_dma(rgb_t[13][0], rgb_t[13][1], rgb_t[13][2], n * 15 + 13);
		led_rgb_to_buf_dma(rgb_t[14][0], rgb_t[14][1], rgb_t[14][2], n * 15 + 14);
	}
}

void led_light(void) {
	HAL_TIM_PWM_Start_DMA(&TIM_LED, TIM_LED_CH, (uint32_t*) &BUF_DMA, ARRAY_LEN);
}
