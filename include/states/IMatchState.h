// This file defines the IMatchState interface with a public method scan_tag().
#ifndef IMATCHSTATE_H
#define IMATCHSTATE_H

class IMatchState {
public:
    virtual void scan_tag() = 0;
};

#endif // IMATCHSTATE_H