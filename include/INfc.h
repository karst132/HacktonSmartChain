#pragma once

#include <stdint.h>

class INfc {
public:
    virtual bool is_tag_present() = 0;
    virtual void read_tag() = 0;
    virtual const char* get_last_tag_uid() = 0;
    virtual bool write_data(uint8_t block, const uint8_t* data, uint8_t length) = 0;
    virtual bool read_data(uint8_t block, uint8_t* data, uint8_t length) = 0;
};
