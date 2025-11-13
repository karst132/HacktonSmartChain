#include "RelationStateFacade.h"

RelationStateFacade::RelationStateFacade(IRgbLed* rgbLed, IButton* button) 
    : rgbLed(rgbLed), button(button) {
}

void RelationStateFacade::loop() {
    // Loop implementation (if needed)
}