#include "states/ReadyState.h"
#include "RelationMatchContext.h"
#include "INfcScanner.h"
#include "ILed.h"
#include <Arduino.h>

ReadyState::ReadyState(ILed** leds, int ledCount, INfcScanner* nfc,
                       uint8_t pairingBlock, uint8_t chainNumber)
    : leds(leds), ledCount(ledCount), nfc(nfc),
      pairingBlock(pairingBlock), chainNumber(chainNumber) {
    Serial.println("ReadyState: Ready to match NFC tags");
}

void ReadyState::scan_tag(RelationMatchContext* context) {
    if (nfc == nullptr) return;
    
    if (!nfc->is_tag_present()) {
        return;
    }

    nfc->read_tag();
    const char* uid = nfc->get_last_tag_uid();
    Serial.print("ReadyState: Tag detected - ");
    Serial.println(uid);
    
    uint8_t readData[1] = {0};
    bool readSuccess = nfc->read_data(pairingBlock, readData, 1);
    if (!readSuccess) {
        Serial.println("ReadyState: Error reading data from tag");
        return;
    }
    
    Serial.print("ReadyState: Chain number read from block 5: ");
    Serial.println(readData[0]);

    int distance = calculate_distance_wrapping(chainNumber, readData[0]);
    Serial.print("ReadyState: Calculated distance: ");
    Serial.println(distance);

    int mappedDistance = map(distance, 0, 255, 0, ledCount);
    Serial.print("ReadyState: Mapped distance to LED count: ");
    Serial.println(mappedDistance);

    turn_on_leds(mappedDistance);
    Serial.println("ReadyState: LEDs updated based on distance");
}

void ReadyState::turn_on_leds(int amount) {
    for (int i = 0; i < ledCount; ++i) {
        if (leds[i] == nullptr) {
            continue;
        }
        
        if (i < amount) {
            leds[i]->on();
        } else {
            leds[i]->off();
        }
    }
}