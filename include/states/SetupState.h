#pragma once

#include "IMatchState.h"
#include <stdint.h>

class ILed;
class INfcScanner;

class SetupState : public IMatchState {
private:
    ILed** leds;
    int ledCount;
    INfcScanner* nfc;
    uint8_t pairingBlock;
    uint8_t chainNumber;
    IMatchState* nextState;

    void turn_half_leds_on(bool even);
    void turn_off_all_leds();
public:
    SetupState(ILed** leds, int ledCount, INfcScanner* nfc, 
               uint8_t pairingBlock, uint8_t chainNumber,
               IMatchState* nextState);

    void scan_tag(RelationMatchContext* context) override;
};
