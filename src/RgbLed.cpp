#include "RgbLed.h"

RgbLed::RgbLed(int redPin, int greenPin, int bluePin) 
    : Led(redPin), greenPin(greenPin), bluePin(bluePin) {
}

void RgbLed::set_color(int red, int green, int blue) {
    // Code to set the RGB LED color
}