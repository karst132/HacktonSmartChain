#include "AnodeRgbLed.h"
#include <Arduino.h>

AnodeRgbLed::AnodeRgbLed(int redPin, int greenPin, int bluePin) 
    : redPin(redPin), greenPin(greenPin), bluePin(bluePin) {
    // Initialize pins as outputs
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    
    Serial.println("AnodeRgbLed initialized (Common Anode)");
    Serial.print("Red Pin: ");
    Serial.print(redPin);
    Serial.print(", Green Pin: ");
    Serial.print(greenPin);
    Serial.print(", Blue Pin: ");
    Serial.println(bluePin);
}

void AnodeRgbLed::set_color(int red, int green, int blue) {
    Serial.print("Anode RGB LED: Setting color to (");
    Serial.print(red);
    Serial.print(", ");
    Serial.print(green);
    Serial.print(", ");
    Serial.print(blue);
    Serial.println(")");
    
    // For common anode: invert the values (255 - value)
    analogWrite(redPin, 255 - red);
    analogWrite(greenPin, 255 - green);
    analogWrite(bluePin, 255 - blue);
}
