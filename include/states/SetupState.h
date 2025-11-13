#pragma once

#include "IMatchState.h"

class ILed;
class INfcScanner;

class SetupState : public IMatchState {
private:
    ILed** leds;
    int ledCount;
    INfcScanner* nfc;

public:
    SetupState(ILed** leds, int ledCount, INfcScanner* nfc);

    void scan_tag() override;
};
