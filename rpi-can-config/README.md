# Raspberry Pi CAN configuration

In this README you will find:
- [Automatic setup](#automatic-setup)
- [Manual setup](#manual-setup)
- [Testing](#testing)
- [Troubleshooting](#troubleshooting)
- [Other useful resources](#other-useful-resources)

## MCP2515 SPI-to-CAN module pinout

| RPi Pin | RPi Label | CAN Module |
|:-------:|:---------:|:----------:|
| 17 	    | 3.3V      | VCC |
| 20 	    | GND       | GND |
| 19 	    | GPIO10    | MOSI (SI) |
| 21 	    | GPIO9     | MISO (SO) |
| 22 	    | GPIO25    | INT |
| 23 	    | GPIO11    | SCK |
| 24 	    | GPIO8     | CS |


[Useful website for Raspberry Pi pinout](https://pinout.xyz/#)

## Automatic setup

Run ```setup.sh```: every command is explained in this README.

## Manual setup

### Installing dependencies

```sudo apt install can-utils```

### Configure SPI for MCP2515

Append the following lines in ```/boot/firmware/config.txt```:

```
### SPI ###
dtparam=spi=on

### CAN-BUS overlay ###
dtoverlay=mcp2515-can0,oscillator=16000000,interrupt=25
dtoverlay=spi-bcm2835
```

### Load CAN modules in OS during boot

Copy the file ```can.conf``` in ```/etc/modules-load.d/```

### Enable CAN interface

Append the following lines in ```/etc/systemd/network/80-can.network```

```bash
[Match]
Name=can0

[CAN]
BitRate=500K
RestartSec=100ms
```

## Testing

For testing the CAN connectivity, first of all you should check the output of
``ifconfig``. If it shows a CAN interface running, you should be all good on the
Raspberry side, if it doesn't, check the [troubleshooting section](#troubleshooting).

### Testing the Raspberry Pi alone

_Note: this will test only the Raspberry-MCP2515 connection, without considering
the transceiver and, therefore, the CAN Bus itself._

You will need two tty sessions, it is possible connecting your PC to the
Raspberry both with [UART](https://github.com/policumbent/coltellino-svizzero/blob/main/debug-tools/raspberry_pi.md#uart)
and [SSH](https://github.com/policumbent/coltellino-svizzero/blob/main/debug-tools/raspberry_pi.md#ssh)
at the same time.

On one session you have to run:
```Bash
candump can0
```

And on the other you can send messages:
```Bash
cansend can0 000#11223344
```

On the ``candump`` session, if everything is working correctly, you should see:
```
  can0  000   [4]  11 22 33 44
```

If it's not, check the [troubleshooting section](#troubleshooting)

### Testing the Raspberry Pi with another CAN node

You can connect a CAN node on the bus, so that you can test also the CAN Bus
itself. In order to do that, in this repo it is included a Platformio project
in the ``esp-can-test`` folder. It periodically sends data and prints on the
serial output the data that it receives.

_Note: to avoid issues with VSCode and Platformio, you should open that folder
with another window of VSCode, **not** accessing it having as project root this
repository._

## Troubleshooting

When you connect the hardware CAN Interface to the Raspberry Pi, you can use the
command ``ifconfig`` to check whether the Raspberry has correctly initialized
SocketCAN and connected to the MCP2515. If no CAN interface is showed in
``ifconfig``, something went wrong.

### Check if CAN modules are loaded in the OS

In order to check if the SocketCAN OS modules are loaded, run this command:
```Bash
lsmod | grep "can"
```

If the modules are correctly loaded, you should see the following:
```
can_raw     ######  0
can         ######  1 can_raw
can_dev     ######  1 mcp251x
```

### Check SPI connection between the RPi and the MCP2515

To check the SPI connection between the Raspberry and the MCP2515 run:
```Bash
dmesg | grep "spi"
```

If it shows only the following message, the MCP2515 is connected correctly:
```
[   ##.######] mcp251x spi0.0 can0: MCP2515 successfully initialized.
```

In the case of an error message is shown, there probably is some physical
connection failure. Anyway, it can show several error codes, in order to
understand them, it can be convenient to Google them.

In the following example, ``error -110`` means a timeout error.
```
[   ##.######] mcp251x spi0.0: MCP251x didn't enter in conf mode after reset
[   ##.######] mcp251x spi0.0: Probe failed, err=110
[   ##.######] mcp251x: probe of spi0.0 failed with error -110
```

In some cases, it can show the ``successfully initialized`` message, followed by
an error. Usually, by empirical experience, it happens when the connection
between the MCP2515 and the transceiver is not working, so in that case you should
check the physical connection between the two integrated circuits or the
powering of the transceiver.

_Note: if you modify something, you should reboot the system in order to restart
SPI and see the results of your changes._ To avoid that, you can "restart" the
SPI OS module:

1. Find the name of the SPI module

   ``spi_bcm2835`` is the name of the SPI OS module on the newest Raspberry's,
   please check if you Raspberry has a different module, you can do that performing
   the following:

   ```Bash
   lsmod | grep "spi"
   ```

   As a result, you will find the SPI module listed with ``lsmod``.

1. Remove and re-add the module (assuming that the name is ``spi_bcm2835``,
   otherwise change it with the result of the previous point):

   ```Bash
   rmmod spi_bcm2835
   modprobe spi_bcm2835
   ```

## Other useful resources

A collection of resources that have been used when working with CAN on the
Raspberry Pi. Some mistakes have been noted in the links, so, please, be careful
and use this README before checking them.

- [How to connect Raspberry Pi to CAN Bus](https://www.hackster.io/youness/how-to-connect-raspberry-pi-to-can-bus-b60235)
- [CAN communication on the Raspberry PI with SocketCAN](https://www.pragmaticlinux.com/2021/10/can-communication-on-the-raspberry-pi-with-socketcan/)
- [Automatically bring up a SocketCAN interface on boot](https://www.pragmaticlinux.com/2021/07/automatically-bring-up-a-socketcan-interface-on-boot/)
- [Raspberry Pi - (Solved) Not able to setup can0](https://forums.raspberrypi.com/viewtopic.php?t=311606)
- [SPI Reset on Raspberry Pi](https://stackoverflow.com/questions/37698895/spi-reset-on-raspberry-pi-after-gpio-usage#40066584)
