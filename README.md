# sam-fd

ATSAMC21 based CAN-FD interface

![Render of the interface PCB](hardware/sam-fd.png)

## Building

Building requires CMake and Make (e.g. GNU Make or NMake from Visual Studio). On Windows, CMake might be included with Visual Studio, but can also be installed separately. Configure and build using the commands below. On Windows you might want to use `cmake .. -G "MinGW Makefiles"` or `cmake .. -G "NMake Makefiles"` variants instead. Building bootloader and the application also requires the GNU ARM toolchain (`arm-none-eabi`).

### Building Bootloader

```sh
cd software/bootloader
mkdir build
cd build
```

Configure:
```sh
cmake .. --toolchain ../toolchain.cmake # or
cmake .. --toolchain ../toolchain.cmake -G "MinGW Makefiles" # or
cmake .. --toolchain ../toolchain.cmake -G "NMake Makefiles"
```

Build:
```sh
cmake --build .
```

### Building Application

```sh
cd software/application
mkdir build
cd build
```

Configure:
```sh
cmake .. --toolchain ../toolchain.cmake # or
cmake .. --toolchain ../toolchain.cmake -G "MinGW Makefiles" # or
cmake .. --toolchain ../toolchain.cmake -G "NMake Makefiles"
```

Build:
```sh
cmake --build .
```

### Building Flasher

```sh
cd software/flasher
mkdir build
cd build
```

Configure:
```sh
cmake .. # or
cmake .. -G "MinGW Makefiles" # or
cmake .. -G "NMake Makefiles"
```

Build:
```sh
cmake --build .
```

## Flashing

From the `software` directory, either flash using an external SWD debugger and OpenOCD using `openocd -f flash.cfg`, or flash over serial using something like the command below. On Windows, the serial port will be `COM1` or something alike instead.

```sh
flasher/build/flasher \
    /dev/ttyUSB0 \ # port to open
    application/build/application.bin # file to flash
```

## License

Please see [hardware/LICENSE](hardware/LICENSE) and [software/LICENSE](software/LICENSE). The software side of this project is based on [Atmel START](https://start.atmel.com) generated code which is mostly licensed under the [Apache-2.0](http://www.apache.org/licenses/LICENSE-2.0) license.

