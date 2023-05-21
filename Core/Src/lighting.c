#include "lighting.h"

long long lastTick;

uint8_t palette[3][360];

void remake_palette(double brightness, double saturation) {
	for (uint16_t i = 0; i < 360; i++) {
		rgb = hsv_to_rgb(i, saturation, brightness);
		palette[0][i] = rgb.r;
		palette[1][i] = rgb.g;
		palette[2][i] = rgb.b;
	}
}

uint16_t offset = 0;

void rainbow(uint8_t reverse, uint16_t chain, uint16_t segment) {

	if (reverse) {
		for (uint16_t i = 0; i < chain; i++) {
			uint16_t paletteIndex = ((360 / segment)
					* ((i + offset - 1) % segment));
			led_rgb_to_buf_dma(palette[0][paletteIndex],
					palette[1][paletteIndex], palette[2][paletteIndex], i);
		}
		led_light();
		offset--;
		if (offset == 0)
			offset = segment;
	} else {
		for (uint16_t i = 0; i < chain; i++) {
			uint16_t paletteIndex = 359
					- ((360 / segment) * ((i + offset) % segment));
			led_rgb_to_buf_dma(palette[0][paletteIndex],
					palette[1][paletteIndex], palette[2][paletteIndex], i);
		}
		led_light();
		offset++;
		if (offset == segment)
			offset = 0;
	}
}
