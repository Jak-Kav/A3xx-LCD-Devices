This folder is a complete working demo of the FCU and EFIS LCD's. Simply download the folder and open the FCU_EFIS_TEST.ino file in arduino and flash to your device.

Make sure the devices are connected to correcct pins. You can change them to whatever you want of course.

Make sure VDD is connected to 5V on the arduino, and VSS is connected to GND on the arduino.    
The FCU is connected as follows:    
• Pin 1: CS (Serial Shift Pulse Input)    
• Pin 2: CLK (Serial Shift Pulse Input)    
• Pin 3: DI (Serial Data Input)    
• Pin 4: VSS (Power Ground)    
• Pin 5: VDD: (Power Anode)    

The EFIS is connected as follows:    
• Pin 1: CS (Serial Shift Pulse Input)    
• Pin 2: CLK (Serial Shift Pulse Input)    
• Pin 3: DI (Serial Data Input)    
• Pin 4: VSS (Power Ground)    
• Pin 5: VDD: (Power Anode)    
• Pin 6: BLA (Backlight Anode)    
• Pin 7: BLK: (Backlight Ground)    

On first use, the device might take a few moments to intialise and get going. If after a few moments there is still no display, but the backlight is illuminated then restart the arduino.

You should then see the device cycle through the 3 pre-programmed displays.
