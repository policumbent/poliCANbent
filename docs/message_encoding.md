# Policumbent CAN Message Definitions

## Acronyms&co

- ID: sender identification, 11bits, used also for priority
- DLC: data length code, 4bits, specifies the length in bytes of the payload
- PL: payload, 0 to 8 bytes maximum

## IDs

```
    type   from
0b  00   | 0000 00000
```

type:
- ``00``: debug
- ``01``: error
- ``10``: data
- ``11``: info

from:
- ``0000``: Core Raspberry Pi/Bob functionalities
- ``0001``: Gearbox
    - ``00000``: limit switch (Cerberus, different behavious for Phoenix)
    - ``00001``: receiver (Cerberus)
    - ``00010``: gearbox
- ``0010``: Raspberry Pi/Bob data sending
    - ``00000``: hall sensor speed
    - ``00001``: hall sensor displacement
    - ``00010``: hall sensor wheel RPM
    - ``00100``: SRM powermeter power
    - ``00101``: SRM pedals' RPM
    - ``01100``: heart-rate
- ``0100``: GSM/GPS module
    - ``00000``: GPS computed speed
    - ``00001``: GPS computed displacement
    <!-- - ``0010``: GPS coordinates(?) -->
- ``1000``: Other low-priority stuff

## Data Frames

### Debug messages

#### Init request (DLC = 5):

ID type: ``0x000``;

#### Init reply:

ID type: ``0b000 + device address``
- PL: ``0x8000000001`` -> on

- if a reply is not received in 5 seconds, then the Raspberry writes an error

For the GSM, the reply PL will be, in bits:

``DDDDD MMMM YYYYYYYYYYYY 00 HHHHH MMMMMM SSSSSS``

``-day- mont ----year---- -- hour- minute --sec-``

### Core Raspberry Pi/Bob functionalities

### Gearbox

#### Errors (DLC: 1byte)

- Limit switch PL: ``0x0`` (if needed)

- Greta PL: ``0x1``

#### Data

- Current gear (DLC = 1), sent only at gear change

### Rasberry Pi/Bob

#### Data sending

- Hall sensor speed (DLC = 8)

- Hall sensor displacement (DLC = 8)

- Hall sensor wheel RPM (DLC = 8)

- SRM powermeter power (DLC = 8)

- SRM pedals' RPM (DLC = 8)

- Heart beat (DLC = 1):

### GSM module

- GPS computed speed (DLC = 8)

- GPS computed displacement (DLC = 8)

<!-- - Coordinates (DLC = 8(?)): to be defined -->