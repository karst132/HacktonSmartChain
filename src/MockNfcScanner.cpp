#include "MockNfcScanner.h"
#include <Arduino.h>
#include <string.h>

MockNfcScanner::MockNfcScanner()
    : tagPresent(false), simulateTagDetection(false) {
    memset(lastTagUid, 0, sizeof(lastTagUid));
    memset(mockData, 0, sizeof(mockData));
    strcpy(lastTagUid, "MOCK000000");
}

void MockNfcScanner::init() {
    Serial.println("MockNfcScanner initialized (for testing)");
}

bool MockNfcScanner::is_tag_present() {
    return tagPresent;
}

void MockNfcScanner::read_tag() {
    Serial.print("MockNfcScanner: Tag read - ");
    Serial.println(lastTagUid);
}

const char* MockNfcScanner::get_last_tag_uid() {
    return lastTagUid;
}

bool MockNfcScanner::write_data(uint8_t block, const uint8_t* data, uint8_t length) {
    if (length > 16) {
        Serial.println("MockNfcScanner: Error - Data too large");
        return false;
    }
    
    // Simulate writing data
    for (int i = 0; i < length; i++) {
        mockData[i] = data[i];
    }
    
    Serial.print("MockNfcScanner: Mock data written to block ");
    Serial.print(block);
    Serial.print(" - ");
    for (int i = 0; i < length; i++) {
        Serial.print(mockData[i]);
        Serial.print(" ");
    }
    Serial.println();
    
    return true;
}

bool MockNfcScanner::read_data(uint8_t block, uint8_t* data, uint8_t length) {
    if (length > 16) {
        Serial.println("MockNfcScanner: Error - Buffer too large");
        return false;
    }
    
    // Return mock data
    for (int i = 0; i < length; i++) {
        data[i] = mockData[i];
    }
    
    Serial.print("MockNfcScanner: Mock data read from block ");
    Serial.print(block);
    Serial.print(" - ");
    for (int i = 0; i < length; i++) {
        Serial.print(data[i]);
        Serial.print(" ");
    }
    Serial.println();
    
    return true;
}

void MockNfcScanner::set_tag_present(bool present) {
    tagPresent = present;
    if (present) {
        Serial.println("MockNfcScanner: Tag simulated as PRESENT");
    } else {
        Serial.println("MockNfcScanner: Tag simulated as ABSENT");
    }
}

void MockNfcScanner::set_mock_uid(const char* uid) {
    if (uid != nullptr) {
        strncpy(lastTagUid, uid, sizeof(lastTagUid) - 1);
        lastTagUid[sizeof(lastTagUid) - 1] = '\0';
        Serial.print("MockNfcScanner: Mock UID set to ");
        Serial.println(lastTagUid);
    }
}

void MockNfcScanner::clear_mock_data() {
    memset(mockData, 0, sizeof(mockData));
    Serial.println("MockNfcScanner: Mock data cleared");
}
