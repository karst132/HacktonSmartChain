#pragma once

#include "IButton.h"

class Button : public IButton {
private:
    int pin;
    bool last_state;
    bool pressed;

public:
    explicit Button(int pin);

    void update() override;
    bool has_been_pressed() override;
};