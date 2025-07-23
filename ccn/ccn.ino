

#include <IRLibSendBase.h>    // Base IR code
#include <IRLib_HashRaw.h>    // Raw signal sending

IRsendRaw mySender;

const int IRSenderPin = 3; // IR LED pin

// Button pins
const int onPin = 12;
const int offPin = 11;

#define RAW_DATA_LEN 100
uint16_t rawDataOn[RAW_DATA_LEN] = {
	3286, 3158, 458, 262, 538, 262, 538, 262, 
	542, 1182, 438, 262, 538, 262, 538, 1186, 
	434, 1186, 434, 262, 538, 262, 538, 1186, 
	434, 262, 538, 1186, 434, 266, 538, 262, 
	538, 262, 538, 1186, 434, 262, 538, 262, 
	538, 1186, 434, 1186, 434, 262, 538, 1186, 
	434, 262, 538, 1186, 434, 1186, 434, 262, 
	538, 266, 534, 266, 534, 266, 538, 266, 
	534, 266, 510, 322, 482, 318, 506, 266, 
	510, 318, 506, 270, 534, 266, 510, 318, 
	506, 266, 510, 1214, 430, 270, 534, 266, 
	510, 318, 506, 266, 534, 270, 510, 318, 
	482, 322, 506, };


uint16_t rawDataOff[RAW_DATA_LEN] = {
	3282, 3158, 458, 266, 538, 262, 538, 262, 
	538, 1186, 434, 262, 538, 262, 538, 1186, 
	434, 1186, 434, 262, 538, 266, 534, 1186, 
	434, 262, 538, 1186, 434, 266, 534, 270, 
	534, 262, 538, 1186, 434, 262, 538, 262, 
	538, 1186, 434, 266, 534, 262, 538, 1186, 
	434, 266, 534, 270, 530, 270, 534, 266, 
	534, 270, 530, 270, 534, 266, 534, 266, 
	534, 270, 530, 270, 534, 270, 530, 270, 
	534, 266, 534, 270, 530, 270, 530, 274, 
	530, 266, 534, 1186, 434, 266, 510, 322, 
	502, 274, 526, 274, 530, 270, 530, 274, 
	510, 314, 506, };


void setup() {
  Serial.begin(9600);
  pinMode(onPin, INPUT_PULLUP);
  pinMode(offPin, INPUT_PULLUP);
  delay(2000);
}

void loop() {
  if (digitalRead(onPin) == LOW) {
    mySender.send(rawDataOn, RAW_DATA_LEN, 38);
    Serial.println(F("AC Switched On"));
    delay(2000); // Debounce delay
  }

  if (digitalRead(offPin) == LOW) {
    mySender.send(rawDataOff, RAW_DATA_LEN, 38);
    Serial.println(F("AC Switched Off"));
    delay(2000); // Debounce delay
  }
}
