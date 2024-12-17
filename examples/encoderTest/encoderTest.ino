#include "GroveEncoder.h"

#ifdef USE_TINYUSB
#include <Adafruit_TinyUSB.h>
#endif

int value = 0;
int bt_flag = 0;
void myCallback(int newValue, bool flag) {
    if (value != newValue) {
        value = newValue;
        Serial.print(newValue, HEX);
        Serial.print("\n");
    }
    if (flag && bt_flag) {
        Serial.println("button");
        bt_flag = 0;
    }
}
GroveEncoder myEncoder(2, &myCallback);
void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
    // put your main code here, to run repeatedly:
    while (1) {
        delay(100);
        bt_flag = 1;
    }
}
