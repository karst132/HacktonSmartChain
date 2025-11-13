#pragma once

#include "IButton.h"
#include "IRgbLed.h"

class RelationStateFacade {
private:
    IRgbLed* rgbLed;
    IButton* button;
    int (*colors)[3];  // Pointer to 2D array of RGB colors
    int colorCount;
    int currentColorIndex;

public:
    RelationStateFacade(IRgbLed* rgbLed, IButton* button, int (*colors)[3], int colorCount);

    void loop();
};