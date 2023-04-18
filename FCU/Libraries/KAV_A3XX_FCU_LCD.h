/**
 * KAV A3XX FCU LCD
 * Written by: James Kavanagh & Keith Greenwood
 * This library has been written to drive the 'Kav Simulations' FCU LCD Display.
 */

#ifndef _KAV_A3XX_FCU_LCD_h
#define _KAV_A3XX_FCU_LCD_h

#define BUFFER_SIZE_MAX 16

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "HT1621.h"

class KAV_A3XX_FCU_LCD {
private:
  // Fields
  HT1621 ht;
  uint8_t buffer[BUFFER_SIZE_MAX];
  bool vertSignEnabled;
  bool _initialised;
  byte _CS;
  byte _CLK;
  byte _DATA;
  bool trkActive;

  // Methods
  void handleMobiFlightCmd(char *string);
  void displayDigit(uint8_t address, uint8_t digit);
  //void setBufferBit(uint8_t address, uint8_t bit, uint8_t enabled);
  void refreshLCD(uint8_t address);
  
public:
  // Constructor
  // 'CLK' is sometimes referred to as 'RW'
  KAV_A3XX_FCU_LCD(uint8_t CS, uint8_t CLK, uint8_t DATA) : ht(CS, CLK, DATA), vertSignEnabled(true) { };

  void begin();
  void clearLCD();
  void attach(byte CS, byte CLK, byte DATA);
  void detach();
  void handleMobiFlightRaw(char *string);

  //Speed and Mach functions
  void setSpeedLabel(bool enabled);
  void setMachLabel(bool enabled);
  void setSpeedDot(int8_t state);
  void showSpeedValue(uint16_t value);

  //Heading, Track and Latitude Functions
  void setHeadingLabel(bool enabled);
  void setTrackLabel(bool enabled);
  void setLatitudeLabel(bool enabled);
  void setHeadingDot(int8_t state);
  void showHeadingValue(uint16_t value);

  //Altitude Functions
  void setAltitudeLabel(bool enabled);
  void setLvlChLabel(bool enabled);
  void setAltitudeDot(int8_t state);
  void showAltitudeValue(uint32_t value);

  //Vertical_Speed & FPA Functions
  void setVrtSpdLabel(bool enabled);
  void setFPALabel(bool enabled);
  void setSignLabel(bool enabled);
  void showVerticalValue(int16_t value);
  void showFPAValue(int8_t value);

  //Preset States
  void setSpeedDashes(int8_t state);
  void setHeadingDashes(int8_t state);
  void setAltitudeDashes(int8_t state);
  void setVrtSpdDashes(int8_t state);
  void setStartLabels();
  void toggleTrkHdgMode(int8_t state);
  void setHeadingMode();
  void setTrackMode();
  void setSpeedMode(uint16_t value);
  void setMachMode(uint16_t value);
};

#endif //KAV_A3XX_FCU_LCD_h
