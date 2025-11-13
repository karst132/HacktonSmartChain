#include <Arduino.h>
#include "RelationStateFacade.h"
#include "AnodeRgbLed.h"
#include "Button.h"

// Pin definitions
const int RGB_RED_PIN = A0;
const int RGB_GREEN_PIN = A1;
const int RGB_BLUE_PIN = A2;
const int BUTTON_PIN = 6;

const int RGB_COLORS[][3] = {
    {255, 104, 229}, 
    {0, 0, 255}
};
const int COLOR_COUNT = 2;

// Global pointers (initialized in setup)
IRgbLed* rgbLed = nullptr;
IButton* button = nullptr;
RelationStateFacade* facade = nullptr;

void setup() {
    Serial.begin(115200);
    
    // Instantiate components in setup
    rgbLed = new AnodeRgbLed(RGB_RED_PIN, RGB_GREEN_PIN, RGB_BLUE_PIN);
    button = new Button(BUTTON_PIN);
    facade = new RelationStateFacade(rgbLed, button, (int(*)[3])RGB_COLORS, COLOR_COUNT);
}

void loop() {
    Serial.println("Main loop running...");
    if (facade != nullptr) {
        facade->loop();
    }
    delay(500);
}