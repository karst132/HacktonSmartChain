#pragma once

#include "IButton.h"

class Button : public IButton {
private:
    int pin;
    unsigned long last_press_down_timestamp;

public:
    explicit Button(int pin = -1);

    bool has_been_pressed() override;
};