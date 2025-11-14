#include "states/SetupState.h"
#include "RelationMatchContext.h"
#include "INfcScanner.h"
#include "ILed.h"
#include <Arduino.h>




SetupState::SetupState(ILed** leds, int ledCount, INfcScanner* nfc, 
                       uint8_t pairingBlock, uint8_t chainNumber, 
                       IMatchState* nextState)
    : leds(leds), ledCount(ledCount), nfc(nfc), 
      pairingBlock(pairingBlock), chainNumber(chainNumber),
      nextState(nextState) {
    Serial.println("SetupState: Waiting for NFC tags to register");

    SetupState::turn_half_leds_on(true); 
}

void SetupState::scan_tag(RelationMatchContext* context) {
    if (nfc == nullptr || context == nullptr) return;
    
    if (!nfc->is_tag_present()) return;

    nfc->read_tag();
    Serial.print("SetupState: Tag detected - ");
    Serial.println(nfc->get_last_tag_uid());
    
    // Write the chain number to the designated block
    uint8_t dataToWrite[] = {chainNumber};
    
    bool writeSuccess = nfc->write_data(pairingBlock, dataToWrite, 1);
    if (!writeSuccess) {
        Serial.println("SetupState: Failed to write chain number");
        return;
    }

    Serial.print("SetupState: Chain number written to block ");
    Serial.print(pairingBlock);
    Serial.print(": ");
    Serial.println(chainNumber);
    
    SetupState::turn_off_all_leds();
    
    context->transition_state(nextState);
    Serial.println("SetupState: Transitioning to Next State");
}

void SetupState::turn_half_leds_on(bool even) {
    for (int i = 0; i < ledCount; ++i) {
        if (leds[i] == nullptr) {
            continue;
        }

        if ((i % 2 == 0) == even) {
            leds[i]->on();
        } else {
            leds[i]->off();
        }
    }
}

void SetupState::turn_off_all_leds() {
    for (int i = 0; i < ledCount; ++i) {
        if (leds[i] == nullptr) {
            continue;
        }
        leds[i]->off();
    }
}