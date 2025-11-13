#include <Arduino.h>
#include "RelationStateFacade.h"
#include "RgbLed.h"
#include "Button.h"

// Pin definitions
const int RGB_RED_PIN = 9;
const int RGB_GREEN_PIN = 10;
const int RGB_BLUE_PIN = 11;
const int BUTTON_PIN = 12;

// Global instances
IRgbLed* rgbLed = new RgbLed(RGB_RED_PIN, RGB_GREEN_PIN, RGB_BLUE_PIN);
IButton* button = new Button(BUTTON_PIN);
RelationStateFacade* facade = nullptr;

void setup() {
    Serial.begin(115200);
    
    // Initialize the facade with interface pointers
    facade = new RelationStateFacade(rgbLed, button);
}

void loop() {
    Serial.println("Main loop running...");
    if (facade != nullptr) {
        facade->loop();
    }
    delay(1000);
}