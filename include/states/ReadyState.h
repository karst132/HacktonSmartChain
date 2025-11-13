#pragma once

#include "IMatchState.h"

class ILed;
class INfcScanner;

class ReadyState : public IMatchState {
private:
    ILed** leds;
    int ledCount;
    INfcScanner* nfc;

public:
    ReadyState(ILed** leds, int ledCount, INfcScanner* nfc);

    void scan_tag() override;
};
