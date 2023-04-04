#!/bin/bash

# dependencies installation
sudo apt install can-utils

# configuration of SPI for MCP2515
sudo cat ./config/config.txt >> /boot/config.txt

# load CAN modules in OS during boot
sudo cp ./can.conf /etc/modules-load.d/

# setting up CAN interface
sudo cat ./config/interfaces >> /etc/network/interfaces