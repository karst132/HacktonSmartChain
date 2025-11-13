#pragma once

#include "IMatchState.h"

class ILed;
class INFC;

class ReadyState : public IMatchState {
private:
    ILed** leds;
    int ledCount;
    INFC* nfc;

public:
    ReadyState(ILed** leds, int ledCount, INFC* nfc);

    void scan_tag() override;
};
