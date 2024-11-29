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

- ``00``: debug / command
- ``01``: error
- ``10``: primary data (e.g.: on-screen data)
- ``11``: secondary data / other

#### From (Device/Specific)

<!-- - ``0000``: Core Raspberry Pi/Bob functionalities -->
- ``0001``: Gearbox
    - ``00001``: Greta (Cerberus gearbox receiver)
    - ``00010``: gearbox
    - ``00100``: refuso (gearbox feedback board)
- ``0010``: Raspberry Pi (Bob/FFS) data sending
    - ``00001``: SRM power
    - ``00010``: SRM pedals' RPM
    - ``00011``: hall sensor speed
    - ``00100``: hall sensor displacement
    - ``00110``: heart-rate
- ``0011``: whereami (GNSS)
    - ``00000``: parallel speed /distance
    - ``00010``: raw speed / distance
    - ``00100``: coordinates
    - ``01000``: position uncertainty
- ``0100``: DumBMS-1
- ``0101``: DumBMS-2 (if needed)
<!-- - ``1000``: Miriam
    - ``00001``: GPS computed speed / displacement
    - ``00010``: GPS coordinates
    - ``00100``: Air quality data: CO2 ppm / TVOC
    - ``00101``: Bike temperature
    - ``01000``: GPS altitude -->

### Current IDs

- ``RefusoData``: Refuso's potentiometer data, id: ``0x24``

- ``GretaError``: Greta receiver error (Cerberus), id: ``0x221``

- ``GbError``: Gearbox error message, id: ``0x222``

- ``Dumbms1Error``: DumBMS-1 error message, id: ``0x280``

- ``Dumbms2Error``: DumBMS-2 error message, id: ``0x2A0``

- ``GretaData``: Greta receiver data (Cerberus), id: ``0x421``

- ``GbData``: Gearbox data message, id: ``0x422``

- ``BobSrmPower``: Bob SRM Power, id: ``0x441``

- ``BobSrmCadence``: Bob SRM Cadence, id: ``0x442``

- ``BobHsSpeed``: Bob Hall Sensor Speed, id: ``0x443``

- ``BobHsDisplacement``: Bob Hall Sensor Displacement, id: ``0x444``

- ``BobHR``: Bob Heart Rate, id: ``0x446``

- ``whereamiData``: whereami parallel speed and distance: id: ``0x460``

- ``whereamiRawData``: whereami raw speed and distance: id: ``0x462``

- ``whereamiCoords``: whereami GNSS coordinates, id: ``0x464``

- ``whereamiPosUncert``: whereami GNSS position uncertainty, id: ``0x468``

- ``Dumbms1Data``: DumBMS-1 Data, id: ``0x480``

- ``Dumbms2Data``: DumBMS-2 Data, id: ``0x4A0``

<!-- - ``MiriamGpsData``: Miriam GPS computed speed and displacement, id: ``0x501``

- ``MiriamGpsCoords``: Miriam GPS coordinates (latitude, longitude), id: ``0x502``

- ``MiriamAirQuality``: Miriam air quality data (CO2 level, TVOC), id: ``0x504``

- ``MiriamTemp``: Miriam read temperature, id: ``0x505``

- ``MiriamGpsOther``: Miriam GPS altitude, id: ``0x508`` -->