#pragma once

class IMatchState {
public:
    virtual ~IMatchState() = default;
    virtual void scan_tag() = 0;
};