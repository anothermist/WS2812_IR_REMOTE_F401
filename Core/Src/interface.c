#include "interface.h"

void show_clean() {
	LCD_Rect_Fill(0, 0, LCD_WIDTH, LCD_HEIGHT, BLACK);
	LCD_Rect(0, 0, LCD_WIDTH, LCD_HEIGHT, 1, WHITE);

	LCD_Rect_Round(79, 10, 15, 15, 0, 1, RED);		LCD_Rect(97, 10, 256, 15, 1, RED);		LCD_Rect_Round(356, 10, 15, 15, 1, 1, RED);
	LCD_Rect_Round(79, 35, 15, 15, 1, 1, GREEN);	LCD_Rect(97, 35, 256, 15, 1, GREEN);	LCD_Rect_Round(356, 35, 15, 15, 1, 1, GREEN);
	LCD_Rect_Round(79, 60, 15, 15, 1, 1, BLUE);		LCD_Rect(97, 60, 256, 15, 1, BLUE);	LCD_Rect_Round(356, 60, 15, 15, 1, 1, BLUE);
	LCD_Rect_Round(79, 85, 15, 15, 1, 1, WHITE);	LCD_Rect(97, 85, 361, 15, 1, WHITE);	LCD_Rect_Round(461, 85, 15, 15, 1, 1, WHITE);
	LCD_Rect_Round(79, 110, 15, 15, 1, 1, GRAY);	LCD_Rect(97, 110, 256, 15, 1, GRAY);	LCD_Rect_Round(356, 110, 15, 15, 1, 1, GRAY);
	LCD_Rect_Round(79, 135, 15, 15, 1, 1, YELLOW);	LCD_Rect(97, 135, 256, 15, 1, YELLOW);	LCD_Rect_Round(356, 135, 15, 15, 1, 1, YELLOW);
	LCD_Rect_Round(79, 160, 15, 15, 1, 1, CYAN);	LCD_Rect(97, 160, 256, 15, 1, CYAN);	LCD_Rect_Round(356, 160, 15, 15, 1, 1, CYAN);
}

void drawR (uint8_t x) {
	for (uint8_t i = 0; i < x; i++) LCD_Line(98 + i, 11, 98 + i, 24, 1, RED);
	for (uint8_t i = 0; i < 255 - x; i++) LCD_Line(97 + (255 - i), 11, 97 + (255 - i), 24, 1, BLACK);
}

void drawG (uint8_t x) {
	for (uint8_t i = 0; i < x; i++) LCD_Line(98 + i, 36, 98 + i, 49, 1, GREEN);
	for (uint8_t i = 0; i < 255 - x; i++) LCD_Line(97 + (255 - i), 36, 97 + (255 - i), 49, 1, BLACK);
}

void drawB (uint8_t x) {
	for (uint8_t i = 0; i < x; i++) LCD_Line(98 + i, 61, 98 + i, 74, 1, BLUE);
	for (uint8_t i = 0; i < 255 - x; i++) LCD_Line(97 + (255 - i), 61, 97 + (255 - i), 74, 1, BLACK);
}

void drawH (uint16_t x) {
	for (uint16_t i = 0; i < x; i++) LCD_Line(98 + i, 86, 98 + i, 99, 1, WHITE);
	for (uint8_t i = 0; i < 360 - x; i++) LCD_Line(97 + (360 - i), 86, 97 + (360 - i), 99, 1, BLACK);
}

void drawS (uint8_t x) {
	for (uint8_t i = 0; i < x; i++) LCD_Line(98 + i, 111, 98 + i, 124, 1, GRAY);
	for (uint8_t i = 0; i < 255 - x; i++) LCD_Line(97 + (255 - i), 111, 97 + (255 - i), 124, 1, BLACK);
}

void drawV (uint8_t x) {
	for (uint8_t i = 0; i < x; i++) LCD_Line(98 + i, 136, 98 + i, 149, 1, YELLOW);
	for (uint8_t i = 0; i < 255 - x; i++) LCD_Line(97 + (255 - i), 136, 97 + (255 - i), 149, 1, BLACK);
}

void drawD (uint8_t x) {
	for (uint8_t i = 0; i < x; i++) LCD_Line(98 + i, 161, 98 + i, 174, 1, CYAN);
	for (uint8_t i = 0; i < 255 - x; i++) LCD_Line(97 + (255 - i), 161, 97 + (255 - i), 174, 1, BLACK);
}
