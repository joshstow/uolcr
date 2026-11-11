// ============================================================
//  RFID Door Lock
//  Unlocks a relay for 2 seconds when the authorised tag is scanned.
//  Wrong tag -> buzzer beeps and LED flashes.
// ============================================================

#include <SPI.h>       // SPI communication between Arduino and RFID module
#include <MFRC522.h>   // Functions for interacting with the RFID module

// ---------- Pin definitions ----------
#define SS_PIN     10  // SS pin on RFID module
#define RST_PIN    5   // RST pin on RFID module
#define RELAY_PIN  A5  // Arduino pin connected to the relay

// ---------- RFID reader ----------
MFRC522 rfid(SS_PIN, RST_PIN);  // Create MFRC522 instance with SS and RST pins

// ---------- Authorised tag ----------
// WHERE TO WRITE PIN CODE:
byte keyTagUID[4] = { 0xC5, 0x52, 0xC8, 0x75 };


// ============================================================
//  Setup
// ============================================================
void setup() {
  Serial.begin(9600);

  SPI.begin();                    // Initialise SPI protocol
  rfid.PCD_Init();                // Initialise MFRC522 (ready to detect + read tags)

  pinMode(RELAY_PIN, OUTPUT);     // Set relay pin as an output
  digitalWrite(RELAY_PIN, HIGH);  // Lock the door initially

  // ************************************************************
  //  TASK 1: Set up the buzzer and LED
  // ************************************************************
  //  pinMode syntax:  pinMode(PIN, MODE);
  //    PIN:  connection to Arduino (integer number)
  //    MODE: either INPUT or OUTPUT

  pinMode(    ,    );   // Initialise buzzer pin as an output
  pinMode(    ,    );   // Initialise LED pin as an output

  //  Ensure buzzer and LED are OFF initially
  //  digitalWrite syntax:  digitalWrite(PIN, VALUE);
  //    VALUE: either HIGH or LOW

  digitalWrite(    ,    );   // Buzzer is OFF (LOW)
  digitalWrite(    ,    );   // LED is OFF (LOW)
  // ************************************************************

  Serial.println("Tap RFID/NFC Tag on reader");
}


// ============================================================
//  Main loop
// ============================================================
void loop() {
  // Wait until a new tag is present and its UID can be read
  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial())   return;

  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);

  // ---------- Check scanned UID against the authorised tag ----------
  if (rfid.uid.uidByte[0] == keyTagUID[0] &&
      rfid.uid.uidByte[1] == keyTagUID[1] &&
      rfid.uid.uidByte[2] == keyTagUID[2] &&
      rfid.uid.uidByte[3] == keyTagUID[3]) {

    // Access granted: unlock for 2 seconds, then lock again
    Serial.println("Access is granted");
    digitalWrite(RELAY_PIN, LOW);   // Unlock the door
    delay(2000);
    digitalWrite(RELAY_PIN, HIGH);  // Lock the door

  } else {

    // Access denied: print the UID of the unrecognised tag
    Serial.print("Access denied for user with UID:");
    for (int i = 0; i < rfid.uid.size; i++) {
      Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(rfid.uid.uidByte[i], HEX);
    }
    Serial.println();

    // ************************************************************
    //  TASK 2: Sound the alarm
    // ************************************************************
    //  Beep the buzzer for 1 second
    digitalWrite(    ,    );   // Buzzer is ON
    delay(    );               // In milliseconds
    digitalWrite(    ,    );   // Buzzer is OFF

    //  LED flashes:
    //  Similar to the buzzer (MISSING!!):



    // ************************************************************
  }

  // ---------- Clean up ----------
  rfid.PICC_HaltA();       // Halt communication with the scanned tag
  rfid.PCD_StopCrypto1();  // Stop encryption on the reader
}