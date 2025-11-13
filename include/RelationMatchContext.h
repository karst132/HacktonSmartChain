#pragma once

#include "states/IMatchState.h"
#include "ILed.h"

class RelationMatchContext {
private:
    IMatchState* state;
    ILed** leds;
    int ledCount;

public:
    explicit RelationMatchContext(IMatchState* initialState);

    void transition_state(IMatchState* state);
    void scan_tag();
};