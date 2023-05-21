#ifndef INC_RGB_HSV_H_
#define INC_RGB_HSV_H_

#include "main.h"
#include <math.h>

typedef struct C_RGB {
	uint8_t r;
	uint8_t g;
	uint8_t b;
} C_RGB;

extern C_RGB rgb;

C_RGB hsv_to_rgb(double H, double S, double V);

typedef struct C_HSV {
	float h;
	float s;
	float v;
} C_HSV;

extern C_HSV hsv;

C_HSV rgb_to_hsv(float R, float G, float B);


#endif /* INC_RGB_HSV_H_ */
