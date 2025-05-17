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

To visualize (and, occasionally, to modify) the ``.dbc`` file, you can use
[this ``.dbc`` online editor](https://www.csselectronics.com/pages/dbc-editor-can-bus-database).

## Libs

The ``libs`` subfolder contains the ``.h`` and ``.c`` files exported by
[``cantools``](https://github.com/cantools/cantools) given our
[``.dbc`` file](/dbc/policanbent.dbc).

In order to use these libraries, you have to copy them in the project that needs
them. In doing so, you can access the generated functions just importing the
``.h`` file in your source code and compiling it with the ``.c`` of the library.

## Plotting logs

For plotting some of the signals in a CAN log, it is possible to use the
following command:
```bash
cat <path-to-log> | python -m cantools plot ./dbc/policanbent.dbc -- --ylabel '<Label 1>' '<MsgName1.SignalName1>' - <...> - --ylabel '<Label N>' '<MsgNameN.SignalNameN>'
```