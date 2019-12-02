# Seeed_Arduino_RotaryEncoder
### Introduction

This library support Encoder.

Connect the Encoder to the D2 and D3 pins of the motherboard.You can use other pins if you want.  

### Software usage  

-Install Seeed Arduino RotaryEncoder library to Arduino.  

-Start a project.  

-Create the callback function and set the Encoder pin.(just set SIGA.SIGB pin is equal to SIGA pin plus 1.)

   Usage of the library, see Example encoderTest
   
   1. Add headers
   ```
      #include "GroveEncoder.h"
   ```
   2. Create the callback function and initialize.The callback function gets the current Angle and the status of the button press.
   Define a 'value' to determine whether the Angle value has changed.Define a 'bt_flag' to prevent the button value from being read    more than once.And set 'bt flag' to 1 in the while() function.You can also get the Angle value through the getValue() function.
   ```
      int value = 0;
      int bt_flag = 0;
      void myCallback(int newValue, bool flag) {
        if(value != newValue)
        {
          value = newValue;
          Serial.print(newValue, HEX);
          Serial.print("\n");
        }
        if(flag && bt_flag)
        {
          Serial.println("button");
          bt_flag = 0;
        }
      }
   ```
   ```
        while(1)
        {
          Serial.println(myEncoder.getValue());
          delay(100);
          bt_flag = 1;
        }
   ```
      Initialize the Encoder.The parameters are the SIGA pin and the callback function name, respectively.
   ```
      GroveEncoder myEncoder(2, &myCallback);
   ```
   
