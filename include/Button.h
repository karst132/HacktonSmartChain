#ifndef BUTTON_H
#define BUTTON_H

class IButton {
public:
    virtual bool has_been_pressed() = 0;
};

class Button : public IButton {
private:
    int pin;
    unsigned long last_press_down_timestamp;

public:
    bool has_been_pressed() override;
};

#endif // BUTTON_H