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
    - ``00001``: SRM power
    - ``00010``: SRM pedals' RPM
    - ``00011``: hall sensor speed
    - ``00100``: hall sensor displacement
    <!-- - ``00110``: accelerometer -->
    - ``00110``: heart-rate
- ``0100``: Miriam
    - ``00001``: GPS computed speed / displacement
    - ``00010``: GPS coordinates
- ``1000``: Other low-priority stuff
    - ``10000``: air quality data

### Current IDs

- ``GretaError``: Greta receiver error (Cerberus), id: ``0x221``

- ``GbError``: Gearbox error message, id: ``0x222``

- ``GretaData``: Greta receiver data (Cerberus), id: ``0x421``

- ``GbData``: Gearbox data message, id: ``0x422``

- ``BobSrmPower``: Bob SRM Power, id: ``0x441``

- ``BobSrmCadence``: Bob SRM Cadence, id: ``0x442``

- ``BobHsSpeed``: Bob Hall Sensor Speed, id: ``0x443``

- ``BobHsDisplacement``: Bob Hall Sensor Displacement, id: ``0x444``

- ``BobHR``: Bob Heart Rate, id ``0x446``

- ``MiriamGpsData``: Miriam GPS computed speed and displacement, id: ``0x481``

- ``MiriamGpsCoords``: Miriam GPS coordinates (latitude, longitude), id: ``0x482``