#pragma once

#include "ILed.h"

class IRgbLed : public ILed {
public:
    virtual void set_color(int red, int green, int blue) = 0;
};
