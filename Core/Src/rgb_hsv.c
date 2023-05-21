#include "rgb_hsv.h"

C_RGB rgb;

C_RGB hsv_to_rgb(double H, double S, double V) {
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

C_HSV hsv;

float max(float a, float b, float c) {
   return ((a > b)? (a > c ? a : c) : (b > c ? b : c));
}

float min(float a, float b, float c) {
   return ((a < b)? (a < c ? a : c) : (b < c ? b : c));
}

C_HSV rgb_to_hsv(float R, float G, float B) {
	R /= 255.0; // R, G, B values are divided by 255 to change the range from 0..255 to 0..1
	G /= 255.0;
	B /= 255.0;
	float cmax = max(R, G, B); // maximum of r, g, b
	float cmin = min(R, G, B); // minimum of r, g, b
	float diff = cmax - cmin; // diff of cmax and cmin.
	if (cmax == cmin)
		hsv.h = 0;
	else if (cmax == R)
		hsv.h = fmod((60 * ((G - B) / diff) + 360), 360.0);
	else if (cmax == G)
		hsv.h = fmod((60 * ((B - R) / diff) + 120), 360.0);
	else if (cmax == B)
		hsv.h = fmod((60 * ((R - G) / diff) + 240), 360.0);

	if (cmax == 0)
		hsv.s = 0;
	else
		hsv.s = (diff / cmax) * 100;

	hsv.v = cmax * 100;

	return hsv;
}
