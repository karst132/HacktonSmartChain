#include "Led.h"
#include <Arduino.h>

Led::Led(int pin) : pin(pin) {
    pinMode(pin, OUTPUT);
}

void Led::on() {
    digitalWrite(pin, HIGH);
}

void Led::off() {
    digitalWrite(pin, LOW);
}