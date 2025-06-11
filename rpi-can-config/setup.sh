#!/bin/bash

# dependencies installation
sudo apt install can-utils

# configuration of SPI for MCP2515
cat ./config/config.txt | sudo tee -a /boot/firmware/config.txt

# load CAN modules in OS during boot
sudo cp ./config/can.conf /etc/modules-load.d/

# setting up CAN interface
sudo systemctl start systemd-networkd
sudo systemctl enable systemd-networkd

cat ./config/interfaces | sudo tee -a /etc/systemd/network/80-can.network