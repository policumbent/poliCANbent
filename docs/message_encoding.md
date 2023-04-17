# Policumbent CAN Message Definitions

## Acronyms&co

- ID: sender identification, 11bits, used also for priority
- DLC: data length code, 4bits, specifies the length in bytes of the payload
- PL: payload, 0 to 8 bytes maximum

## IDs

```
    type   from
0b  000  | 0000 0000
```

type:
- ```000```: debug
- ```001```: error
- ```010```: data
- ```100```: info

from:
- ``0000``: Core Raspberry Pi/Bob functionalities
- ``0001``: Gearbox
    - ``0001``: limit switch (Cerberus, different behavious for Phoenix)
    - ``0010``: receiver (Cerberus)
    - ``0100``: gearbox
- ``0010``: Raspberry Pi/Bob data sending
    - ``0001``: hall sensor (velocity, position, wheel RPM)
    - ``0010``: SRM powermeter (power, pedals' RPM)
    - ``0100``: heart-rate
- ``0100``: GSM/GPS module
    - ``0001``: GPS computed displacement and speed
    - ``0010``: GPS coordinates
- ``1000``: Other low-priority stuff

## Data Frames

### Debug messages

#### Init request:
ID type: ``0x000``; DLC: 1

#### Init reply:
ID type: ``0b000 + device address``
- PL: ``0x81`` -> on
- if a reply is not received in 5 seconds, then the Raspberry writes an error

For the GSM, the reply PL will be, in bits (DLC = 5, do not consider spaces):

``DDDDD MMMM YYYYYYYYYYYY 00 HHHHH MMMMMM SSSSSS``

``-day- mont ----year---- -- hour- minute --sec-``

### Core Raspberry Pi/Bob functionalities

### Gearbox

#### Errors (DLC: 1byte)

- Limit switch PL: ``0x0`` (if needed)
- Greta PL: ``0x1``

#### Data (DLC: 1byte)

- Changed gear: ``hex(current_gear)``

### Rasberry Pi/Bob data sending

- Hall sensor (DLC = 4):

    ``DDDDDDDDDDDDDD 0 SSSSSSSS 0 RRRRRRRR``

    ``-displacement- - --speed- - -w_rpm--``

- SRM (DLC = 3):

    ``00 PPPPPPPPPP 00 RRRRRRRR 00``

    ``-- ---power-- -- --p_rpm- --``

- Heart beat (DLC = 1):

    ``BBBBBBBB``

    ``---bpm--``

### GSM module

- Coordinates (DLC = 8(?)):
- Displacement and speed (DLC = 3):
    
    ``DDDDDDDDDDDDDD 00 SSSSSSSS``
    
    ``-displacement- -- --speed-``