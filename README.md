# sam-fd

## Building

`cd` to what you want to build:

```sh
cd software/bootloader # or
cd software/application # or
cd software/flasher
```

Configure and build using the commands below. On Windows you might want to use `cmake .. -G "MinGW Makefiles"` instead.

```sh
mkdir build
cd build
cmake ..
make
```

## Flashing

From the `software` directory, either flash using an external SWD debugger and OpenOCD using `openocd -f flash.cfg`, or flash over serial using something like the command below. On Windows, the serial port will be `COM1` or something alike instead.

```sh
flasher/build/flasher \
    /dev/ttyUSB0 \ # port to open
    application/build/application.bin # file to flash
```
