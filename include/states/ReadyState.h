#pragma once

#include "IMatchState.h"
#include <stdint.h>

class ILed;
class INfcScanner;

class ReadyState : public IMatchState {
private:
    ILed** leds;
    int ledCount;
    INfcScanner* nfc;
    uint8_t pairingBlock;
    uint8_t pairingSecret;

public:
    ReadyState(ILed** leds, int ledCount, INfcScanner* nfc,
               uint8_t pairingBlock, uint8_t pairingSecret);

    void scan_tag(RelationMatchContext* context) override;
};
