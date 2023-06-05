#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "Strip.h"

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void showStrip()
{
  strip.show();
}

void clearStrip()
{
  strip.clear();
}

// Colors blue and green were exchanged due to construction type
void setPixel(int pixel, int red, int green, int blue)
{
  strip.setPixelColor(pixel, strip.Color(red, blue, green));
}

void setAll(int red, int green, int blue)
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    setPixel(i, red, green, blue);
  }
}

void fadeToBlack(int ledNo, byte fadeValue)
{
  uint32_t oldColor;
  uint8_t r, g, b;
  int value;

  oldColor = strip.getPixelColor(ledNo);
  r = (oldColor & 0x00ff0000UL) >> 16;
  b = (oldColor & 0x0000ff00UL) >> 8;
  g = (oldColor & 0x000000ffUL);

  r = (r <= 10) ? 0 : (int)r - (r * fadeValue / 256);
  g = (g <= 10) ? 0 : (int)g - (g * fadeValue / 256);
  b = (b <= 10) ? 0 : (int)b - (b * fadeValue / 256);

  strip.setPixelColor(ledNo, r, b, g);
}