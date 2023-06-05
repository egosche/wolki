#include <Arduino.h>
#include "Strip.h"
#include "Sektionen.h"

// Light effect for snow
void snow(byte red, byte green, byte blue, int SpeedDelay)
{
  setAll(104, 140, 136);
  int Pixel = random(NUM_LEDS);
  setPixel(Pixel, red, green, blue);
  showStrip();
  delay(SpeedDelay);
  setAll(104, 140, 136);
}

// Light effect for rain
void rain(int r, int g, int b, byte meteorSize, byte meteorTrailDecay,
          int SpeedDelay)
{
  setAll(30, 55, 153);
  showStrip();

  for (int i = random(NUM_LEDS); i < NUM_LEDS + NUM_LEDS; i++)
  {
    // fade brightness all LEDs one step
    for (int j = 0; j < NUM_LEDS; j++)
    {
      setPixel(j, 30, 55, 153);
    }

    // draw meteor
    for (int j = 0; j < meteorSize; j++)
    {
      if ((i - j < NUM_LEDS) && (i - j >= 0))
      {
        setPixel(i - j, r, g, b);
        delay(5);
      }
    }

    showStrip();
    delay(SpeedDelay);
  }
}

// Light effect for cloudy
void cloudy(int r, int g, int b, byte meteorSize, byte meteorTrailDecay,
            int SpeedDelay)
{
  setAll(140, 140, 140);
  showStrip();

  for (int i = random(NUM_LEDS); i < NUM_LEDS + NUM_LEDS; i++)
  {
    // fade brightness all LEDs one step
    for (int j = 0; j < NUM_LEDS; j++)
    {
      setPixel(j, 140, 140, 140);
    }

    // draw meteor
    for (int j = 0; j < meteorSize; j++)
    {
      if ((i - j < NUM_LEDS) && (i - j >= 0))
      {
        setPixel(i - j, r, g, b);
        delay(5);
      }
    }

    showStrip();
    delay(SpeedDelay);
  }
}

// Light effect for thunderstorm
void thunderstorm(int r, int g, int b, int gewitterDelay, int speedDelay)
{
  setAll(r, g, b);

  int zufall = random(14);

  switch (zufall)
  {
  case 0:
    setSek_1(255, 255, 255);
    break;
  case 1:
    setSek_2(255, 255, 255);
    break;
  case 2:
    setSek_3(255, 255, 255);
    break;
  case 3:
    setSek_4(255, 255, 255);
    break;
  case 4:
    setSek_5(255, 255, 255);
    break;
  case 5:
    setSek_6(255, 255, 255);
    break;
  case 6:
    setSek_7(255, 255, 255);
    break;
  case 7:
    setSek_8(255, 255, 255);
    break;
  case 8:
    setSek_Mitte_Unten(255, 255, 255);
    break;
  case 9:
    setSek_Mitte_Oben(255, 255, 255);
    break;
  case 10:
    setSek_Unten(255, 255, 255);
    break;
  case 11:
    setSek_Unten_Vorne(255, 255, 255);
    break;
  case 12:
    setSek_Unten_Hinten(255, 255, 255);
    break;
  default:
    setSek_Mitte(255, 255, 255);
    break;
  }
  showStrip();
  delay(gewitterDelay);
  setAll(r, g, b);
  showStrip();
  delay(speedDelay);
}

// Light effect for sunny weather
void sunny(int r, int g, int b, byte meteorSize, byte meteorTrailDecay,
           int SpeedDelay)
{
  setAll(254, 198, 6);
  showStrip();

  for (int i = random(NUM_LEDS); i < NUM_LEDS + NUM_LEDS; i++)
  {
    // fade brightness all LEDs one step
    for (int j = 0; j < NUM_LEDS; j++)
    {
      setPixel(j, 254, 198, 6);
    }

    // draw meteor
    for (int j = 0; j < meteorSize; j++)
    {
      if ((i - j < NUM_LEDS) && (i - j >= 0))
      {
        setPixel(i - j, r, g, b);
        delay(5);
      }
    }

    showStrip();
    delay(SpeedDelay);
  }
}