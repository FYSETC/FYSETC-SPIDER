# Switch RPI hardware uart

If you want to connect Spider UART1(RX1:PA10, TX1:PA9) port to RPI  uart0(TX:GPIO14,RX:GPIO15) port, you need to follow this.

## Step 1 : Wiring

Please wiring as below shows.

![](cable.jpg)

## Step 2 : Switch raspberryPI uart

There are 2 methods for you to do this.

### Method 1

Enter RPI system first with `SSH` utility. We are going to switch RPI hardware uart to `GPIO14/GPIO15`. You need to edit the following line in `/boot/config.txt` file

```
sudo nano /boot/cmdline.txt
```

remove the word phase "console=serial0,115200" or "console=ttyAMA0,115200", then

```
sudo reboot
```

Then enter RPI system again.

```
sudo raspi-config
```

=> Interfacing Option

=> Serial

=> NO

=> YES

=> Ok

=> Finish

=> Yes

After reboot, enter RPI system again

```
sudo nano /boot/config.txt
```

Add the following line to the end of the file

```
dtoverlay=pi3-disable-bt
```

Then reboot again.

```
sudo reboot
```

Done.

### Method 2

This method is from community member, not tested well yet.

```
sudo raspi-config nonint do_serial 2 
echo dtoverlay=pi3-disable-bt | sudo tee -a /boot/config.txt 
sudo reboot 
```

