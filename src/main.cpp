#include <Arduino.h>
#include "RelationStateFacade.h"
#include "AnodeRgbLed.h"
#include "Button.h"
#include "Led.h"
#include "MFRC522NfcScanner.h"
#include "RelationMatchContext.h"
#include "states/SetupState.h"
#include "states/ReadyState.h"

// Pin definitions
const int RGB_RED_PIN = A0;
const int RGB_GREEN_PIN = A1;
const int RGB_BLUE_PIN = A2;
const int BUTTON_PIN = 6;

// LED pins array
const int LED_PINS[] = {2, 3, 4, 7, 8};
const int LED_COUNT = 5;

// NFC SPI pin definitions
const int NFC_CS_PIN = 10;      // SS (Slave Select)
const int NFC_RST_PIN = 5;      // RST (Reset)

// NFC configuration constants
const uint8_t NFC_PAIRING_BLOCK = 5;      // Block where pairing data is stored
uint8_t NFC_CHAIN_NUMBER;                 // Random chain number (initialized in setup)

// LED configuration constants
const unsigned long LED_TIMEOUT_DURATION = 5000; // Timeout in milliseconds

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
ILed* leds[LED_COUNT] = {nullptr};  // Array of LED pointers
RelationMatchContext* matchContext = nullptr;

void setup() {
    Serial.begin(115200);
    delay(100);
    
    // Initialize random seed and generate chain number
    randomSeed(analogRead(0));
    NFC_CHAIN_NUMBER = random(0, 256);
    Serial.print("Generated NFC Chain Number: ");
    Serial.println(NFC_CHAIN_NUMBER);
    

    // Instantiate components in setup
    rgbLed = new AnodeRgbLed(RGB_RED_PIN, RGB_GREEN_PIN, RGB_BLUE_PIN);
    button = new Button(BUTTON_PIN);
    
    // Initialize LED array
    for (int i = 0; i < LED_COUNT; i++) {
        leds[i] = new Led(LED_PINS[i]);
    }
    
    nfc = new MFRC522NfcScanner(NFC_CS_PIN, NFC_RST_PIN);
    ((MFRC522NfcScanner*)nfc)->init();


    IMatchState* readyState = new ReadyState(leds, LED_COUNT, nfc, NFC_PAIRING_BLOCK, NFC_CHAIN_NUMBER, LED_TIMEOUT_DURATION);
    IMatchState* setupState = new SetupState(leds, LED_COUNT, nfc, NFC_PAIRING_BLOCK, NFC_CHAIN_NUMBER, readyState);
    matchContext = new RelationMatchContext(setupState);
    

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