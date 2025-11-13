#pragma once

class IButton {
public:
    virtual ~IButton() = default;
    virtual bool has_been_pressed() = 0;
};
