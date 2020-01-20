#include <MFRC522.h>
#include <SPI.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

int outputPin = 3;
int inputPin = 2;
String UID = "44 6C 00 23"; //change here the UID of the card/cards that you want to give access

void setup() {
  pinMode(outputPin, OUTPUT);
  pinMode(inputPin, INPUT);
  
  Serial.begin(9600);
  
  SPI.begin();
  mfrc522.PCD_Init();

  digitalWrite(outputPin, LOW);                                                                                                  
  
}

/*
Check for cards/fobs and open 
safe if correct card is given

Post:
  Set the output pin to high to
  notify the main file that the 
  correct card/fob as been used
*/
void checkRFID() {
    
  if (digitalRead(inputPin) == HIGH) { // return if gate is closed in main file
    digitalWrite(outputPin, LOW);
    return;
  }
  
  // Look for new cards
  
  if (mfrc522.PICC_IsNewCardPresent()) 
  {
  
    // Select one of the cards
    if ( mfrc522.PICC_ReadCardSerial()) 
    {
  
      //Show UID on serial monitor
      Serial.print("UID tag :");
      String content= "";
      byte letter;
      for (byte i = 0; i < mfrc522.uid.size; i++) 
      {
         Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
         Serial.print(mfrc522.uid.uidByte[i], HEX);
         content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
         content.concat(String(mfrc522.uid.uidByte[i], HEX));
      }
      Serial.println();
      Serial.print("Message : ");
      content.toUpperCase();
      if (content.substring(1) == UID) 
      {
        Serial.println("Authorized access");
        digitalWrite(outputPin, HIGH);
      }
      else   
        Serial.println(" Access denied");
    }
  }
}

void loop() {
  checkRFID();
}
