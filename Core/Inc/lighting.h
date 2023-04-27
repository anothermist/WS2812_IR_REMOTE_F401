#ifndef LIGHTING_H_
#define LIGHTING_H_

#include "main.h"
#include <math.h>
#include "ws2812.h"

void remake_palette(double brightness, double saturation);
void rainbow(uint8_t reverse, uint16_t chain, uint16_t segment);

#endif /* LIGHTING_H_ */
