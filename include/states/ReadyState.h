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
    uint8_t chainNumber;

    void turn_on_leds(int amount);
    int calculate_distance_wrapping(uint8_t a, uint8_t b);

public:
    ReadyState(ILed** leds, int ledCount, INfcScanner* nfc,
               uint8_t pairingBlock, uint8_t chainNumber);

    void scan_tag(RelationMatchContext* context) override;
};
