# A3xx-LCD-Devices

This repository contains all the relevant files you need to get up and running with our LCD devices.    

Currently only the A3xx FCU LCD is available, but the EFIS LCD is coming soon.

### Most Recent Version In `FCU&EFIS` Directory. Use This One!

Standalone Setup Video: https://youtu.be/K2MG2Fc2na8    <b><-- Start here to get the demo example working first!</b>    
MobiFlight Setup Video: https://youtu.be/qKGPGoqFOwo    

- - - - - - - - - -
# Jak Kav Custom Firmware   
This is my custom firware for the MobiFlight modules.   
It allows the user to use my custom LCD's for the FCU and EFIS.   
<b>There is a pre-built HEX file hardcoded with the pins detailed below</b>
Current release is inline with MobiFlight V2.4, and you should use the file named `mobiflight_mega_2_4_0_Custom (1FCU_2EFIS).hex`, regardless of whether you're using just 1 FCU, 1 FCU and 1 EFIS or 1 FCU and 2 EFIS.    

You need to put the `arduino_mega_kav.board.json` in your MobiFlight connector directory manually.    
`C:\...AppData\Local\MobiFlight\MobiFlight Connector\Boards\` 

It should be setup as a normal `LCD DISPLAY` from the 'Add Device' menu in the MobiFlight Modules settings page.    
![Device Choice](https://cdn.shopify.com/s/files/1/0736/3588/9464/files/Capture2.png?v=1686832847)    
It will send a string as it's LCD output, and that will be converted to a method and value in the custom LCD library.   
To use the precompiled HEX version, please connect to the following arduino mega pins:   
<b>FCU</b>    
CS = 12   
CLK = 11   
DATA = 8   
Backlight = +5V   

<b>EFIS LEFT</b>    
CS = 32   
CLK = 33   
DATA = 34   
Backlight = +5V   

<b>EFIS RIGHT</b>    
CS = 35   
CLK = 36   
DATA = 37   
Backlight = +5V   

If you wish to compile your own version with different pin numbers, you should change the values in `LCDDisplayCustom.cpp` in the `Add` function.    
We have only compiled and tested for the Arduino Mega 2560 board.

In `MFBoards.h`, we have created this as a new board type, and this should be reflected in the MobiFlight Connector when setting up.    
The devices should always be in this order, otherwise the data will be sent to the wrong device. <b>This is critical!</b>    
![New Board Type](https://cdn.shopify.com/s/files/1/0736/3588/9464/files/Capture1.jpg?v=1686832848)         
