#pragma once

#include "states/IMatchState.h"
#include "Led.h"

class RelationMatchContext {
private:
    IMatchState* state;
    Led** leds;

public:
    explicit RelationMatchContext(IMatchState* initialState);
    ~RelationMatchContext() = default;

    void transition_state(IMatchState* state);
    void scan_tag();
};