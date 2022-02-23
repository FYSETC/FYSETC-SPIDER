# 固件指南

## 固件修改

我们提供的固件是基于 [gloomyandy/RRFBuild at v3.3-dev (github.com)](https://github.com/gloomyandy/RRFBuild/tree/v3.3-dev) 修改而成。由于原始固件大小超过蜘蛛主控的 512k flash 空间，所以我们进行了一些裁剪，裁剪的内容如下所示。你可以在 `Patches` 文件夹下查看具体的修改。

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

## 使用 RRF 固件的步骤

- ### 第一步：上电 24V

首先我们给蜘蛛主板连接 24V 电源进行上电。

- ### 第二步：上传 Bootloader

在你开始使用 RRF 固件之前，你需要先根据这里 ([github](https://github.com/FYSETC/FYSETC-SPIDER/tree/main/bootloader) [gitee](https://gitee.com/fysetc/FYSETC-SPIDER/tree/main/bootloader)) 的说明来上传 32k Bootloader `Bootloader_FYSETC_SPIDER.hex`.

- ### 第三步：上传预编译固件

`Pre-builds` folder contains a firmware for Spider v1.1 named `firmware1.1.bin` , boot offset is `32k` (`0x08008000`), you can start RRF by flashing this firmware to have a try（You need to flash 32k [bootloader](https://github.com/FYSETC/FYSETC-SPIDER/blob/main/bootloader/Bootloader_FYSETC_SPIDER.hex) if you flash `firmware1.1.bin` or you can just flash `firmware1.1.hex`, hex contains both bootloader and firmware. For Spider v2.2, you need `firmware2.2.hex`.

`Pre-builds` 文件夹包含了给 Spider v1.1 的 RRF 固件 `firmware1.1.bin`，你也可以烧录 `firmware1.1.hex` 文件那么第二步就不用做了，`firmware.hex` 已经包含了 bootloader 在内，对于 Spider v2.2 版本，你需要烧录 `firmware2.2.hex` 。请根据这里（[github](https://github.com/FYSETC/FYSETC-SPIDER#44--firmware-upload) [gitee](https://gitee.com/fysetc-mirrors/FYSETC-SPIDER/tree/main#44--firmware-upload)）的说明上传固件。

- ### 第四步：固件配置

这个目录里有一个 `config`文件夹，里面是用来跑 RRF 需要的配置文件，你需要根据你主板的版本将对应的配置文件夹下（`config/Spider_v1.x` 或者`config/Spider_v2.2`）的所有内容拷贝到你的 SD 卡根目录中，并将 SD 卡插入蜘蛛 SD 卡槽。这个配置不是针对任何机型的，所以你需要根据自己的机器更改里面的配置。

# 硬件指南

If you want to build a machine with this RRF firmware on Spider, then you have three ways to communicate with/control Spider.

如果你想要组装一台用蜘蛛主板运行 RRF 固件的机器，我们有三种方式与这台机器进行交互。

## 方式1. USB serial

你上传完 bootloader 和固件之后，也插入带有配置文件的 SD 卡，机器启动之后，你只需要用 USB 线连接蜘蛛主板和你的电脑，你就可以发 RRF [gcode](https://duet3d.dozuki.com/Wiki/Gcode)  来控制你的机器了，当然你需要用一些串口工具软件来发送命令，请百度串口工具，自行下载一个。

## 方式2. Paneldue

如果要通过上面的方式1通过发送命令来控制机器，机器用起来就太困难了。所以你需要一个屏幕来控制机器。我们在裁剪 RRF 固件的时候去掉了 lcd 屏幕的支持，但是 Paneldue 屏幕是可以使用的，你可以在我们的店铺中找到这个 Paneldue 屏幕，如下图这样连接屏幕即可。

![](images/paneldue.jpg)

![](images/paneldue1.jpg)

![](images/paneldue2.jpg)

## 方式3. Wifi 模块

我们的 RRF 固件也支持 wifi 模块，如下图所示。你可以根据下面的步骤来连接你的网络。首先你必须能用方式1 发送命令，然后安装好 wifi 模块，如下面图3所示。然后我们通过发送命令来进行网络连接。

1. 先停止 wifi 模块

   ```
   M552 s-1
   ```

   You should receive `WiFi module stopped`.

2. 启动 wifi 模块

   ```
   M552 s0
   ```

   这一步里你应该会收到 `WiFi module started` 的串口信息.

3. 然后用下面的命令来设定你网络的 SSID 和密码

   ```
   M587 S"ssid" P"password"
   ```

   wifi 模块大概需要花 30s 左右连接你的网络，具体时间根据你的网络状况定. 连接完成后，你可以在串口中看到 ip 地址，用这个地址浏览器访问即可。

![](images/wifi1.png)

![](images/wifi2.png)

![](images/wifi3.jpg)