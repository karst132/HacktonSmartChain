#pragma once

#include "INfc.h"
#include <MFRC522.h>

class MFRC522Nfc : public INfc {
private:
    MFRC522 mfrc522;
    char lastTagUid[18];  // String representation of UID

public:
    MFRC522Nfc(uint8_t chipSelectPin, uint8_t resetPin);
    
    void init();
    bool is_tag_present() override;
    void read_tag() override;
    const char* get_last_tag_uid() override;
};
