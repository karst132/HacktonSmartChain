#pragma once

#include "INfcScanner.h"

class MockNfcScanner : public INfcScanner {
private:
    char lastTagUid[18];
    uint8_t mockData[16];
    bool tagPresent;
    bool simulateTagDetection;

public:
    MockNfcScanner();
    
    void init();
    bool is_tag_present() override;
    void read_tag() override;
    const char* get_last_tag_uid() override;
    bool write_data(uint8_t block, const uint8_t* data, uint8_t length) override;
    bool read_data(uint8_t block, uint8_t* data, uint8_t length) override;
    
    // Mock-specific methods for testing
    void set_tag_present(bool present);
    void set_mock_uid(const char* uid);
    void clear_mock_data();
};
