# A3xx-LCD-Devices

This repository contains all the relevant files you need to get up and running with our LCD devices.    

Currently only the A3xx FCU LCD is available, but the EFIS LCD is coming soon.


Standalone Setup Video: https://youtu.be/K2MG2Fc2na8    <b><-- Start here to get the demo example working first!</b>    
MobiFlight Setup Video: https://youtu.be/qKGPGoqFOwo    

- - - - - - - - - -
## A Note On The Order Of Devices In The Config    
When setting up the devices in the config, they must be in this order:    
![Picture of order of LCD devices](https://cdn.shopify.com/s/files/1/0736/3588/9464/files/Capture.png)    
This is so that the right data is sent to the correct device.    
Where possible, you should also try to have these at the top of the config if you are using other devices (LED's, Encoders, etc).    
