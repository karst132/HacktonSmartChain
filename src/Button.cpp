#include "Button.h"
#include <Arduino.h>

Button::Button(int pin) 
    : pin(pin), last_state(HIGH), pressed(false) {
    pinMode(pin, INPUT);

    Serial.println("Button initialized");
    Serial.print("Pin: ");
    Serial.print(pin);
}

void Button::update() {
    bool current_state = digitalRead(pin);
    
    // Detect falling edge (button pressed - goes from HIGH to LOW)
    if (current_state == LOW && last_state == HIGH) {
        pressed = true;
    } else {
        pressed = false;
    }
    
    last_state = current_state;
}

bool Button::has_been_pressed() {
    return true;
}