#ifndef SETUPSTATE_H
#define SETUPSTATE_H

#include "RelationMatchContext.h"
#include "states/IMatchState.h"

class SetupState : public IMatchState {
private:
    RelationMatchContext context;
    Led* leds[10]; // Assuming a maximum of 10 LEDs, adjust as necessary

public:
    void set_context(RelationMatchContext context);
    void scan_tag();
};

#endif // SETUPSTATE_H