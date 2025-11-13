#include "MFRC522Nfc.h"
#include <Arduino.h>
#include <SPI.h>

MFRC522Nfc::MFRC522Nfc(uint8_t chipSelectPin, uint8_t resetPin)
    : mfrc522(chipSelectPin, resetPin) {
    lastTagUid[0] = '\0';
}

void MFRC522Nfc::init() {
    SPI.begin();
    mfrc522.PCD_Init();
    Serial.println("MFRC522 NFC Reader initialized");
}

bool MFRC522Nfc::is_tag_present() {
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

void MFRC522Nfc::read_tag() {
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

const char* MFRC522Nfc::get_last_tag_uid() {
    return lastTagUid;
}
