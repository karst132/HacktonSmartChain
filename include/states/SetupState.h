#pragma once

#include "IMatchState.h"

class RelationMatchContext;  // Forward declaration
class Led;

class SetupState : public IMatchState {
private:
    RelationMatchContext* context;
    Led** leds;

public:
    SetupState();
    ~SetupState() override = default;

    void set_context(RelationMatchContext* context);
    void scan_tag() override;
};