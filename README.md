# Raspberry Pi CAN configuration

## MCP2515 SPI-to-CAN module pinout

```
RPi Pin    RPi Label     CAN Module
17---------3.3V----------VCC
20---------GND-----------GND
19---------GPIO10--------MOSI (SI)
21---------GPIO9---------MISO (SO)
22---------GPIO25--------INT
23---------GPIO11--------SCK
24---------GPIO8---------CS
```

## Automatic setup

Run ```setup.sh```: every command is explained in this README.

## Manual setup

### Installing dependencies

```sudo apt install can-utils```

### Configure SPI for MCP2515

Copy the following lines in ```/boot/config.txt```:

```
### SPI ###
dtparam=spi=on

### CAN-BUS overlay ###
dtoverlay=mcp2515-can0,oscillator=8000000,interrupt=25
dtoverlay=spi-bcm2835
```

### Load CAN modules in OS during boot

Copy the file ```can.conf``` in ```/etc/modules-load.d/```

### Enable ```systemd-networkd``` and CAN

CAN has to be managed by ```systemd-networkd```, which, usually, is not enabled
by default. In order to enable it run the following commands:

```Bash
$ sudo systemctl start systemd-networkd
$ sudo systemctl enable systemd-networkd
```

Then, copy the file ```80-can.network``` in ```/etc/systemd/network/``` and run
the command ```sudo systemctl restart systemd-networkd```