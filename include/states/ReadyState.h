#pragma once

#include "IMatchState.h"

class ILed;
class INfc;

class ReadyState : public IMatchState {
private:
    ILed** leds;
    int ledCount;
    INfc* nfc;

public:
    ReadyState(ILed** leds, int ledCount, INfc* nfc);

    void scan_tag() override;
};
