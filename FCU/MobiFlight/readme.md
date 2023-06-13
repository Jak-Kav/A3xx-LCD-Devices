Here you can download the config files for MobiFlight, and the precompiled binary to flash to an Arduino Mega.    

As this has been precompiled for you, you can't change the pins. They must be connected as follows:    
<b>FCU</b>
* CS = Pin 12
* CLK = Pin 11
* DATA = Pin 8 
   
<b>EFIS</b>
* CS = Pin 32
* CLK = Pin 33
* DATA = Pin 34

We recommend using ['XLoader'](https://github.com/binaryupdates/xLoader) to simply upload the .hex file to the arduino.    
It's a very simple process, but there are some step-by-step tutorials on Google if you need them.    

KNOWN WORKING VERSIONS:    
MobiFlight <b>9.7.1</b>    
FBW A320 (Development) <b>e7c4fa0</b>    
