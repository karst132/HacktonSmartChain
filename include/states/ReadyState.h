#ifndef READY_STATE_H
#define READY_STATE_H

#include "IMatchState.h"
#include "RelationMatchContext.h"
#include "Led.h"

class ReadyState : public IMatchState {
private:
    RelationMatchContext context;
    Led* leds[];

public:
    void set_context(RelationMatchContext context);
    void scan_tag();
};

#endif // READY_STATE_H