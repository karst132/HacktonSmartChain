#pragma once

class IButton {
public:
    virtual bool has_been_pressed() = 0;
    virtual ~IButton() = default;
};
