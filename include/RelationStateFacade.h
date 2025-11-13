#pragma once

#include "Button.h"
#include "RgbLed.h"

class RelationStateFacade {
private:
    RgbLed rgbLed;
    Button button;

public:
    RelationStateFacade();
    ~RelationStateFacade() = default;

    void loop();
};