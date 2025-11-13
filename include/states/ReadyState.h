#pragma once

#include "IMatchState.h"

class RelationMatchContext;  // Forward declaration
class Led;

class ReadyState : public IMatchState {
private:
    RelationMatchContext* context;
    Led** leds;

public:
    ReadyState();
    ~ReadyState() override = default;

    void set_context(RelationMatchContext* context);
    void scan_tag() override;
};