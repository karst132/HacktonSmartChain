#pragma once

#include "IMatchState.h"

class ILed;
class INFC;

class SetupState : public IMatchState {
private:
    ILed** leds;
    int ledCount;
    INFC* nfc;

public:
    SetupState(ILed** leds, int ledCount, INFC* nfc);

    void scan_tag() override;
};
