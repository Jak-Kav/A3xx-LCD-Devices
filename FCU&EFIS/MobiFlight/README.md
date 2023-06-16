Here you can download the config files for MobiFlight, and the precompiled binary to flash to an Arduino Mega.    

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

<b>EFIS LEFT</b>    
CS = 32   
CLK = 33   
DATA = 34      

<b>EFIS RIGHT</b>    
CS = 35   
CLK = 36   
DATA = 37    

If you wish to compile your own version with different pin numbers, you should change the values in `LCDDisplayCustom.cpp` in the `Add` function.    
We have only compiled and tested for the Arduino Mega 2560 board.

In `MFBoards.h`, we have created this as a new board type, and this should be reflected in the MobiFlight Connector when setting up.    
The devices should always be in this order, otherwise the data will be sent to the wrong device. <b>This is critical!</b>    
![New Board Type](https://cdn.shopify.com/s/files/1/0736/3588/9464/files/Capture1.jpg?v=1686832848)   

You can now upload the firmware directly to the Mega through MobiFlight!    
Once you have placed the `arduino_mega_kav.board.json` into the Boards folder, you should then place the `.hex` file in the `C:...\AppData\Local\MobiFlight\MobiFlight Connector\firmware\` direcctory.    
You can now simply click the `Update Firmware` button and ensure that the device shows `Firmware 2.4.1` and the module type and name is `MobiFlight Mega Kav`.    
![Firmware Update](https://cdn.shopify.com/s/files/1/0736/3588/9464/files/Capture4.jpg?v=1686923609)   

KNOWN WORKING VERSIONS:    
MobiFlight <b>9.7.1</b>    
FBW A320 (Development) <b>e7c4fa0</b>    
