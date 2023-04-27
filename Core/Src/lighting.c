#include "lighting.h"

long long lastTick;

typedef struct RGB {
	uint8_t r;
	uint8_t g;
	uint8_t b;
} RGB;

RGB rgb;

RGB hsv_rgb(double H, double S, double V) {
	double r = 0, g = 0, b = 0;

	if (S == 0) {
		r = V;
		g = V;
		b = V;
	} else {
		uint16_t i;
		double f, p, q, t;

		if (H == 360)
			H = 0;
		else
			H = H / 60;

		i = (uint16_t) trunc(H);
		f = H - i;

		p = V * (1.0 - S);
		q = V * (1.0 - (S * f));
		t = V * (1.0 - (S * (1.0 - f)));

		switch (i) {
		case 0:
			r = V;
			g = t;
			b = p;
			break;
		case 1:
			r = q;
			g = V;
			b = p;
			break;
		case 2:
			r = p;
			g = V;
			b = t;
			break;
		case 3:
			r = p;
			g = q;
			b = V;
			break;
		case 4:
			r = t;
			g = p;
			b = V;
			break;
		default:
			r = V;
			g = p;
			b = q;
			break;
		}

	}
	rgb.r = r * 255;
	rgb.g = g * 255;
	rgb.b = b * 255;
	return rgb;
}

uint8_t palette[3][360];

void remake_palette(double brightness, double saturation) {
	for (uint16_t i = 0; i < 360; i++) {
		rgb = hsv_rgb(i, saturation, brightness);
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
