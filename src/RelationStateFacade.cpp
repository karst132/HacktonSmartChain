#include "RelationStateFacade.h"
#include <Arduino.h>

RelationStateFacade::RelationStateFacade(IRgbLed* rgbLed, IButton* button) 
    : rgbLed(rgbLed), button(button) {
}

void RelationStateFacade::loop() {
    // Update button state
    button->update();
    
    // Check if button was pressed (only triggers once per press)
    if (button->has_been_pressed()) {
        Serial.println("Button pressed!");
    }
}