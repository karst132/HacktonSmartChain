#pragma once

#include "Led.h"

class RgbLed : public Led {
private:
    int greenPin;
    int bluePin;

public:
    explicit RgbLed(int redPin = -1, int greenPin = -1, int bluePin = -1);
    ~RgbLed() override = default;

    void set_color(int red, int green, int blue);
};