# poliCANbent

Team Policumbent CAN Bus specification, documentation and tools.

## Raspberry Pi CAN config

The ``rpi-can-config`` subfolder contains a script that configures SocketCAN active at
start up time on the Raspberry. Moreover, in the [README](/rpi-can-config/README.md)
you will find a guide that tells you each step of the configuration procedure.

## Docs

The ``docs`` subfolder contains the specification of our CAN Bus system:
- [``IDs``](/docs/01_IDs.md) contains information regarding the IDs
- [``Nodes``](/docs/02_Nodes.md) contains the specification of the CAN nodes,
messages and signals

## DBC

The ``dbc`` subfolder contains the ``.dbc`` file(s) of our CAN system.

## Libs

The ``libs`` subfolder contains the ``.h`` and ``.c`` files exported by
[``cantools``](https://github.com/cantools/cantools) given our
[``.dbc`` file](/dbc/policanbent.dbc).