#pragma once

class INFC {
public:
    virtual bool is_tag_present() = 0;
    virtual void read_tag() = 0;
    virtual const char* get_last_tag_uid() = 0;
};
