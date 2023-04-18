/**
Kav Simulations FCU LCD Example Code
Written by: James Kavanagh
This example code will demonstrate the FCU working on a simple loop.
It is designed to show you how to call the functions and set up the device.
**/

// Include the required libraries
#include "KAV_A3XX_FCU_LCD.h"

// Declare the pins for the FCU
#define FCU_CS    13
#define FCU_CLK   12
#define FCU_DATA  8

// Create the FCU and EFIS objects
KAV_A3XX_FCU_LCD fcu(FCU_CS, FCU_CLK, FCU_DATA);

void setup() {
  // Setup the device
  fcu.attach(FCU_CS, FCU_CLK, FCU_DATA);
}

void loop() {
  // We wouldn't need to do this normally, but we need to reset the start labels because we're clearing the FCU at the end of the loop.
  fcu.setStartLabels();

  // Demo State 1
  fcu.toggleTrkHdgMode(0); // 0 = Heading 1 = Track
  fcu.setSpeedMode(0); // To get the 'SPD' label
  fcu.setSpeedDashes(1);
  fcu.setSpeedDot(1);
  fcu.setHeadingDashes(1);
  fcu.setHeadingDot(1);
  fcu.showAltitudeValue(5000);
  fcu.setVrtSpdDashes(1);
  delay(4000); // Wait a bit...

  // Demo State 2
  fcu.setSpeedDashes(0);
  fcu.setSpeedDot(0);
  fcu.setHeadingDashes(0);
  fcu.setHeadingDot(0);
  fcu.setVrtSpdDashes(0);
  fcu.setMachMode(80); // Set the value we want after the decimal. I.e., '80' will display '0.80'
  fcu.showHeadingValue(245);
  fcu.showAltitudeValue(12000);
  fcu.showVerticalValue(-1200); // Show a negative value
  delay(3000); // Wait a bit...
  fcu.showVerticalValue(800); // Show a positive value
  delay(3000); // Wait a bit...

  // Demo State 3
  fcu.setSpeedMode(250);
  fcu.toggleTrkHdgMode(1);
  fcu.showHeadingValue(210);
  fcu.showAltitudeValue(16000);
  fcu.showFPAValue(-30);
  delay(4000); // Wait a bit...

  // Clear
  fcu.clearLCD();
  delay(10); // Wait a bit...
}
