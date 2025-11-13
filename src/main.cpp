#include <Arduino.h>
#include "RelationStateFacade.h"
#include "RgbLed.h"
#include "Button.h"

// Pin definitions
const int RGB_RED_PIN = 9;
const int RGB_GREEN_PIN = 10;
const int RGB_BLUE_PIN = 11;
const int BUTTON_PIN = 12;

const int RGB_COLORS[][3] = {
    {255, 0, 0},     
    {0, 255, 0}     
};
const int COLOR_COUNT = 2;

// Global instances
IRgbLed* rgbLed = new RgbLed(RGB_RED_PIN, RGB_GREEN_PIN, RGB_BLUE_PIN);
IButton* button = new Button(BUTTON_PIN);
RelationStateFacade* facade = nullptr;

void setup() {
    Serial.begin(115200);
    
    facade = new RelationStateFacade(rgbLed, button, (int(*)[3])RGB_COLORS, COLOR_COUNT);
}

void loop() {
    Serial.println("Main loop running...");
    if (facade != nullptr) {
        facade->loop();
    }
    delay(500);
}