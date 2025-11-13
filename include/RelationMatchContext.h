#ifndef RELATIONMATCHCONTEXT_H
#define RELATIONMATCHCONTEXT_H

#include "states/IMatchState.h"
#include "Led.h"

class RelationMatchContext {
private:
    IMatchState* state;
    Led** leds;

public:
    RelationMatchContext(IMatchState* initialState);
    void transition_state(IMatchState* state);
    void scan_tag();
};

#endif // RELATIONMATCHCONTEXT_H