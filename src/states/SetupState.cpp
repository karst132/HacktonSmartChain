#include "states/SetupState.h"
#include "RelationMatchContext.h"
#include "INfcScanner.h"
#include "ILed.h"
#include "states/ReadyState.h"
#include <Arduino.h>

SetupState::SetupState(ILed** leds, int ledCount, INfcScanner* nfc, 
                       uint8_t pairingBlock, uint8_t pairingSecret, 
                       IMatchState* nextState)
    : leds(leds), ledCount(ledCount), nfc(nfc), 
      pairingBlock(pairingBlock), pairingSecret(pairingSecret),
      nextState(nextState) {
    Serial.println("SetupState: Waiting for NFC tags to register");
}

void SetupState::scan_tag(RelationMatchContext* context) {
    if (nfc == nullptr || context == nullptr) return;
    
    if (!nfc->is_tag_present()) return;

    nfc->read_tag();
    Serial.print("SetupState: Tag detected - ");
    Serial.println(nfc->get_last_tag_uid());
    
    // Write the pairing secret to the designated block
    uint8_t dataToWrite[] = {pairingSecret};
    
    bool writeSuccess = nfc->write_data(pairingBlock, dataToWrite, 1);
    if (!writeSuccess) {
        Serial.println("SetupState: Failed to write pairing secret");
        return;
    }

    Serial.print("SetupState: Pairing secret written to block ");
    Serial.print(pairingBlock);
    Serial.print(": ");
    Serial.println(pairingSecret);
    
    // TODO: Indicate success via LEDs
    
    context->transition_state(nextState);
    Serial.println("SetupState: Transitioning to Next State");
}