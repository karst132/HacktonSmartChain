#pragma once

#include "IButton.h"
#include "IRgbLed.h"

class RelationStateFacade {
private:
    IRgbLed* rgbLed;
    IButton* button;

public:
    RelationStateFacade(IRgbLed* rgbLed, IButton* button);
    ~RelationStateFacade() = default;

    void loop();
};