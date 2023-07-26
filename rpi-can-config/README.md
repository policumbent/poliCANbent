# Raspberry Pi CAN configuration

## MCP2515 SPI-to-CAN module pinout


| RPi Pin | RPi Label | CAN Module |
|:-------:|:---------:|:----------:|
| 17 	  | 3.3V      | VCC |
| 20 	  | GND       | GND |
| 19 	  | GPIO10    | MOSI (SI) |
| 21 	  | GPIO9     | MISO (SO) |
| 22 	  | GPIO25    | INT |
| 23 	  | GPIO11    | SCK |
| 24 	  | GPIO8     | CS |


[Useful website for Raspberry Pi pinout](https://pinout.xyz/#)

## Automatic setup

Run ```setup.sh```: every command is explained in this README.

## Manual setup

### Installing dependencies

```sudo apt install can-utils```

### Configure SPI for MCP2515

Append the following lines in ```/boot/config.txt```:

```
### SPI ###
dtparam=spi=on

### CAN-BUS overlay ###
dtoverlay=mcp2515-can0,oscillator=8000000,interrupt=25
dtoverlay=spi-bcm2835
```

### Load CAN modules in OS during boot

Copy the file ```can.conf``` in ```/etc/modules-load.d/```

### Enable CAN interface

Append the following lines in ```/etc/network/interfaces```

```
auto can0
iface can0 can static
	bitrate 500000
```