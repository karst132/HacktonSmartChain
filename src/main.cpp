#include <Arduino.h>
#include "RelationStateFacade.h"
#include "AnodeRgbLed.h"
#include "Button.h"
#include "MFRC522NfcScanner.h"
#include "RelationMatchContext.h"
#include "states/SetupState.h"
#include "states/ReadyState.h"

// Pin definitions
const int RGB_RED_PIN = A0;
const int RGB_GREEN_PIN = A1;
const int RGB_BLUE_PIN = A2;
const int BUTTON_PIN = 6;

// NFC SPI pin definitions
const int NFC_CS_PIN = 10;      // SS (Slave Select)
const int NFC_RST_PIN = 5;      // RST (Reset)

const int RGB_COLORS[][3] = {
    {255, 104, 229}, 
    {0, 0, 255}
};
const int COLOR_COUNT = 2;

// Global pointers (initialized in setup)
IRgbLed* rgbLed = nullptr;
IButton* button = nullptr;
RelationStateFacade* facade = nullptr;
INfcScanner* nfc = nullptr;
RelationMatchContext* matchContext = nullptr;

void setup() {
    Serial.begin(115200);
    delay(100);
    
    
    // Instantiate components in setup
    rgbLed = new AnodeRgbLed(RGB_RED_PIN, RGB_GREEN_PIN, RGB_BLUE_PIN);
    button = new Button(BUTTON_PIN);
    
    // Instantiate NFC reader
    nfc = new MFRC522NfcScanner(NFC_CS_PIN, NFC_RST_PIN);
    ((MFRC522NfcScanner*)nfc)->init();

    // Create initial state (SetupState)
    IMatchState* initialState = new SetupState(nullptr, 0, nfc);
    // Create relation match context with state
    matchContext = new RelationMatchContext(initialState);
    
    // Create facade for button control
    facade = new RelationStateFacade(rgbLed, button, (int(*)[3])RGB_COLORS, COLOR_COUNT);
}

void loop() {
    Serial.println("Main loop running...");
    if (facade != nullptr) {
        facade->loop();
    }
    
    if (matchContext != nullptr) {
        matchContext->scan_tag();
    }
    
    delay(250);
}