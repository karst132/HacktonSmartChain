#pragma once

#include "ILed.h"

class IRgbLed : public ILed {
public:
    virtual ~IRgbLed() = default;
    virtual void set_color(int red, int green, int blue) = 0;
};
