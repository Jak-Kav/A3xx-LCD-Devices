# IMPORTANT! NEW REPOSITORY!
We are now transitioning over to a new repository: [https://github.com/Kav-Simulations](https://github.com/Kav-Simulations)     
This is to accomdate our new natural integration with MobiFlight, and there is no longer any need for you to install our custom firmware or configuration files outside of MobiFlight.

All of our devices and firmware are now included in MobiFlight, and so the only need for our GitHub repository access is to contribute to development. If you are an end user, and don't need to contribute code, then you no longer need to follow our original installation guides.     
Please visit our YouTube [www.youtube.com/@kavsimulations5855](https://www.youtube.com/@kavsimulations5855/) for the latest video tutorial on getting setup with our devices.

</br>
<i>The original firmware will still be available for those that wish to continue using it, but it will no longer be supported or updated going forward. You can see the details below:</i>

- - - - - - - - - -

# A3xx-LCD-Devices

This repository contains all the relevant files you need to get up and running with our LCD devices.    

### Most Recent Version In `FCU&EFIS` Directory. Use This One!

Standalone Setup Video: https://youtu.be/K2MG2Fc2na8    <b><-- Start here to get the demo example working first!</b>    
MobiFlight Setup Video: https://youtu.be/qKGPGoqFOwo     
<b>New Firmware Upgrade Video: https://youtu.be/AQkjJ02LWNs</b>     

- - - - - - - - - -
# Jak Kav Custom Firmware   
This is my custom firware for the MobiFlight modules.   
It allows the user to use my custom LCD's for the FCU and EFIS.   
<b>There is a pre-built HEX file hardcoded with the pins detailed below</b>
Current release is inline with MobiFlight V2.4.x, and you should use the file named `mobiflight_mega_kav_2_4_2.hex`, regardless of whether you're using just '1 FCU', '1 FCU and 1 EFIS' or '1 FCU and 2 EFIS'.    

You need to put the `arduino_mega_kav.board.json` in your MobiFlight connector directory manually.    
`C:\...AppData\Local\MobiFlight\MobiFlight Connector\Boards\`     
You should then place the `mobiflight_mega_kav_2_4_2.hex` file in the `C:...\AppData\Local\MobiFlight\MobiFlight Connector\firmware\` direcctory.    
You can now simply click the `Update Firmware` button and ensure that the device shows `Firmware 2.4.2` and the module type and name is `MobiFlight Mega Kav`.    
![Firmware Update](https://cdn.shopify.com/s/files/1/0736/3588/9464/files/Capture4.jpg?v=1686923609)  

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
