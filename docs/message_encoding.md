# Policumbent CAN Message Definitions

## Acronyms&co

- ID: sender identification, 11bits, used also for priority
- DLC: data length code, 4bits, specifies the length in bytes of the payload
- PL: payload, 0 to 8 bytes maximum
- DT: data type

## IDs

```
    type   from
0b  00   | 0000 00000
```

### Message type

- ``00``: debug
- ``01``: error
- ``10``: data
- ``11``: info

### From (Device/Specific)

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
    <!-- - ``00010``: GPS coordinates(?) -->
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

### Data types

- Speed: DLC = 2; measurement unit: km/h; precision: 0.01

- Distance: DLC = 2; measurement unit: m; precision: 1

- RPM: DLC = 2; measurement unit: RPM; precision 0.1

- Power: DLC = 2; measurement unit: W; precision 0.1

- Heart Rate: DLC = 1; measurement unit: BPM; precision 1

- Gear: DLC = 1; measurement unit: none; precision 1

### Core Raspberry Pi/Bob functionalities

### Gearbox

#### Errors (DLC: 1byte)

- Limit switch PL: ``0x0`` (if needed)

- Greta PL: ``0x1``

#### Data

- Current gear (DT: Gear)

### Rasberry Pi/Bob

#### Data sending

- Hall sensor speed (DT: Speed)

- Hall sensor distance (DT: Distance)

- Hall sensor wheel RPM (DT: RPM)

- SRM powermeter power (DT: Power)

- SRM pedals' RPM (DT: RPM)

- Heart beat (DT: Heart Rate)

### GSM module

- GPS computed speed (DT: Speed)

- GPS computed distance (DT: Distance)

<!-- - Coordinates (DLC = 8(?)): to be defined -->