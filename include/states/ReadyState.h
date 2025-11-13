#pragma once

#include "IMatchState.h"

class RelationMatchContext;  // Forward declaration
class ILed;

class ReadyState : public IMatchState {
private:
    RelationMatchContext* context;
    ILed** leds;

public:
    ReadyState();
    ~ReadyState() override = default;

    void set_context(RelationMatchContext* context);
    void scan_tag() override;
};