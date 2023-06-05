#include "interface.h"

void show_clean() {
	LCD_Rect_Fill(0, 0, LCD_WIDTH, LCD_HEIGHT, BLACK);
	LCD_Rect(0, 0, LCD_WIDTH, LCD_HEIGHT, 1, WHITE);

	LCD_Rect_Round(79, 10, 15, 15, 1, 1, RED);		LCD_Rect_Round(97, 10, 256, 15, 1, 1, RED);		LCD_Rect_Round(356, 10, 15, 15, 1, 1, RED);
	LCD_Rect_Round(79, 35, 15, 15, 1, 1, GREEN);	LCD_Rect_Round(97, 35, 256, 15, 1, 1, GREEN);	LCD_Rect_Round(356, 35, 15, 15, 1, 1, GREEN);
	LCD_Rect_Round(79, 60, 15, 15, 1, 1, BLUE);		LCD_Rect_Round(97, 60, 256, 15, 1, 1, BLUE);	LCD_Rect_Round(356, 60, 15, 15, 1, 1, BLUE);
	LCD_Rect_Round(79, 85, 15, 15, 1, 1, WHITE);	LCD_Rect_Round(97, 85, 361, 15, 1, 1, WHITE);	LCD_Rect_Round(461, 85, 15, 15, 1, 1, WHITE);
	LCD_Rect_Round(79, 110, 15, 15, 1, 1, GRAY);	LCD_Rect_Round(97, 110, 256, 15, 1, 1, GRAY);	LCD_Rect_Round(356, 110, 15, 15, 1, 1, GRAY);
	LCD_Rect_Round(79, 135, 15, 15, 1, 1, YELLOW);	LCD_Rect_Round(97, 135, 256, 15, 1, 1, YELLOW);	LCD_Rect_Round(356, 135, 15, 15, 1, 1, YELLOW);
	LCD_Rect_Round(79, 160, 15, 15, 1, 1, CYAN);	LCD_Rect_Round(97, 160, 256, 15, 1, 1, CYAN);	LCD_Rect_Round(356, 160, 15, 15, 1, 1, CYAN);
}
