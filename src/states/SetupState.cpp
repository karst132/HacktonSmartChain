#include "states/SetupState.h"
#include "RelationMatchContext.h"
#include "INfc.h"
#include "ILed.h"
#include <Arduino.h>

SetupState::SetupState(ILed** leds, int ledCount, INfc* nfc)
    : leds(leds), ledCount(ledCount), nfc(nfc) {
    Serial.println("SetupState: Waiting for NFC tags to register");
}

void SetupState::scan_tag() {
    if (nfc == nullptr) return;
    
    if (nfc->is_tag_present()) {
        nfc->read_tag();
        Serial.print("SetupState: Tag registered - ");
        Serial.println(nfc->get_last_tag_uid());
        
        // Light up LED to indicate registration
        if (leds && ledCount > 0) {
            leds[0]->on();
        }
    }
}