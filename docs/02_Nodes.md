# Policumbent CAN Bus Documentation - Nodes and messages

## List of nodes

- [Gearbox (Camilla)](#gearbox)
- [Greta (Cerberus' gearbox receiver)](#greta)
- [Raspberry Pi](#raspberry-pi)
- [Miriam (Telemetry ECU)](#miriam)

### Gearbox

The gearbox has two types of messages:

- [``GbError``](#gberror)
- [``GbData``](#gbdata)

We divide them due to ID priority, giving ``GbError`` higher priority since the
gearbox is the most critical ECU of our bikes. 

#### GbError

- ``GbError`` encodes the error diagnostics message type for the gearbox
- ID: ``0x222``
- DLC: ``2``

It encodes the following signals:

| Name       | Start | Len | Factor | Offset | Min | Max | Unit | Comment |
|------------|:-----:|:---:|:------:|:------:|:---:|:---:|:----:|---------|
| GbErrCode  | 0     | 3   | 1      | 0      | 0   | 7   | -    | Gearbox error code |
| GbMode     | 3     | 1   | 1      | 0      | 0   | 1   | -    | Mode (gearbox/calibration) |
| GbShifting | 4     | 2   | 1      | 0      | 0   | 3   | -    | Shifting information |
| GbGear     | 8     | 5   | 1      | 0      | 0   | 16  | -    | Current gear |

#### GbData

- ``GbData`` encodes the error diagnostics message type for the gearbox
- ID: ``0x422``
- DLC: ``1``

It encodes the following signals:

| Name       | Start | Len | Factor | Offset | Min | Max | Unit | Comment |
|------------|:-----:|:---:|:------:|:------:|:---:|:---:|:----:|---------|
| GbMode     | 0     | 1   | 1      | 0      | 0   | 1   | -    | Mode (gearbox/calibration) |
| GbShifting | 1     | 2   | 1      | 0      | 0   | 3   | -    | Shifting information |
| GbGear     | 3     | 5   | 1      | 0      | 0   | 16  | -    | Current gear |

### Greta

- [``GretaError``](#gretaerror)
- [``GretaData``](#gretadata)

Greta has two types of messages. Recall that it is present only on Cerberus.

#### GretaError

- ``GretaError`` encodes the error message type for the gearbox receiver
- ID: ``0x221``
- DLC: ``1``

It encodes the following signals:

| Name         | Start | Len | Factor | Offset | Min | Max | Unit | Comment |
|--------------|:-----:|:---:|:------:|:------:|:---:|:---:|:----:|---------|
| TimeOutError | 0     | 1   | 1      | 0      | 0   | 1   | -    | 1 if a receiver timeout has occurred |

#### GretaData

- ``GretaData`` encodes the data message type for the gearbox receiver
- ID: ``0x421``
- DLC: ``2``

It encodes the following signals:

| Name         | Start | Len | Factor | Offset | Min | Max | Unit | Comment |
|--------------|:-----:|:---:|:------:|:------:|:---:|:---:|:----:|---------|
| TelekBattery | 0     | 7   | 1      | 0      | 0   | 100 | %    | Battery percentage of Telekhambion |
| RxShifting   | 7     | 2   | 1      | 0      | 0   | 3   | -    | Shifting information received from Telekhambion |

### Raspberry Pi

The Raspberry Pi has five types of messages:
- [``BobSrmPower``](#bobsrmpower)
- [``BobSrmCadence``](#bobsrmcadence)
- [``BobHsSpeed``](#bobhsspeed)
- [``BobHsDisplacement``](#bobhsdisplacement)
- [``BobHR``](#bobhr)

#### BobSrmPower

- ``BobSrmPower`` encodes the power computed by the on-board SRM Power Meter
- ID: ``0x441``
- DLC: ``2``

It encodes the following signals:

| Name       | Start | Len | Factor | Offset | Min | Max | Unit | Comment |
|------------|:-----:|:---:|:------:|:------:|:---:|:---:|:----:|---------|
| SrmPower   | 0     | 16  | 0.1    | 0      | 0   | 1000| W    | Power read by SRM Power Meter |

#### BobSrmCadence

- ``BobSrmCadence`` encodes the pedals cadence computed by the on-board SRM Power Meter
- ID: ``0x442``
- DLC: ``2``

It encodes the following signals:

| Name       | Start | Len | Factor | Offset | Min | Max | Unit | Comment |
|------------|:-----:|:---:|:------:|:------:|:---:|:---:|:----:|---------|
| SrmCadence | 16    | 16  | 0.1    | 0      | 0   | 1000| rpm  | Cadence read by SRM Power Meter |

#### BobHsSpeed

- ``BobSRM`` encodes the data collected by the on-board velocity Hall Sensor
- ID: ``0x443``
- DLC: ``2``

It encodes the following signals:

| Name       | Start | Len | Factor | Offset | Min | Max | Unit | Comment |
|------------|:-----:|:---:|:------:|:------:|:---:|:---:|:----:|---------|
| HsSpeed    | 0     | 16  | 0.01   | 0      | 0   | 200 | km/h | Speed computed by Hall Sensor |

#### BobHsDisplacement

- ``BobHsDisplacement`` encodes the pedals cadence computed by the on-board SRM Power Meter
- ID: ``0x444``
- DLC: ``2``

It encodes the following signals:

| Name       | Start | Len | Factor | Offset | Min | Max | Unit | Comment |
|------------|:-----:|:---:|:------:|:------:|:---:|:---:|:----:|---------|
| HsDistance | 16    | 16  | 1      | 0      | 0   | 9000| m    | Distance computed by Hall Sensor |

#### BobHR

- ``BobSRM`` encodes the data collected by the on-board velocity Hall Sensor
- ID: ``0x446``
- DLC: ``1``

It encodes the following signals:

| Name       | Start | Len | Factor | Offset | Min | Max | Unit | Comment |
|------------|:-----:|:---:|:------:|:------:|:---:|:---:|:----:|---------|
| HeartRate  | 0     | 8   | 1      | 0      | 0   | 250 | bpm  | Heart rate received by Bob |

### Miriam

Miriam (currently) has two types of messages:
- [``MiriamGpsData``](#miriamgpsdata)
- [``MiriamGpsCoords``](#miriamgpscoords)

#### MiriamGpsData

- ``MiriamGpsData`` encodes the data computed by the GPS system on Miriam
- ID: ``0x481``
- DLC: ``4``

It encodes the following signals:

| Name            | Start | Len | Factor | Offset | Min | Max   | Unit | Comment |
|-----------------|:-----:|:---:|:------:|:------:|:---:|:-----:|:----:|---------|
| GpsSpeed        | 0     | 16  | 0.01   | 0      | 0   | 200   | km/h | Speed computed from GPS data |
| GpsDisplacement | 16    | 16  | 1      | 0      | 0   | 20000 | m    | Displacement computed from GPS data |

#### MiriamGpsCoords

- ``MiriamGpsCoords`` encodes the coordinates given by the GPS system on Miriam
- ID: ``0x482``
- DLC: ``8``

It encodes the following signals:

| Name         | Start | Len | Factor   | Offset | Min  | Max | Unit | Comment |
|--------------|:-----:|:---:|:--------:|:------:|:----:|:---:|:----:|---------|
| GpsLatitude  | 0     | 32  | 0.000001 | 0      | -90  | 90  | km/h | Latitude given by GPS |
| GpsLongitude | 32    | 32  | 0.000001 | 0      | -180 | 180 | m    | Longitude given by GPS |

_Notice: both the encoded signals are signed!_