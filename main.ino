#include <EEPROM.h>

#define PinLEDYellow 1
#define PinLEDGreen 2
#define PinLEDRed 3
#define PinTrigger 4

int state = 0;

void setup() {
  pinMode(PinLEDYellow, OUTPUT);
  pinMode(PinLEDGreen, OUTPUT);
  pinMode(PinLEDRed, OUTPUT);
  pinMode(PinTrigger, INPUT_PULLUP);

  Serial.begin(9600);

  state = EEPROM.read(0);

  if (state < 0 || state > 2) {
    state = 0;
  }
}

void loop() {
  if (state == 0) {
    Serial.print("oi");
    digitalWrite(PinLEDRed, HIGH);
    digitalWrite(PinLEDYellow, LOW);
    digitalWrite(PinLEDGreen, LOW);

    delay(600);

    digitalWrite(PinLEDRed, LOW);
    digitalWrite(PinLEDYellow, HIGH);
    digitalWrite(PinLEDGreen, LOW);

    delay(20000);

    digitalWrite(PinLEDRed, LOW);
    digitalWrite(PinLEDYellow, LOW);
    digitalWrite(PinLEDGreen, HIGH);

    delay(60000);

    state = 1;
  }
  else if (state == 1) {
    Serial.println("cheguei");
    digitalWrite(PinLEDRed, HIGH);
    digitalWrite(PinLEDYellow, LOW);
    digitalWrite(PinLEDGreen, LOW);

    state = 2;
  }
  else if (state == 2) {
    int swt = digitalRead(PinTrigger);

    if (swt == LOW) {
      digitalWrite(PinLEDRed, HIGH);
      digitalWrite(PinLEDYellow, HIGH);
      digitalWrite(PinLEDGreen, HIGH);
    }
    else {
      digitalWrite(PinLEDRed, LOW);
      digitalWrite(PinLEDYellow, LOW);
      digitalWrite(PinLEDGreen, LOW);
    }
  }

  EEPROM.write(0, state);
  EEPROM.commit();
}
