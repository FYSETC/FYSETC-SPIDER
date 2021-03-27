

## Bootloader

#### Upload the bootloader(DFU)

##### Download stm32cubeprogrammer 

You can download it from ST website.

https://www.st.com/zh/development-tools/stm32cubeprog.html

Open the STM32CubeProgrammer software.

![STM32CubeProgrammer](images/STM32CubeProgrammer.png)

##### Enter DFU mode

First power off the board , then jumper the BT0 to 3.3V (You can find them in the middle area of the board) , then connect the USB to the board and your computer , it will enter DFU mode . Now you can take the jumper away. 

***REMEMBER to remove the jumper if you finish uploading or it will enter DFU mode again.***

##### Upload the bootloader

Now you can connect and flash the Spider board with STM32CubeProgrammer with the following operation.

![Steps](images/Steps.png)

Do as the red number shows in the screen shot.

1. Click the button to flesh the DFU port.

2. Connect the DFU 

3. Choose the downloaded "Bootloader-FYSETC_SPIDER.hex" file.

6. Start Programming

**We will continue to update, please look forward to it!***

## Tech Support
You can raise issue in our github https://github.com/FYSETC/FYSETC-SPIDER/issues
Or submit any technical issue into our [forum](http://forum.fysetc.com/) 