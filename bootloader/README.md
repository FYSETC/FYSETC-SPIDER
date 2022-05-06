

# Bootloader

Bootloader is the boot program, which is a code placed at the beginning of the flash space of the motherboard storage. The main function is to make the motherboard have the function to flash firmware with sdcard. Due to historical reasons, we provide two versions of bootloader, namely 32k bootloader `Bootloader_FYSETC_SPIDER.hex` and 64k bootloader `Bootloader_FYSETC_SPIDER_10000.hex`,

But from 2021/06/23, the 64k bootloader is no longer used, and the new spider motherboard comes with 32k bootloader. However, because the old motherboard (factory before 2021/06/23) comes with a 64k bootloader, for compatibility, a 64k bootloader is still provided here. It is recommended that the old motherboard can be updated to 32k bootloader according to the instructions below.

We provide two methods to upload the bootloader.

## Method 1 : stm32cubeprogrammer

This method only works in windows.

### Step 1: Download stm32cubeprogrammer 


You can download it from ST website.

https://www.st.com/zh/development-tools/stm32cubeprog.html

Open the STM32CubeProgrammer software.

![STM32CubeProgrammer](images/STM32CubeProgrammer.png)

### Step 2: Enter DFU mode


1. First power off the board
2. Set jumper on 5v pin and DC5V ![](../images/5vJumper.png)
3. Place jumper on BT0 to 3.3V pin ![](../images/boot.png)
4. Connect USB cable to the board and your computer 
5. Power up the board with 24v 

Now the board is in DFU mode. 

***REMEMBER to remove the jumper if you finish uploading firmware or it will enter DFU mode again.***

### Step 3: Upload the bootloader


Now you can connect and flash the Spider board with STM32CubeProgrammer with the following operation.

![Steps](images/Steps.png)

Do as the red number shows in the screen shot.

1. Click the button to find the DFU port.
2. Connect the DFU 
3. Choose the downloaded "Bootloader-FYSETC_SPIDER.hex" file. (If 64k bootloader,choose `Bootloader_FYSETC_SPIDER_10000.hex`). 
4. Start Programming

**We will continue to update, please look forward to it!***

## Method 2: dfu-util 

This method works in linux, works in raspberry pi. ***According to community members feedbacks, someone runs into klipper no connection with Spider. If you run into this situration, please use method 1 instead.***

1. Make sure dfu-util is installed, shoot `dfu-util --version` command to check.

   Sample output:

   ```
   dfu-util 0.9
   
   Copyright 2005-2009 Weston Schmidt, Harald Welte and OpenMoko Inc.
   Copyright 2010-2016 Tormod Volden and Stefan Schmidt
   This program is Free Software and has ABSOLUTELY NO WARRANTY
   Please report bugs to http://sourceforge.net/p/dfu-util/tickets/
   ```

   If not , you should install it first, use the package manager of your distribution to get the latest version, like

   ```
   sudo apt-get install dfu-util
   ```

2. Power off board, remove SD Card, place jumper on BT0 and 3.3V. (Between Z- endstop and E0 driver) Connect Spider to Pi with USB cable with jumper in place. Set U5V jumper closest to stepper driver modules to power Spider from the Pi USB. Verify 3.3V LED is lit and board is detected with `dfu-util --list`, should look something like

   ```
   <snip>
   Found DFU: [0483:df11] ver=2200, devnum=13, cfg=1, intf=0, path="1-1.3", alt=3, name="@Device Feature/0xFFFF0000/01*004 e", serial="STM32FxSTM32"
   Found DFU:<snip>
   ```

3. ```
   wget https://github.com/FYSETC/FYSETC-SPIDER/raw/main/bootloader/Bootloader_FYSETC_SPIDER.hex
   ```

4. ```
   objcopy --input-target=ihex --output-target=binary Bootloader_FYSETC_SPIDER.hex Bootloader_FYSETC_SPIDER.bin && dfu-util -a 0 -s 0x08000000:mass-erase:force -D Bootloader_FYSETC_SPIDER.bin
   ```

## Tech Support

You can raise issue in our github https://github.com/FYSETC/FYSETC-SPIDER/issues
Or submit any technical issue into our [forum](http://forum.fysetc.com/) 