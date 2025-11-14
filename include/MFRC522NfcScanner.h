#pragma once

#include "INfcScanner.h"
#include <MFRC522.h>

class MFRC522NfcScanner : public INfcScanner {
private:
    MFRC522 mfrc522;
    char lastTagUid[18];  // String representation of UID
    MFRC522::MIFARE_Key key;  // Default authentication key
    
    bool authenticate(uint8_t block);

public:
    MFRC522NfcScanner(uint8_t chipSelectPin, uint8_t resetPin);
    
    void init();
    bool is_tag_present() override;
    void read_tag() override;
    const char* get_last_tag_uid() override;
    bool write_data(uint8_t block, const uint8_t* data, uint8_t length) override;
    bool read_data(uint8_t block, uint8_t* data, uint8_t length) override;
};
