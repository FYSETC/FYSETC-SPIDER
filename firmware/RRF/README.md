# Firmware

## Changes

This firmware is base on [gloomyandy/RRFBuild at v3.3-dev (github.com)](https://github.com/gloomyandy/RRFBuild/tree/v3.3-dev). The original firmware size is larger than 512k which exceed STM32F446 chip flash room. So i remove/disable some features. You can check what have been changed below. And there is `Patches` folder showing all the changes.

```
λ git log -16 --oneline
65fa2a9 (HEAD -> v3.3-dev) Add STM32F446 variants
4152f02 Disable HAS_VOLTAGE_MONITOR
2ad660c Remove NonVolatileMemory support
e1aa79e Disable HAS_CPU_TEMP_SENSOR
513cf9a Comment paneldue update function
c04cffd Remove Display src in RepRapFirmware.mk
f487869 Diable SUPPORT_12864_LCD
5352406 Remove other board config, reserve FYSETC Spider only
e164053 Update FYSETC.h pins file
c704df2 Change makefile for STM32F446
074dd9e Disable CCMRAM
bc512a5 Add RepRapFirmware
ffd77a2 Add RRFLibraries
c3bf369 Add DuetWiFiSocketServer
0fa2d23 Add FreeRTOS
7b49883 Add CoreN2G
```

## Steps to use RRF

- ### Step 1: Power supply

First power on the Spider with a power supply.

- ### Step2: Bootloader

Before you use this RRF firmware, you need to follow the README here ([github](https://github.com/FYSETC/FYSETC-SPIDER/tree/main/bootloader) [gitee](https://gitee.com/fysetc/FYSETC-SPIDER/tree/main/bootloader)) to upload the bootloader `Bootloader_FYSETC_SPIDER.hex` first, boot offset is `32k` (`0x08008000`). 

- ### Step3: Pre-builds

`Pre-builds` folder contains a firmware for Spider v1.1 named `firmware1.1.bin` , boot offset is `32k` (`0x08008000`), you can start RRF by flashing this firmware to have a try（You need to flash 32k [bootloader](https://github.com/FYSETC/FYSETC-SPIDER/blob/main/bootloader/Bootloader_FYSETC_SPIDER.hex) if you flash `firmware1.1.bin` or you can just flash `firmware1.1.hex`, hex contains both bootloader and firmware. For Spider v2.2, you need `firmware2.2.hex`.

- ### Step4: config

There is `config` folder beside this README file, it is just an example config to run RRF. Copy all contents in the `config/Spider_v1.x` or `config/Spider_v2.2` folder to your sdcard root directory and insert the sdcard to Spider sdcard slot. You need to know this is just example for you to try RRF, it not for VORON or any machines. And if you make the right config for VORON, please make a PR for me, i will update it ASAP, thanks in advance. 

# Hardware

If you want to build a machine with this RRF firmware on Spider, then you have three ways to communicate with/control Spider.

## 1.USB serial

After you flash bootloader and firmware, and insert the sdcard with example config(i really recommend you to make the config yourself), you should get information from USB serial now(Of course, you need a USB cable to connect Spider to your PC). So you can control the motherboard using RRF [gcode](https://duet3d.dozuki.com/Wiki/Gcode) now.

## 2.Paneldue

Control the machine with USB serial will be a hard job, so you may need a screen to make the work easier. And i remove other lcd support in this firmware, so i recommend you to use Paneldue, you can get it from our store [here](https://www.aliexpress.com/item/4000156345741.html). You can connect it to Spider using the wiring below.![](images/paneldue.jpg)

![](images/paneldue1.jpg)

![](images/paneldue2.jpg)

## 3.Wifi module

RRF in Spider also support wifi module. You can get the module [here](https://www.aliexpress.com/item/1005003145645569.html). You can follow below steps to connect it to your wifi network.

1. Stop wifi module

   ```
   M552 s-1
   ```

   You should receive `WiFi module stopped`.

2. Start wifi module

   ```
   M552 s0
   ```

   You should receive `WiFi module started`.

3. Setup your wifi network SSID and password.

   ```
   M587 S"ssid" P"password"
   ```

   The module should connect to your wifi network in 30s.

![](images/wifi1.png)

![](images/wifi2.png)

![](images/wifi3.jpg)