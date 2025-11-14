#pragma once

class IButton {
public:
    virtual void update() = 0;
    virtual bool has_been_pressed() = 0;
    virtual ~IButton() = default;
};
