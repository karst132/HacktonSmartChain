#pragma once

#include "ILed.h"

class Led : public ILed {
private:
    int pin;

public:
    explicit Led(int pin = -1);

    void on() override;
    void off() override;
};