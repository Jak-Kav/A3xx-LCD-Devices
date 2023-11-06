/**
 * Kav A3XX RUDDER LCD
 * Written by: James Kavanagh & Keith Greenwood
 * This library has been written to drive the 'Kav Simulations' EFIS LCD Display.
 */

#ifndef _KAV_A3XX_RUDDER_LCD_h
#define _KAV_A3XX_RUDDER_LCD_h

#define BUFFER_SIZE_MAX 16

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "HT1621.h"

class KAV_A3XX_RUDDER_LCD {
private:
  // Fields
  HT1621 ht_rad_tcas;
  uint8_t buffer[BUFFER_SIZE_MAX];
  bool _initialised;
  byte _CS;
  byte _CLK;
  byte _DATA;

  // Methods
  void handleMobiFlightCmd(char *string);
  void displayDigit(uint8_t address, uint8_t digit);
  void refreshLCD(uint8_t address);
  
public:
  // Constructor
  // 'CLK' is sometimes referred to as 'RW'
  KAV_A3XX_RUDDER_LCD(uint8_t CS, uint8_t CLK, uint8_t DATA) : ht_rad_tcas(CS, CLK, DATA) { };

  void begin();
  void clearLCD();
  void clearDigit(uint8_t address);
  void attach(byte CS, byte CLK, byte DATA);
  void detach();
  void handleMobiFlightRaw(char *string);

  // Set 'L' and 'R' functions
  void setLeft(bool enabled);
  void setRight(bool enabled);
  // Set Dot Function
  void setDot(bool enabled);
  // Set value function
  void setValueInt(uint16_t value);

  // Show Rudder Value function
  void showLeftValueInt(uint16_t value);
  void showRightValueInt(uint16_t value);
};

#endif //KAV_A3XX_RUDDER_LCD_h
