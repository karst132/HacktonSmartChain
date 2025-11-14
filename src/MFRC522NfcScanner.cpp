#include "MFRC522NfcScanner.h"
#include <Arduino.h>
#include <SPI.h>

MFRC522NfcScanner::MFRC522NfcScanner(uint8_t chipSelectPin, uint8_t resetPin)
    : mfrc522(chipSelectPin, resetPin) {
    lastTagUid[0] = '\0';
    
    // Initialize default key (factory default for MIFARE Classic)
    for (byte i = 0; i < 6; i++) {
        key.keyByte[i] = 0xFF;
    }
}

void MFRC522NfcScanner::init() {
    SPI.begin();
    mfrc522.PCD_Init();
    Serial.println("MFRC522 NFC Reader initialized");
}

bool MFRC522NfcScanner::is_tag_present() {
    // Look for new cards
    if (!mfrc522.PICC_IsNewCardPresent()) {
        return false;
    }
    
    // Select one of the cards
    if (!mfrc522.PICC_ReadCardSerial()) {
        return false;
    }
    
    return true;
}

void MFRC522NfcScanner::read_tag() {
    // Convert UID to string
    String uidString = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
        if (mfrc522.uid.uidByte[i] < 0x10) {
            uidString += "0";
        }
        uidString += String(mfrc522.uid.uidByte[i], HEX);
    }
    uidString.toUpperCase();
    uidString.toCharArray(lastTagUid, sizeof(lastTagUid));
    
    // Halt PICC
    mfrc522.PICC_HaltA();
    // Stop encryption on PCD
    mfrc522.PCD_StopCrypto1();
}

const char* MFRC522NfcScanner::get_last_tag_uid() {
    return lastTagUid;
}

bool MFRC522NfcScanner::authenticate(uint8_t block) {
    // Determine the sector trailer block for the given block
    // For MIFARE Classic 1K: blocks 0-63, grouped in sectors of 4 blocks
    // Sector trailer is the last block of each sector (blocks 3, 7, 11, 15, etc.)
    uint8_t trailerBlock = ((block / 4) * 4) + 3;
    
    // Authenticate using Key A
    MFRC522::StatusCode status = mfrc522.PCD_Authenticate(
        MFRC522::PICC_CMD_MF_AUTH_KEY_A,
        trailerBlock,
        &key,
        &(mfrc522.uid)
    );
    
    if (status != MFRC522::STATUS_OK) {
        Serial.print("Authentication failed: ");
        Serial.println(mfrc522.GetStatusCodeName(status));
        return false;
    }
    
    return true;
}

bool MFRC522NfcScanner::write_data(uint8_t block, const uint8_t* data, uint8_t length) {
    if (length > 16) {
        Serial.println("Error: Data too large (max 16 bytes per block)");
        return false;
    }
    
    // Check if trying to write to sector trailer (not allowed)
    if ((block + 1) % 4 == 0) {
        Serial.println("Error: Cannot write to sector trailer block");
        return false;
    }
    
    // Authenticate before writing
    if (!authenticate(block)) {
        return false;
    }
    
    // Prepare data buffer (16 bytes for MFRC522 block)
    uint8_t buffer[16] = {0};
    for (int i = 0; i < length; i++) {
        buffer[i] = data[i];
    }
    
    // Write to card
    MFRC522::StatusCode status = mfrc522.MIFARE_Write(block, buffer, 16);
    
    if (status != MFRC522::STATUS_OK) {
        Serial.print("Write failed: ");
        Serial.println(mfrc522.GetStatusCodeName(status));
        return false;
    }
    
    Serial.print("Data written to block ");
    Serial.println(block);
    return true;
}

bool MFRC522NfcScanner::read_data(uint8_t block, uint8_t* data, uint8_t length) {
    if (length > 16) {
        Serial.println("Error: Buffer too large (max 16 bytes per block)");
        return false;
    }
    
    // Authenticate before reading
    if (!authenticate(block)) {
        return false;
    }
    
    // Read from card
    uint8_t buffer[18];
    uint8_t bufferSize = sizeof(buffer);
    
    MFRC522::StatusCode status = mfrc522.MIFARE_Read(block, buffer, &bufferSize);
    
    if (status != MFRC522::STATUS_OK) {
        Serial.print("Read failed: ");
        Serial.println(mfrc522.GetStatusCodeName(status));
        return false;
    }
    
    // Copy requested data
    for (int i = 0; i < length; i++) {
        data[i] = buffer[i];
    }
    
    Serial.print("Data read from block ");
    Serial.println(block);
    return true;
}
