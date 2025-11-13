#ifndef RELATIONSTATEFACADE_H
#define RELATIONSTATEFACADE_H

#include "Button.h"
#include "RgbLed.h"

class RelationStateFacade {
private:
    RgbLed rgbLed;
    Button button;

public:
    void loop();
};

#endif // RELATIONSTATEFACADE_H