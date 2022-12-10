/**
    NFC helpers
*/
byte ntagHeader[4];
MFRC522::MIFARE_Key key;

void setupNFCReader() {
  SPI.begin();
  rfid.PCD_Init();

  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }

  Serial.println(F("This code scan the MIFARE Classsic NUID."));
  Serial.print(F("Using the following key:"));
}

void printNFCTagInfo() {
  // Display some basic information about the card
  Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  Serial.println(rfid.PICC_GetTypeName(piccType));

  Serial.println(F("A new patch has been detected."));
  // Store NUID into nuidPICC array
  for (byte i = 0; i < 4; i++) {
    ntagHeader[i] = rfid.uid.uidByte[i];
  }
}

String constructMessage() {
  MFRC522::StatusCode status;
  byte byteCount;
  byte buffer[18];
  byte i;

  String animationType;
  String message = "";
  bool delimiterFound = false;

  for (byte page = 0; page < 16; page += 4) { // Read returns data for 4 pages at a time.
    // Read pages
    byteCount = sizeof(buffer);
    status = rfid.MIFARE_Read(page, buffer, &byteCount);
    if (status != rfid.STATUS_OK) {
      Serial.print(F("Patch read failed: "));
      Serial.println(rfid.GetStatusCodeName(status));
      break;
    }

    for (byte offset = 0; offset < 4; offset++) {
      i = page + offset;
      for (byte index = 0; index < 4; index++) {
        i = 4 * offset + index;
        if (delimiterFound) {
          if (buffer[i] == ',') {
            delimiterFound = false;
          } else {
            message += (char)buffer[i];
          }
        } else {
          if (buffer[i] == ',') {
            delimiterFound = true;
          }
        }
      }
    }
  }
  Serial.println(message.length() == 0 ? "I can't recognize that NFC tag" : message);
  return message.length() > 0 ? message : "";
}

void readNFC() {
  if (!rfid.PICC_IsNewCardPresent()) {
    if (++timer % POLLING_MS == 0) {
      // Maybe turn off lights after poll time and no patch
    }
    return;
  }

  if (!rfid.PICC_ReadCardSerial()) {
    return;
  }

  printNFCTagInfo();
  animationType = constructMessage();
  clearSerialAndWaitForNextTag();
}

void clearSerialAndWaitForNextTag() {
  // Halt PICC
  rfid.PICC_HaltA();

  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
}
