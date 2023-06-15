/**
 * Kav A3XX EFIS LCD
 * Written by: James Kavanagh & Keith Greenwood
 * This library has been written to drive the 'Kav Simulations' EFIS LCD Display.
 */

#ifndef _KAV_A3XX_EFIS_LCD_h
#define _KAV_A3XX_EFIS_LCD_h

#define BUFFER_SIZE_MAX 16

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "HT1621.h"

class KAV_A3XX_EFIS_LCD {
private:
  // Fields
  HT1621 ht_efis;
  uint8_t buffer[BUFFER_SIZE_MAX];
  bool _initialised;
  byte _CS;
  byte _CLK;
  byte _DATA;

  // Methods
  void handleMobiFlightCmd(char *string);
  void displayDigit(uint8_t address, uint8_t digit);
  //void setBufferBit(uint8_t address, uint8_t bit, uint8_t enabled);
  void refreshLCD(uint8_t address);
  
public:
  // Constructor
  // 'CLK' is sometimes referred to as 'RW'
  KAV_A3XX_EFIS_LCD(uint8_t CS, uint8_t CLK, uint8_t DATA) : ht_efis(CS, CLK, DATA) { };

  void begin();
  void clearLCD();
  void attach(byte CS, byte CLK, byte DATA);
  void detach();
  void handleMobiFlightRaw(char *string);

  // Set QFE or QNH functions
  void setQFE(bool enabled);
  void setQNH(bool enabled);
  // Set Dot Function
  void setDot(bool enabled);
  // Show Std function
  void showStd(uint16_t state);

  // Show QFE function
  void showQFEValue(uint16_t value);
  // Show QNH function
  void showQNHValue(uint16_t value);
};

#endif //KAV_A3XX_EFIS_LCD_h
