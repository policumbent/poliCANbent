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
    - ``0001``: GPS data
- ``1000``: Other low-priority stuff

## Data Frames

### Debug messages

#### Init request:
ID type: ``0x000``; DLC: 1

#### Init reply:
ID type: ``0b000 + device address``
- PL: ``0x81`` -> on
- if reply is not received in 5 seconds, then the Raspberry writes an error

### Core Raspberry Pi/Bob functionalities



### Gearbox

### GSM module

### RPi/Bob data sending