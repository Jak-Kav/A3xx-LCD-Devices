/**
Kav Simulations Rudder Trim LCD Example Code
Written by: James Kavanagh
This example code will demonstrate the Rudder Trim LCD working on a simple loop.
It is designed to show you how to call the functions and set up the device.
**/

// Include the required libraries
#include "KAV_A3XX_RUDDER_LCD.h"
#include "KAV_A3XX_BATTERY_LCD.h"
#include "KAV_A3XX_RAD_TCAS_LCD.h"

// Declare the pins for the Rudder
#define RUDDER_CS 10
#define RUDDER_CLK 9
#define RUDDER_DATA 8
#define BATTERY_CS 7
#define BATTERY_CLK 6
#define BATTERY_DATA 5
#define RAD_TCAS_CS 4
#define RAD_TCAS_CLK 3
#define RAD_TCAS_DATA 2

// Create the FCU and EFIS objects
KAV_A3XX_RUDDER_LCD rudder(RUDDER_CS, RUDDER_CLK, RUDDER_DATA);
KAV_A3XX_BATTERY_LCD battery(BATTERY_CS, BATTERY_CLK, BATTERY_DATA);
KAV_A3XX_RAD_TCAS_LCD rad_tcas(RAD_TCAS_CS, RAD_TCAS_CLK, RAD_TCAS_DATA);

void setup()
{
  // Setup the device
  rudder.attach(RUDDER_CS, RUDDER_CLK, RUDDER_DATA);
  battery.attach(BATTERY_CS, BATTERY_CLK, BATTERY_DATA);
  rad_tcas.attach(RAD_TCAS_CS, RAD_TCAS_CLK, RAD_TCAS_DATA);
}

void loop()
{
  // Demo State 1
  battery.showBattValueInt(279);
  rad_tcas.showRadio(118000);
  for (int i = 0; i < 21; i++)
  {
    rudder.showLeftValueInt(i);
    delay(150);
  }
  delay(2000);

  // Demo State 2
  rad_tcas.showRadio(122800);
  for (int i = 21; i >= 0; i--)
  {
    rudder.showLeftValueInt(i);
    if (i < 10) {battery.showBattValueInt(270 + i);}
    delay(150);
  }
  delay(2000);

  // Demo State 3
  rad_tcas.showTcas(1234);
  for (int i = 0; i < 21; i++)
  {
    rudder.showRightValueInt(i);
    if (i < 10) {battery.showBattValueInt(270 + i);}
    delay(150);
  }
  delay(2000);

  // Demo State 4
  battery.showBattValueInt(280);
  for (int i = 21; i >= 0; i--)
  {
    rudder.showRightValueInt(i);
    rad_tcas.showRadio(122800 - (i * 100));
    delay(150);
  }
  delay(2000);

  // Clear
  battery.clearLCD();
  rudder.clearLCD();
  rad_tcas.clearLCD();
  delay(10); // Wait a bit...
}
