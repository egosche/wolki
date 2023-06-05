#include <Arduino.h>

void schnee(byte red, byte green, byte blue, int SpeedDelay);
void regen(int r, int g, int b, byte meteorSize, byte meteorTrailDecay, int SpeedDelay);
void bewoelkt(int r, int g, int b, byte meteorSize, byte meteorTrailDecay, int SpeedDelay);
void gewitter(int r, int g, int b, int gewitterDelay, int speedDelay);
void sonnig(int r, int g, int b, byte meteorSize, byte meteorTrailDecay, int SpeedDelay);