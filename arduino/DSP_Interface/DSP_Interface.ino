#include "DSP_Menu.hpp"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd_obj(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // Initialize lcd display

void setup() {
  Serial.begin(115200);
}

void loop() {
  Menu mainMenu(&lcd_obj);
  Serial.println("hello");
  Serial.println("please input action (0-Back, 1-Up, 2-Down, 3-Select):");
  while (1) {
    while (!Serial.available()) {} // Wait for user input.
    uint8_t inputVal = Serial.read();
    switch (inputVal) {
      case 48:
        mainMenu.Input(0);
        break;
      case 49:
        mainMenu.Input(1);
        break;
      case 50:
        mainMenu.Input(2);
        break;
      case 51:
        mainMenu.Input(3);
        break;
      default:
        Serial.println(inputVal, DEC);
    }
  }
}
