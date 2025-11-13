#include "states/ReadyState.h"
#include "RelationMatchContext.h"
#include "INfcScanner.h"
#include "ILed.h"
#include <Arduino.h>

ReadyState::ReadyState(ILed** leds, int ledCount, INfcScanner* nfc,
                       uint8_t pairingBlock, uint8_t pairingSecret)
    : leds(leds), ledCount(ledCount), nfc(nfc),
      pairingBlock(pairingBlock), pairingSecret(pairingSecret) {
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
    
    Serial.print("ReadyState: Random number read from block 5: ");
    Serial.println(readData[0]);
}