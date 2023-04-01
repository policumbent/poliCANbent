#!/bin/bash

# setting up can:
#   - bitrate: 125000
#   - loopback on
#   - restart time (if it goes down): 50ms
sudo ip link set can0 type can bitrate 125000 loopback on restart-ms 50

# enable can
sudo ip link set up can0