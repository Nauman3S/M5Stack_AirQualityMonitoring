<p align="center">
  <a href="" rel="noopener">
 <img width=200px height=200px src="artwork/aqi.png" alt="Project logo"></a>
</p>

<h3 align="center">Smart Air Quality Monitor</h3>

<div align="center">

[![Status](https://img.shields.io/badge/status-active-success.svg)]()


</div>

---


<p align="center"> Smart Air Quality Monitor
    <br> 
</p>

## 📝 Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [Circuit](#circuit)
- [MQTT Topic Details](#mqtt)
- [Usage](#usage)
- [List Of Components](#list)
- [Built Using](#built_using)
- [DemoVideo](#DemoVideo)
- [Authors](#authors)


## 🧐 About <a name = "about"></a>

This repo contains

- Firmware
- Detailed instructions

for Smart Air Quality Monitor.



## Getting Started <a name = "getting_started"></a>

These instructions will get you a copy of the project up and running on your system.

### Prerequisites

Things you need to install the FW.

```
- Arduino IDE
```

### Installing <a name = "installing"></a>

A step by step series that tell you how to get the Firmware and Backend running

#### ESP32(M5STACK) Configuration

You should have Arduino IDE Installed

  1.  Add ESP32 Board to your Arduino IDE
    1. In your Arduino IDE, go to File> Preferences
        Installing ESP32 Add-on in Arduino IDE Windows, Mac OS X, Linux open preferences
    2. Enter ```https://dl.espressif.com/dl/package_esp32_index.json```<br>
              ```https://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/arduino/package_m5stack_index.json``` 
        into the “Additional Board Manager URLs” field then, click the “OK” button:
        Note: if you already have the ESP32 boards URL, you can separate the URLs with a comma(each board will go to neaw line) as follows:
        ```https://dl.espressif.com/dl/package_esp32_index.json```
        ```http://arduino.esp8266.com/stable/package_esp8266com_index.json```
    
    
  2. Open the Boards Manager. Go to Tools > Board > Boards Manager…
  3. Search for ESP32 and press install button for the ESP32 by Espressif Systems.
  4. Search for M5Stack and press install

![M5StackBoard](artwork/m5stackboard.PNG)
  
  5.  That’s it. It should be installed after a few seconds.
  6.  Close and re-open the Arduino IDE.

  7.  Now copy the contents of the libs folder to the libraries directory of your Arduino
      1. If you are using windows, the libraries directory will be Documents/Arduino/libraries

##### ESP32 Node FW Uploading
  1.  Select ESP32 Dev Module from Tools->Board->ESP32
  2.  Select the correct port from Tools->Port
  3.  Then open Firmware.ino file,
  4.  Select Tools > ESP32 Sketch Data Upload menu item. This should start uploading the files into ESP32 flash file system.
  5.  Now Upload the Code to your ESP32 Dev Module.
  6.  Your ESP32 is now ready to be used.


## Circuit <a name = "circuit"></a>


### ESP32 Dev Module Pinout


- Relay should be connected to GPIO26 of the M5Stack. This can be chnaged in Firmware.ino


## MQTT Topic Details <a name = "mqtt"></a>
### Topics List
#### Logs
1.  <span style="color: green">smart-air/logs</span> `(all log messages are published to this topic) READ-ONLY`



## Usage <a name = "usage"></a>

1.  Upload the code to your M5Stack.
2.  Power on your ESP32, it will present you with an AP named ```SmartAir-abc``` (while ```SmartAir``` can be changed in the portal and ```abc``` is a unique id for each esp32)
3.  Default captive portal password `123456789AP` which can be changed in captive portal.
4.  Connect to the ESP32 access point and open the web-browser and navigate to the link ```http://esp32.local/_ac```. This link will work on most of the operating systems but if your operating system is not allowing to open it, you may want to check the captive portal IP Address from the serial monitor and can use that IP address inplace of the above mentioned URL.
5.  The default access IP Address is ```http://192.168.4.1/_ac```
6.  You will be presented with a main dashboard as shown below(based on your device)
   ![SCR1](Circuit/scr1.png)

7.  Once connected to a WiFi network, you can again access the captive portal using same URL or the IP Address from the Serial monitor.
8.  The data is published to the MQTT Topic ```SmartAir/{hostname}``` while the hostname is the one which you can define in Settings page of the captive portal.
9.  You can also check the realted IP address in the settings screen of M5Stack by pressing the button 'B' two times.

## List of Components <a name = "list"></a>

Following components are used to make this project

1.  VOC Sensor
    https://www.adafruit.com/product/3566
2.  PM2.5 Sensor
    https://www.adafruit.com/product/4505
3.  Generic 12v Relay Module
    https://www.amazon.com/ANMBEST-Channel-Optocoupler-Expansion-Raspberry/dp/B08PNX72ZQ/ref=sr_1_9?dchild=1&keywords=12v+relay+module&qid=1632992909&sr=8-9


## ⛏️ Built Using <a name = "built_using"></a>

- [Arduino](https://www.arduino.cc/) - Embedded Framework and IDE - For Sensor Node Design

## 📹 Demo Video <a name = "DemoVideo"></a>

[SmartAir Demo Video](https://youtu.be/Dd3uMzf-TNA) - Demo Video Part 1
[SmartAir Demo Video](https://youtu.be/cCcm4IN_Dts) - Demo Video Part 2




## ✍️ Authors <a name = "authors"></a>

- [@Nauman3S](https://github.com/Nauman3S) - Development and Deployment
