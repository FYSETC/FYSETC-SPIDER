# Bootloader

Before you use this RRF firmware, you need to upload the bootloader firmware here first. 

# Firmware

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

# Pre-builds

This folder contains a firmware named `firmware.bin` , you can start RRF by flashing this firmware to have a try.

# config

There is `config` folder beside this README file, it is just an example config to run RRF. Copy all contents in the `config` folder to your sdcard root directory. You need to know this is just example for you to try RRF, it not for VORON or any machines. And if you make the right config for VORON, please make a PR for me, i will update it ASAP, thanks in advance. 

