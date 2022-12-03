/**
 *  NFC helpers
 */
void setupNFCReader() {
  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata) {
    Serial.print("Didn't find PN53x board");
    while (1); // halt
  }

  // Got ok data, print it out!
  Serial.print("Found chip PN5"); Serial.println((versiondata >> 24) & 0xFF, HEX);
  Serial.print("Firmware ver. "); Serial.print((versiondata >> 16) & 0xFF, DEC);
  Serial.print('.'); Serial.println((versiondata >> 8) & 0xFF, DEC);

  // configure board to read RFID tags
  nfc.SAMConfig();

  Serial.println("Waiting for an ISO14443A Card ...");
}

void printNFCTagInfo(uint8_t uid[], uint8_t uidLength) {
  // Display some basic information about the card
  Serial.println("Found an ISO14443A card");
  Serial.print("  UID Length: "); Serial.print(uidLength, DEC); Serial.println(" bytes");
  Serial.print("  UID Value: ");
  nfc.PrintHex(uid, uidLength);
  Serial.println("");
}

String constructMessage(uint8_t uid[], uint8_t uidLength) {
  String animationType;
  uint8_t data[32];
  String message = "";
  // Constructing animationType value
  bool delimiterFound = false;
  for (uint8_t i = 0; i < 42; i++) {
    bool success = nfc.ntag2xx_ReadPage(i, data);
    if (success) {
      for (int i = 0; i < 4; i++) {
        if (delimiterFound) {
          if (data[i] == ',') {
            delimiterFound = false;
          } else {
            message += (char)data[i];
          }
        } else {
          if (data[i] == ',') {
            delimiterFound = true;
          }
        }
      }
    }
  }
  Serial.println(message.length() == 0 ? "I can't recognize that NFC tag" : message);
  return message.length() > 0 ? message : "";
}

void clearSerialAndWaitForNextTag() {
  Serial.flush();
  while (Serial.available()) {
    Serial.read();
  }
  Serial.flush();
}

void readNFC() {
  uint8_t success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
  uint8_t uidLength;                        // Length of the UID (4 or 7 bytes depending on ISO14443A card type)

  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);
  if (success) {
    printNFCTagInfo(uid, uidLength);

    if (uidLength == 7) {
      Serial.println("Seems to be an NTAG2xx tag (7 byte UID)");
      animationType = constructMessage(uid, uidLength);
    } else {
      Serial.println("This doesn't seem to be an NTAG203 tag (UUID length != 7 bytes)!");
    }

    // Wait a bit before trying again
    Serial.println();
    clearSerialAndWaitForNextTag();
  }
}
