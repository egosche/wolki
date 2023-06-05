#include "Strip.h"

// Set all LEDs of section 1 to the given color
void setSek_1(int r, int g, int b)
{
  setPixel(29, r, g, b);
  setPixel(38, r, g, b);
  setPixel(97, r, g, b);
}

// Set all LEDs of section 2 to the given color
void setSek_2(int r, int g, int b)
{
  setPixel(90, r, g, b);
  setPixel(93, r, g, b);
  setPixel(94, r, g, b);
}

// Set all LEDs of section 3 to the given color
void setSek_3(int r, int g, int b)
{
  setPixel(0, r, g, b);
  setPixel(1, r, g, b);
  setPixel(9, r, g, b);
  setPixel(56, r, g, b);
  setPixel(81, r, g, b);
  setPixel(87, r, g, b);
  setPixel(89, r, g, b);
}

// Set all LEDs of section 4 to the given color
void setSek_4(int r, int g, int b)
{
  setPixel(66, r, g, b);
  setPixel(67, r, g, b);
  setPixel(68, r, g, b);
}

// Set all LEDs of section 5 to the given color
void setSek_5(int r, int g, int b)
{
  setPixel(23, r, g, b);
  setPixel(24, r, g, b);
  setPixel(25, r, g, b);
  setPixel(26, r, g, b);
  setPixel(27, r, g, b);
  setPixel(28, r, g, b);
  setPixel(33, r, g, b);
  setPixel(34, r, g, b);
  setPixel(35, r, g, b);
  setPixel(36, r, g, b);
  setPixel(37, r, g, b);
  setPixel(39, r, g, b);
}

// Set all LEDs of section 6 to the given color
void setSek_6(int r, int g, int b)
{
  setPixel(11, r, g, b);
  setPixel(12, r, g, b);
  setPixel(13, r, g, b);
  setPixel(16, r, g, b);
  setPixel(31, r, g, b);
  setPixel(32, r, g, b);
  setPixel(92, r, g, b);
}

// Set all LEDs of section 7 to the given color
void setSek_7(int r, int g, int b)
{
  setPixel(48, r, g, b);
  setPixel(49, r, g, b);
  setPixel(50, r, g, b);
  setPixel(52, r, g, b);
  setPixel(53, r, g, b);
  setPixel(54, r, g, b);
}

// Set all LEDs of section 8 to the given color
void setSek_8(int r, int g, int b)
{
  setPixel(61, r, g, b);
  setPixel(62, r, g, b);
  setPixel(63, r, g, b);
  setPixel(64, r, g, b);
  setPixel(65, r, g, b);
}

// Set all LEDs of section mid to the given color
void setSek_Mitte(int r, int g, int b)
{
  setPixel(2, r, g, b);
  setPixel(3, r, g, b);
  setPixel(6, r, g, b);
  setPixel(10, r, g, b);
  setPixel(20, r, g, b);
  setPixel(21, r, g, b);
  setPixel(22, r, g, b);
  setPixel(30, r, g, b);
  setPixel(45, r, g, b);
  setPixel(46, r, g, b);
  setPixel(47, r, g, b);
  setPixel(55, r, g, b);
  setPixel(69, r, g, b);
  setPixel(70, r, g, b);
  setPixel(75, r, g, b);
  setPixel(76, r, g, b);
  setPixel(77, r, g, b);
  setPixel(78, r, g, b);
  setPixel(79, r, g, b);
  setPixel(80, r, g, b);
  setPixel(84, r, g, b);
  setPixel(85, r, g, b);
  setPixel(86, r, g, b);
  setPixel(88, r, g, b);
  setPixel(91, r, g, b);
  setPixel(95, r, g, b);
  setPixel(96, r, g, b);
  setPixel(98, r, g, b);
  setPixel(99, r, g, b);
}

// Set all LEDs of section mid bot to the given color
void setSek_Mitte_Unten(int r, int g, int b)
{
  setPixel(4, r, g, b);
  setPixel(5, r, g, b);
  setPixel(51, r, g, b);
}

// Set all LEDs of section mid top to the given color
void setSek_Mitte_Oben(int r, int g, int b)
{
  setPixel(7, r, g, b);
  setPixel(8, r, g, b);
}

// Set all LEDs of section bot to the given color
void setSek_Unten(int r, int g, int b)
{
  setPixel(14, r, g, b);
  setPixel(17, r, g, b);
  setPixel(18, r, g, b);
  setPixel(19, r, g, b);
  setPixel(42, r, g, b);
  setPixel(43, r, g, b);
  setPixel(44, r, g, b);
  setPixel(57, r, g, b);
  setPixel(82, r, g, b);
  setPixel(83, r, g, b);
}

// Set all LEDs of section bot front to the given color
void setSek_Unten_Vorne(int r, int g, int b)
{
  setPixel(15, r, g, b);
  setPixel(40, r, g, b);
  setPixel(41, r, g, b);
}

// Set all LEDs of section bot back to the given color
void setSek_Unten_Hinten(int r, int g, int b)
{
  setPixel(58, r, g, b);
  setPixel(59, r, g, b);
  setPixel(60, r, g, b);
  setPixel(71, r, g, b);
  setPixel(72, r, g, b);
  setPixel(73, r, g, b);
  setPixel(74, r, g, b);
}
