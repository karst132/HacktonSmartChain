#include "Button.h"

Button::Button(int pin) 
    : pin(pin), last_press_down_timestamp(0) {
}

bool Button::has_been_pressed() {
    // Implementation to check if button has been pressed
    return false;
}