#pragma once

#include "states/IMatchState.h"

class RelationMatchContext {
private:
    IMatchState* state;

public:
    explicit RelationMatchContext(IMatchState* initialState);

    void transition_state(IMatchState* state);
    void scan_tag();
};