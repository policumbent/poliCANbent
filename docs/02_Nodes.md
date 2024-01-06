# Policumbent CAN Bus Documentation - Nodes and messages

## List of nodes

- [Camilla (Gearbox Control Unit)](#gearbox)
- [Greta (Cerberus' gearbox receiver)](#greta)
- [Raspberry Pi](#raspberry-pi)
- [DumBMS (Battery Control Unit)](#dumbms-1-and-2)
- [Miriam (Telemetry Control Unit)](#miriam)

### Gearbox

The gearbox has two types of messages:

- [``GbError``](#gberror)
- [``GbData``](#gbdata)

We divide them due to ID priority, giving ``GbError`` higher priority since the
gearbox is the most critical ECU of our bikes. 

#### GbError

- ``GbError`` encodes the error diagnostics message type for the gearbox
- ID: ``0x222``
- DLC: ``1``

It encodes the following signals:

| Name       | Start | Len | Factor | Offset | Min | Max | Unit | Comment |
|------------|:-----:|:---:|:------:|:------:|:---:|:---:|:----:|---------|
| GbErrCode  | 0     | 3   | 1      | 0      | 0   | 7   | -    | Gearbox error code |
| GbGear     | 3     | 5   | 1      | 0      | 0   | 16  | -    | Current gear |

#### GbData

- ``GbData`` encodes the error diagnostics message type for the gearbox
- ID: ``0x422``
- DLC: ``1``

It encodes the following signals:

| Name       | Start | Len | Factor | Offset | Min | Max | Unit | Comment |
|------------|:-----:|:---:|:------:|:------:|:---:|:---:|:----:|---------|
| GbGear     | 0     | 5   | 1      | 0      | 0   | 16  | -    | Current gear |

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

### DumBMS (1 and 2)

There could be two DumBMS Control Units on the bike (especially on Cerberus) and
they have the same messages encoding (N stands for the Control Unit number):

- [``DumbmsNError``](#dumbmsnerror)
- [``DumbmsNData``](#dumbmsndata)

#### DumbmsNError

- ``DumbmsNError`` encodes the batteries undervoltage detection (if any)
- ID 1: ``0x280``
- ID 2: ``0x2A0``
- DLC: ``1``

It encodes the following signal

| Name          | Start | Len | Factor | Offset | Min | Max | Unit | Comment |
|---------------|:-----:|:---:|:------:|:------:|:---:|:---:|:----:|---------|
| Bat0UnderVolt | 0     | 1   | 1      | 0      | 0   | 1   | -    | DumBMS LiPo undervoltage detected |
| Bat1UnderVolt | 1     | 1   | 1      | 0      | 0   | 1   | -    | 3S slot 1 undervoltage detected |
| Bat2UnderVolt | 1     | 1   | 1      | 0      | 0   | 1   | -    | 3S slot 2 undervoltage detected |
| Bat3UnderVolt | 1     | 1   | 1      | 0      | 0   | 1   | -    | 3S slot 3 undervoltage detected |
| Bat4UnderVolt | 1     | 1   | 1      | 0      | 0   | 1   | -    | 3S slot 4 undervoltage detected |

#### DumbmsNData

- ``DumbmsNData`` encodes the batteries voltages
- ID 1: ``0x480``
- ID 2: ``0x4A0``
- DLC: ``5``

| Name        | Start | Len | Factor | Offset | Min | Max | Unit | Comment |
|-------------|:-----:|:---:|:------:|:------:|:---:|:---:|:----:|---------|
| Bat0Voltage | 0     | 8   | 0.1    | 0      | 0   | 1   | -    | DumBMS LiPo voltage |
| Bat1Voltage | 8     | 8   | 0.1    | 0      | 0   | 1   | -    | 3S slot 1 voltage   |
| Bat2Voltage | 16    | 8   | 0.1    | 0      | 0   | 1   | -    | 3S slot 2 voltage   |
| Bat3Voltage | 24    | 8   | 0.1    | 0      | 0   | 1   | -    | 3S slot 3 voltage   |
| Bat4Voltage | 32    | 8   | 0.1    | 0      | 0   | 1   | -    | 3S slot 4 voltage   |

### Miriam

Miriam (currently) has two types of messages:
- [``MiriamGpsData``](#miriamgpsdata)
- [``MiriamGpsCoords``](#miriamgpscoords)
- [``MiriamAirQuality``](#miriamairquality)
- [``MiriamTemp``](#miriamtemp)
- [``MiriamGpsOther``](#miriamgpsother)

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

#### MiriamAirQuality

- ``MiriamAirQuality`` encodes the air quality data read by the sensor connected
to Miriam
- ID: ``0x484``
- DLC: ``8``

It encodes the following signals:

| Name     | Start | Len | Factor  | Offset | Min  | Max  | Unit  | Comment |
|----------|:-----:|:---:|:-------:|:------:|:----:|:----:|:-----:|---------|
| CO2Level | 0     | 32  | 0.00001 | 0      | 200  | 3000 | ppm   | C02 level (in ppm) in the bike |
| TVOC     | 32    | 32  | 0.00001 | 0      | 0    | 4000 | level | TVOC level in the bike |

#### MiriamTemp

- ``MiriamTemp`` encodes the temperature read by the sensor connected to Miriam
- ID: ``0x485``
- DLC: ``2``

It encodes the following signals:

| Name        | Start | Len | Factor | Offset | Min  | Max  | Unit | Comment |
|-------------|:-----:|:---:|:------:|:------:|:----:|:----:|:----:|---------|
| Temperature | 0     | 16  | 0.01   | 0      | 0    | 60   | °C   | Temperature inside the bike |

#### MiriamGpsOther

- ``MiriamGpsOther`` encodes the altitude given by the GPS system on Miriam
- ID: ``0x488``
- DLC: ``2``

It encodes the following signals:

| Name     | Start | Len | Factor | Offset | Min  | Max  | Unit | Comment |
|----------|:-----:|:---:|:------:|:------:|:----:|:----:|:----:|---------|
| Altitude | 0     | 16  | 1      | 0      | 0    | 3000 | m    | Altitude computed by the GPS |