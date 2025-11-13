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

void AnodeRgbLed::on() {
    Serial.println("Anode RGB LED: ON (White)");
    // For common anode: 0 = full brightness
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
}

void AnodeRgbLed::off() {
    Serial.println("Anode RGB LED: OFF");
    // For common anode: 255 = off
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
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
