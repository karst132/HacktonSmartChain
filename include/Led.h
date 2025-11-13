#pragma once

class Led {
private:
    int pin;

public:
    explicit Led(int pin = -1);
    virtual ~Led() = default;

    virtual void toggle();
    virtual void on();
    virtual void off();
};