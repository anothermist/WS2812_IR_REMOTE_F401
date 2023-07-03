#ifndef INC_INTERFACE_H_
#define INC_INTERFACE_H_


#include "main.h"
#include "ili9488.h"
#include "rgb_hsv.h"

void show_clean();

void drawR (uint8_t x);
void drawG (uint8_t x);
void drawB (uint8_t x);
void drawH (uint16_t x);
void drawS (uint8_t x);
void drawV (uint8_t x);
void drawD (uint8_t x);


#endif /* INC_INTERFACE_H_ */
