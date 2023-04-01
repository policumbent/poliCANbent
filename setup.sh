#!/bin/bash

sudo apt install can-utils

sudo cat ./config/mcp2515-spi.txt >> /boot/config.txt

sudo cp ./can.conf /etc/modules-load.d/

sudo systemctl start systemd-networkd
sudo systemctl enable systemd-networkd

sudo cp ./config/80-can.network /etc/systemd/network/

sudo systemctl restart systemd-networkd