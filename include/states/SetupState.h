#pragma once

#include "IMatchState.h"

class RelationMatchContext;  // Forward declaration
class ILed;

class SetupState : public IMatchState {
private:
    RelationMatchContext* context;
    ILed** leds;

public:
    SetupState();

    void set_context(RelationMatchContext* context);
    void scan_tag() override;
};