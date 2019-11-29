# Seeed_Arduino_RotaryEncoder

This library support Encoder.

Connect the Encoder to the D2 and D3 pins of the motherboard.You can use other pins if you want.  

### Software usage  

-Install Seeed Arduino RotaryEncoder library to Arduino.  

-Start a project.  

-Create the callback function and set the Encoder pin.(just set SIGA.SIGB pin is equal to SIGA pin plus 1.)

   ```
   #include "GroveEncoder.h"

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
   GroveEncoder myEncoder(2, &myCallback);
   ```
   You can provide an optional callback, or poll the "getValue()" API.
   
