#pragma once

#include "ILed.h"

class Led : public ILed {
private:
    int pin;

public:
    explicit Led(int pin);

    void on() override;
    void off() override;
};