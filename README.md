![](images/Spider.png)

## Features

- Compact size: 155.3mm x 76.5mm
- Based on STM32F446 180Mhz，all IOs can withstand 5V voltage
- **8 TMC stepper** drivers support, with Uart&SPI support
- Improved TMC jumper settings again，simpler and easier 
- 28V input max，12V@5A DC-DC，**5V@8A DC-DC (Especially for Raspberry Pi)**，3.3V@0.8A LDO
- Two car fuses for hot bed input and main power input
- Limit switch socket 24V/5V/3.3V optional, ready for more other equipment, such as -inductive sensor, BL-Touch
- XH2.54 connectors
- 10x PWM capable power mosfet outputs (1 for HotBed, 3 for Heat-End, 3 for fans, 3 for RGB LED strip)
- 3pin temperature header, you can use thermistor or thermocouple (requires AD597 module)
- **Up to 8 ways PWM fans**  (only use 1 extrueder and no 12V/24V RGB used )，2 ways RGB led(12V & 24V optional) ，**1 way 5V-RGB led (NEO-PIXEL/WS2812)**
- RepRapDiscount SmartController compatible pin header on board
- **UART1-Raspberry Pi pin header (including 5V@8A power supply)**
- 2X4 PinHeader Out for SD Card moudle
- **Onboard micro-SD card**
- **Type-C and Type-B USB connector optional**
- EXP1 & EXP2 have more multiplexing functions, such as USART, I2C, CAN
- SD card & USB upload support

## Firmware - Klipper

You need to follow the Klipper [installation guide](https://www.klipper3d.org/Installation.html) to install [Klipper](https://github.com/KevinOConnor/klipper).

When calling "menuconfig", enable "extra low-level configuration setup" and select the "12MHz crystal" as clock reference. For flashing, write the compiled klipper.bin to memory location 0x08000000 (This is because i don't find boot address setting in Klipper , but if Klipper future update support this feature, then you can set the boot address and write the klipper.bin file to 0x08010000).

If you set the address to 0x08000000 then you can't use the Spider bootloader and you can't upload klpper.bin with sdcard.  Then you can only use DFU mode to update the firmware. Please follow [Upload the firmware(DFU)](#jump). **But you need to set the 'Start address' to 0x08000000 and Choose klipper.bin file but not firmware.bin**.

Also we have a pre-build firmware `klipper.bin` in  `firmware/Klipper` folder in this repository.  You can just use it.

And there is printer.cfg for VORON 2.4 machine , you can take it as an example.

If you can set the boot address to 0x08010000, then you can follow [Upload the firmware(SDCARD)](#jump1).

## Firmware - Marlin

#### Download Vscode + platformio

To compile the firmware , you need to install Visual Studio Code and the platformio pulg-in.

#### Download firmware

The Marlin firmware is in the `firmware/Marlin` folder in this repository , you can also get the firmware from latest [Marlin bugfix-2.0.x branch](https://github.com/MarlinFirmware/Marlin/tree/bugfix-2.0.x). You need to enable following define in ```configuration.h``` file  

```#define MOTHERBOARD BOARD_FYSETC_SPIDER```

then change the ```default_envs``` variant in ```platformio.ini``` file

```default_envs = FYSETC_SPIDER```

#### Compile the firmware

Open Vscode and open platformio main page and click the "Open Project" button , and direct to the folder where you put your firmware.

![1561099422559](images/AIO_f1.png)

If everything goes fine , at the bottom you can see several buttons

![1561099546202](images/AIO_f2.png)

The check mark is for compiling , click it to compile.

If you generate the hex file fail you may need to open vscode using Administrator Account .

#### <span id="jump1">Upload the firmware(SDCARD)</span>

We provide several ways to upload the firmware .Uploading with SD card is our default way to update the firmware as the board already has the sdcard bootloader in it when it leave the factory. There is sdcard slot at the right side of the board. 

Then,copy your compiled firmware file ```firmware.bin``` or `klipper.bin`file to the SD card , and insert it to the SD card slot, and then power up the board. You may need to wait for about 30s to finish uploading, there is LED beside the sdcard slot blinking when it is uploading. 

Note: The bootloader is in the folder named `bootloader`, please follow the README in [bootloader folder](https://github.com/FYSETC/FYSETC-SPIDER/tree/main/bootloader).

#### <span id="jump">Upload the firmware(DFU)</span>

The other way to upload the firmware is using DFU.

##### 1.Download stm32cubeprogrammer 

You can download it from ST website.

https://www.st.com/zh/development-tools/stm32cubeprog.html

Open the STM32CubeProgrammer software.

![1574332767079](images/S6_1574332767079.png)

##### 2.Enter DFU mode

First power off the board , then jumper the BT0 to 3.3V (You can find them in the middle area of the board) , then connect the USB to the board and your computer , it will enter DFU mode . Now you can take the jumper away. 

***REMEMBER to remove the jumper if you finish uploading or it will enter DFU mode again.***

##### 3.Upload the firmware

Now you can connect and flash the Spider board with stm32cubeprogrammer with the following operation.

![1574386395071](images/S6_1574386395071.png)

Do as the red number shows in the screen shot.

1. Click the button to flesh the DFU port.
2. Connect the DFU 
3. Choose the "firmware.bin" file.
4. fill in the 'Start address' with 0x8010000
5. Start Programming
## How to buy
- [FYSETC](https://www.fysetc.com/products/pre-sale-fysetc-spider-v1-0-motherboard-32bit-controller-board-tmc2208-tmc2209-3d-printer-part-replace-skr-v1-3-for-voron?variant=39404109267119)
- [Aliexpress](https://www.aliexpress.com/item/1005002324070189.html)

## Tech Support
You can submit issue in our github https://github.com/FYSETC/FYSETC-SPIDER/issues
Or submit any technical issue into our [forum](http://forum.fysetc.com/) 
