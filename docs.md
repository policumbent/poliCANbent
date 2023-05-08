# Policumbent CAN Bus Documentation

## Acronyms&co

- ID: sender identification, 11bits, used also for priority
- DLC: data length code, 4bits, specifies the length in bytes of the payload
- PL: payload, 0 to 8 bytes maximum
- DT: data type
- RTR: remote transmission request

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

<!-- - ``0000``: Core Raspberry Pi/Bob functionalities -->
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
    <!-- - ``00110``: accelerometer -->
    - ``01100``: heart-rate
- ``0100``: GSM/GPS module
    - ``00000``: GPS computed speed
    - ``00001``: GPS computed displacement
    <!-- - ``00010``: GPS coordinates(?) -->
- ``1000``: Other low-priority stuff
    - ``10000``: air quality data

## Data Frames

### Debug messages

#### Init (DLC = 1):

- RPi/GSM starting communication ID type: ``0x001``

- Init request: ``0x000``

#### Init reply:

ID type: ``0b00 + device address``

- PL: ``0xFF`` -> on

- if a reply is not received in a predefined time limit, then the GSM module
writes an error

#### Raspberry Pi and GSM module init communication

These two modules can be slow in starting their functionalities, so they could
have to ask for all nodes statuses multiple times. As soon as they both write on
the bus, the GSM module will make an init request to all the nodes that will
reply with the format specified in [init reply](#init-reply).

### Data types

- Speed: DLC = 2; measurement unit: km/h; precision: 0.01

- Distance: DLC = 2; measurement unit: m; precision: 1

- RPM: DLC = 2; measurement unit: RPM; precision 0.1

- Power: DLC = 2; measurement unit: W; precision 0.1

- Heart Rate: DLC = 1; measurement unit: BPM; precision 1

- Gear: DLC = 1; measurement unit: none; precision 1

- Gear Status: DLC = 1; measurement unit: none; precision: none

- Accelerometer: <!-- understand the type of data -->

- Air Quality: <!-- understand the type of data -->

<!-- ### Core Raspberry Pi/Bob functionalities -->

### Gearbox

#### Errors (DLC: 1byte)

Send just a payload of the type ``0x00``. The payload will be ignored by the
decoder.

#### Data

- Current gear (DT: Gear)

- Gear status (DT: Gear Status)
    
    - Shifting up: ``0x0F``

    - Shifting down: ``0xF0``

    - Shift completed: ``0x00``

### Rasberry Pi/Bob

#### Data sending

- Hall sensor speed (DT: Speed)

- Hall sensor distance (DT: Distance)

- Hall sensor wheel RPM (DT: RPM)

- SRM powermeter power (DT: Power)

- SRM pedals' RPM (DT: RPM)

- Heart beat (DT: Heart Rate)

<!-- - Accelerometer -->

### GSM module

- GPS computed speed (DT: Speed)

- GPS computed distance (DT: Distance)

<!-- - GPS coordinates: to be defined -->

- Air quality (DT: Air Quality)