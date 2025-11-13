#pragma once

#include "IRgbLed.h"

class RgbLed : public IRgbLed {
private:
    int redPin;
    int greenPin;
    int bluePin;

public:
    explicit RgbLed(int redPin = -1, int greenPin = -1, int bluePin = -1);
    ~RgbLed() override = default;

    void on() override;
    void off() override;
    void set_color(int red, int green, int blue) override;
};