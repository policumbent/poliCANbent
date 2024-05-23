#!/bin/bash

# dependencies installation
sudo apt install can-utils

# configuration of SPI for MCP2515
cat ./config/config.txt | sudo tee -a /boot/firmware/config.txt

# load CAN modules in OS during boot
sudo cp ./config/can.conf /etc/modules-load.d/

# setting up CAN interface
cat ./config/interfaces | sudo tee -a /etc/network/interfaces