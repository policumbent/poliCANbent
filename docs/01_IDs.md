# Policumbent CAN Bus Documentation - IDs

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

### Encoding

#### Message type

- ``00``: debug
- ``01``: error
- ``10``: data
<!-- - ``11``: info -->

#### From (Device/Specific)

<!-- - ``0000``: Core Raspberry Pi/Bob functionalities -->
- ``0001``: Gearbox
    - ``00001``: Greta (Cerberus gearbox receiver)
    - ``00010``: gearbox
- ``0010``: Raspberry Pi/Bob data sending
    - ``00001``: hall sensor speed / displacement
    - ``00010``: SRM powermeter power and pedals' RPM
    <!-- - ``00110``: accelerometer -->
    - ``00100``: heart-rate
- ``0100``: Miriam
    - ``00001``: GPS computed speed / displacement
    <!-- - ``00010``: GPS coordinates(?) -->
- ``1000``: Other low-priority stuff
    - ``10000``: air quality data

### Current IDs

- ``GbError``: Gearbox error message, id: ``0x222``

- ``RxGreta``: Greta receiver (Cerberus), id: ``0x421``

- ``GbData``: Gearbox data message, id: ``0x422``

- ``BobSRM``: Bob SRM, id: ``0x441``

- ``BobHS``: Bob Hall Sensor, id: ``0x442``

- ``BobHR``: Bob Heart Rate, id ``0x444``