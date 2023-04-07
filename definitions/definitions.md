# Policumbent CAN ID and messages encoding

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
- ```000```: error
- ```001```: init
- ```010```: data
- ```100```: info(?)

from:
- ``0000``: Core Raspberry Pi/Bob functionalities
- ``0001``: Gearbox
    - ``0000``: limit switch
    - ``0001``: receiver (Cerberus)
    - ``0010``: gearbox
- ``0010``: GSM module
- ``0100``: Raspberry Pi/Bob data sending
- ``1000``: Other low-priority stuff

## Data Frames

### Data requests

#### Init request:
ID type: ``0x100``; DLC: 1

#### Init reply:
ID type: ``0b100 + device address``
- PL: ``0x81`` -> on
- PL: ``0x80`` -> off -> error

### Core Raspberry Pi/Bob functionalities

### Gearbox

### GSM module

### RPi/Bob data sending