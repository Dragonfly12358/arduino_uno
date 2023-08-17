#include <Wire.h>

char message[32]; // 31 characters + 1 for the null terminator

void setup() {
  Serial.begin(9600);
  Wire.begin(); // join I2C bus (address optional for master)
}

void loop() {
  Serial.println();
  strcpy(message, "bi'-ruo/gui'tto nomita'ina");
  talk(message);
  checkResponse();
  delay(1000);

  strcpy(message, "konichiwaA");  //error test
  talk(message);
  checkResponse();
  delay(1000);
}

void talk(const char *pMessage) {
  Serial.print("--> Sending: ");
  Serial.println(message);
  Wire.beginTransmission(0x2E); // transmit to device 0x2E
  Wire.write(pMessage); //31byte
  Wire.write(0x0D);           //[CR]
  Wire.endTransmission();    // stop transmitting
}

void checkResponse() {
  bool endOfCheck = false;
  while (!endOfCheck) {
    //42: *
    //62: >
    Wire.requestFrom(0x2E, 1, true);
    while (Wire.available()) {
      int resVal = Wire.read();
      Serial.print("<-- receiving: ");
      Serial.print(resVal);
      switch(resVal) {
        case 42:
          Serial.println(" busy");
          break;
        case 62:
          Serial.println(" ready");
          endOfCheck = true;
          break; 
        default:
          Serial.println(" error");
          endOfCheck = true;
          break;
      }
    }
    delay(500);
  }
}
