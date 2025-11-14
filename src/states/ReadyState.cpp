#include "states/ReadyState.h"
#include "RelationMatchContext.h"
#include "INfcScanner.h"
#include "ILed.h"
#include <Arduino.h>

ReadyState::ReadyState(ILed** leds, int ledCount, INfcScanner* nfc,
                       uint8_t pairingBlock, uint8_t chainNumber,
                       unsigned long ledTimeoutDuration)
    : leds(leds), ledCount(ledCount), nfc(nfc),
      pairingBlock(pairingBlock), chainNumber(chainNumber),
      ledTurnOnTime(0), ledsActive(false),
      ledTimeoutDuration(ledTimeoutDuration) {
    Serial.println("ReadyState: Ready to match NFC tags");
}

void ReadyState::scan_tag(RelationMatchContext* context) {
    if (nfc == nullptr) return;
    
    // Check if LEDs should be turned off after timeout duration
    if (ledsActive && (millis() - ledTurnOnTime) >= ledTimeoutDuration) {
        turn_off_all_leds();
        ledsActive = false;
        Serial.print("ReadyState: LEDs turned off (");
        Serial.print(ledTimeoutDuration);
        Serial.println("ms timeout)");
    }
    
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
    
    Serial.print("ReadyState: Chain number read from block ");
    Serial.print(pairingBlock);
    Serial.print(": ");
    Serial.println(readData[0]);

    int distance = calculate_distance_wrapping(chainNumber, readData[0]);
    Serial.print("ReadyState: Calculated distance: ");
    Serial.println(distance);

    int mappedDistance = map(distance, 0, 128, 0, ledCount);
    int calculatedLedCount = (mappedDistance - ledCount) * -1;
    Serial.print("ReadyState: Mapped distance to LED count: ");
    Serial.println(calculatedLedCount);

    turn_on_leds(calculatedLedCount);
    ledTurnOnTime = millis();
    ledsActive = true;
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

void ReadyState::turn_off_all_leds() {
    for (int i = 0; i < ledCount; ++i) {
        if (leds[i] == nullptr) {
            continue;
        }
        leds[i]->off();
    }
}

int ReadyState::calculate_distance_wrapping(uint8_t a, uint8_t b) {
    int directDistance = abs(static_cast<int>(a) - static_cast<int>(b));
    int wrappedDistance = 256 - directDistance;
    return (directDistance < wrappedDistance) ? directDistance : wrappedDistance;
}