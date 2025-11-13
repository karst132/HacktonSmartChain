#pragma once

#include "IMatchState.h"

class ILed;
class INfc;

class SetupState : public IMatchState {
private:
    ILed** leds;
    int ledCount;
    INfc* nfc;

public:
    SetupState(ILed** leds, int ledCount, INfc* nfc);

    void scan_tag() override;
};
