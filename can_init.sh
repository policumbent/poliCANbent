#!/bin/bash

sudo modprobe can
sudo modprobe can_raw

sudo ip link set can0 type can bitrate 125000 loopback on
sudo ip link set up can0