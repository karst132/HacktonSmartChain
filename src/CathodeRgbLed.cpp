#include "CathodeRgbLed.h"
#include <Arduino.h>

CathodeRgbLed::CathodeRgbLed(int redPin, int greenPin, int bluePin) 
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

void CathodeRgbLed::on() {
    Serial.println("Cathode RGB LED: ON (White)");
    // For common anode: 0 = full brightness
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
}

void CathodeRgbLed::off() {
    Serial.println("Cathode RGB LED: OFF");
    // For common anode: 255 = off
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
}

void CathodeRgbLed::set_color(int red, int green, int blue) {
    Serial.print("Cathode RGB LED: Setting color to (");
    Serial.print(red);
    Serial.print(", ");
    Serial.print(green);
    Serial.print(", ");
    Serial.print(blue);
    Serial.println(")");
    
    // For common anode: invert the values (255 - value)
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
}
