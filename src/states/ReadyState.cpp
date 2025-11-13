#include "states/ReadyState.h"
#include "RelationMatchContext.h"
#include "INfc.h"
#include "ILed.h"
#include <Arduino.h>

ReadyState::ReadyState(ILed** leds, int ledCount, INfc* nfc)
    : leds(leds), ledCount(ledCount), nfc(nfc) {
    Serial.println("ReadyState: Ready to match NFC tags");
}

void ReadyState::scan_tag() {
    if (nfc == nullptr) return;
    
    if (nfc->is_tag_present()) {
        nfc->read_tag();
        const char* uid = nfc->get_last_tag_uid();
        
        Serial.print("ReadyState: Tag detected - ");
        Serial.println(uid);
        
        // Check if tag matches and light appropriate LED
        if (leds && ledCount > 1) {
            leds[1]->on();
        }
    }
}