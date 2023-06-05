#include <Arduino.h>

#define NUM_LEDS 100
#define LED_PIN 17

void showStrip();
void clearStrip();
void setPixel(int pixel, int red, int green, int blue);
void setAll(int red, int green, int blue);
void fadeToBlack(int ledNo, byte fadeValue);