#include "RelationMatchContext.h"
#include "states/IMatchState.h"
#include <Arduino.h>

RelationMatchContext::RelationMatchContext(IMatchState* initialState) 
    : state(initialState) {
    Serial.println("RelationMatchContext initialized with state pattern");
}

void RelationMatchContext::transition_state(IMatchState* state) {
    if (state != nullptr) {
        this->state = state;
        Serial.println("State transitioned");
    }
}

void RelationMatchContext::scan_tag() {
    if (state != nullptr) {
        state->scan_tag();
    }
}