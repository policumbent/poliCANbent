# Policumbent CAN Bus Documentation - Nodes and messages

## List of nodes

- [Gearbox](#gearbox)
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

Greta has only one type of message. Recall that it is present only on Cerberus.

- ``RxGreta`` encodes the error diagnostics message type for the gearbox
- ID: ``0x421``
- DLC: ``2``

It encodes the following signals:

| Name         | Start | Len | Factor | Offset | Min | Max | Unit | Comment |
|--------------|:-----:|:---:|:------:|:------:|:---:|:---:|:----:|---------|
| RxTimeout    | 0     | 1   | 1      | 0      | 0   | 1   | -    | The receiver is in timeout (didn't receive in a given time) |
| TelekBattery | 1     | 7   | 1      | 0      | 0   | 100 | %    | Battery percentage of Telekhambion |
| RxShifting   | 8     | 2   | 1      | 0      | 0   | 3   | -    | Shifting information received from Telekhambion |

### Raspberry Pi

The Raspberry Pi has three types of messages:
- [``BobHS``](#bobhs)
- [``BobSRM``](#bobsrm)
- [``BobHR``](#bobhr)

#### BobSRM

- ``BobSRM`` encodes the data collected by the on-board SRM Power Meter
- ID: ``0x441``
- DLC: ``4``

It encodes the following signals:

| Name       | Start | Len | Factor | Offset | Min | Max | Unit | Comment |
|------------|:-----:|:---:|:------:|:------:|:---:|:---:|:----:|---------|
| SrmPower   | 0     | 16  | 0.1    | 0      | 0   | 1000| W    | Power read by SRM Power Meter |
| SrmCadence | 16    | 16  | 0.1    | 0      | 0   | 1000| rpm  | Cadence read by SRM Power Meter |

#### BobHS

- ``BobSRM`` encodes the data collected by the on-board velocity Hall Sensor
- ID: ``0x442``
- DLC: ``4``

It encodes the following signals:

| Name       | Start | Len | Factor | Offset | Min | Max | Unit | Comment |
|------------|:-----:|:---:|:------:|:------:|:---:|:---:|:----:|---------|
| HsSpeed    | 0     | 16  | 0.01   | 0      | 0   | 200 | km/h | Speed computed by Hall Sensor |
| HsDistance | 16    | 16  | 1      | 0      | 0   | 9000| m    | Distance computed by Hall Sensor |

#### BobHR

- ``BobSRM`` encodes the data collected by the on-board velocity Hall Sensor
- ID: ``0x442``
- DLC: ``4``

It encodes the following signals:

| Name       | Start | Len | Factor | Offset | Min | Max | Unit | Comment |
|------------|:-----:|:---:|:------:|:------:|:---:|:---:|:----:|---------|
| HsSpeed    | 0     | 16  | 0.01   | 0      | 0   | 200 | km/h | Speed computed by Hall Sensor |
| HsDistance | 16    | 16  | 1      | 0      | 0   | 9000| m    | Distance computed by Hall Sensor |

### Miriam