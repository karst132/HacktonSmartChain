#pragma once

#include "IRgbLed.h"

class CathodeRgbLed : public IRgbLed {
private:
    int redPin;
    int greenPin;
    int bluePin;

public:
    explicit CathodeRgbLed(int redPin, int greenPin, int bluePin);

    void on() override;
    void off() override;
    void set_color(int red, int green, int blue) override;
};
