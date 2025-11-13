#pragma once

class IButton {
public:
    virtual ~IButton() = default;
    virtual bool has_been_pressed() = 0;
};

class Button : public IButton {
private:
    int pin;
    unsigned long last_press_down_timestamp;

public:
    explicit Button(int pin = -1);
    ~Button() override = default;

    bool has_been_pressed() override;
};