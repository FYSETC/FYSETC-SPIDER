

## Bootloader

You can follow the following steps to upload the bootloader to Spider.

- ##### Download stm32cubeprogrammer 


You can download it from ST website.

https://www.st.com/zh/development-tools/stm32cubeprog.html

Open the STM32CubeProgrammer software.

![STM32CubeProgrammer](images/STM32CubeProgrammer.png)

- ##### Enter DFU mode


1. First power off the board
2. Then close BT0 to 3.3V pin (You can find them in the middle area of the board)  with a jumper
3. Connect USB cable to the board and your computer 
4. Power up the board

Now the board is in DFU mode. 

***REMEMBER to remove the jumper if you finish uploading firmware or it will enter DFU mode again.***

- ##### Upload the bootloader


Now you can connect and flash the Spider board with STM32CubeProgrammer with the following operation.

![Steps](images/Steps.png)

Do as the red number shows in the screen shot.

1. Click the button to find the DFU port.
2. Connect the DFU 
3. Choose the downloaded "Bootloader-FYSETC_SPIDER.hex" file.
4. Make sure "Start address" is 0x8000000.
5. Start Programming

**We will continue to update, please look forward to it!***

## Tech Support
You can raise issue in our github https://github.com/FYSETC/FYSETC-SPIDER/issues
Or submit any technical issue into our [forum](http://forum.fysetc.com/) 