#pragma once

class ILed {
public:
    virtual void on() = 0;
    virtual void off() = 0;
};
