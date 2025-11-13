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
    unsigned long ledTurnOnTime;     // Timestamp when LEDs were turned on
    bool ledsActive;                 // Track if LEDs are currently on
    unsigned long ledTimeoutDuration; // Duration in ms before LEDs turn off

    void turn_on_leds(int amount);
    int calculate_distance_wrapping(uint8_t a, uint8_t b);
    void turn_off_all_leds();

public:
    ReadyState(ILed** leds, int ledCount, INfcScanner* nfc,
               uint8_t pairingBlock, uint8_t chainNumber,
               unsigned long ledTimeoutDuration);

    void scan_tag(RelationMatchContext* context) override;
};
