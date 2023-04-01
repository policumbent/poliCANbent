#!/bin/bash

# dependencies installation
sudo apt install can-utils

# configuration of SPI for MCP2515
sudo cat ./config/mcp2515-spi.txt >> /boot/config.txt

# load CAN modules in OS during boot
sudo cp ./can.conf /etc/modules-load.d/

# start and enable systemd-networkd
sudo systemctl start systemd-networkd
sudo systemctl enable systemd-networkd

# configuration for CAN network
sudo cp ./config/80-can.network /etc/systemd/network/

# restart systemd-networkd
sudo systemctl restart systemd-networkd