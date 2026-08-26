#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

// RFID Pins
#define RST_PIN 9
#define SS_PIN 10
MFRC522 mfrc522(SS_PIN, RST_PIN);

// Piezo setup
const int piezoPin = A0;
const int threshold = 150;
int prev = 0, stepCount = 0;
float vout, vin = 5.0;
unsigned long previousMillis = 0;
const long interval = 100;

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Toggle flag
bool isCounting = false;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Scan your card");
}

void loop() {
  // Card scan logic
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    Serial.print("Card UID: ");
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      Serial.print(mfrc522.uid.uidByte[i], HEX);
    }
    Serial.println();

    // Toggle step counting
    isCounting = !isCounting;

    if (isCounting) {
      stepCount = 0;
      prev = 1; // Avoid false step immediately
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Steps: 0");
      lcd.setCursor(0, 1);
      lcd.print("Voltage: 0.0V");
      Serial.println("Counting started.");
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Scan your card");
      Serial.println("Counting stopped.");
    }

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();

    delay(1000); // Debounce delay to prevent double-scan
  }

  // Step counting only when activated
  if (isCounting) {
    unsigned long currentMillis = millis();
    int sensorValue = analogRead(piezoPin);

    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      if (sensorValue > threshold && prev == 0) {
        stepCount++;
        lcd.setCursor(7, 0);
        lcd.print("    ");
        lcd.setCursor(7, 0);
        lcd.print(stepCount);

        vout = (sensorValue * vin) / 1023.0;
        lcd.setCursor(9, 1);
        lcd.print("     ");
        lcd.setCursor(9, 1);
        lcd.print(vout, 1);
        lcd.print("V");

        Serial.print("Step ");
        Serial.print(stepCount);
        Serial.print(" - Voltage: ");
        Serial.println(vout, 2);

        prev = 1;
      } else if (sensorValue < threshold) {
        prev = 0;
      }
    }
  }
}
