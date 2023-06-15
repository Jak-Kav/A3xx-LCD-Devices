/**
Kav Simulations FCU LCD Example Code
Written by: James Kavanagh
This example code will demonstrate the FCU & EFIS working on a simple loop.
It is designed to show you how to call the functions and set up the device.

If you only have 1 EFIS, you can still run this code. It won't matter that the second one isn't plugged in.
**/

// Include the required libraries
#include "KAV_A3XX_FCU_LCD.h"
#include "KAV_A3XX_EFIS_LCD.h"

// Declare the pins for the FCU
#define FCU_CS      12
#define FCU_CLK     11
#define FCU_DATA    8
#define EFIS_L_CS   32
#define EFIS_L_CLK  33
#define EFIS_L_DATA 34
#define EFIS_R_CS   35
#define EFIS_R_CLK  36
#define EFIS_R_DATA 37

// Create the FCU and EFIS objects
KAV_A3XX_FCU_LCD fcu(FCU_CS, FCU_CLK, FCU_DATA);
KAV_A3XX_EFIS_LCD efisL(EFIS_L_CS, EFIS_L_CLK, EFIS_L_DATA);
KAV_A3XX_EFIS_LCD efisR(EFIS_R_CS, EFIS_R_CLK, EFIS_R_DATA);

void setup() {
  // Setup the device
  fcu.attach(FCU_CS, FCU_CLK, FCU_DATA);
  efisL.attach(EFIS_L_CS, EFIS_L_CLK, EFIS_L_DATA);
  efisR.attach(EFIS_R_CS, EFIS_R_CLK, EFIS_R_DATA);
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
  //
  efisL.showQNHValue(1016);
  efisR.showQFEValue(3005);
  delay(4000); // Wait a bit...

  // Demo State 2
  fcu.setSpeedDashes(0);
  fcu.setSpeedDot(0);
  fcu.setHeadingDashes(0);
  fcu.setHeadingDot(0);
  fcu.setVrtSpdDashes(0);
  fcu.setMachMode(75); // Set the value we want after the decimal. I.e., '80' will display '0.80'
  fcu.showHeadingValue(245);
  fcu.showAltitudeValue(12000);
  fcu.showVerticalValue(-1200); // Show a negative value
  //
  efisR.showQNHValue(1018);
  efisL.showQFEValue(3001);
  //
  delay(3000); // Wait a bit...
  fcu.showVerticalValue(800); // Show a positive value
  efisL.showStd(1);
  delay(3000); // Wait a bit...

  // Demo State 3
  fcu.setSpeedMode(250);
  fcu.toggleTrkHdgMode(1);
  fcu.showHeadingValue(210);
  fcu.showAltitudeValue(16000);
  fcu.showFPAValue(15);
  //
  efisL.showQNHValue(1024);
  efisR.showStd(1);
  delay(4000); // Wait a bit...

  // Clear
  fcu.clearLCD();
  delay(10); // Wait a bit...
}
