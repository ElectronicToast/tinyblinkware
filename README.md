# tinyblinkware
![travis](https://api.travis-ci.org/ElectronicToast/tinyblinkware.svg?branch=master) ![license](https://img.shields.io/github/license/electronictoast/tinyblinkware)

Firmware for TinyBlink ATtiny85-based LED keychain PCBs

## Description

TinyBlink series of printed circuit board (PCB) keychains, which currently includes [RuddBlink](https://github.com/ElectronicToast/ruddblink) and [MoleBlink](https://github.com/ElectronicToast/moleblink). TinyBlink is based on Atmel's ATtiny85 MCU, driving the ubiquitous 74HC595 shift register connected to 8 LEDs. 

This repository contains avr-gcc firmware for TinyBlink.

## Motivation

TinyBlink began as a personal project by Ray, an electrical engineering student at Caltech, to address the following questions

- Can a PCB keychain be compact, aesthetic, inexpensive, and easy to solder by hand, all at once?
- Can you, as a student or hobbyist, encourage those without electronics background to learn basic electronics skills?
- What can you do with 8 kB of flash and 512 B of SRAM?

as well as a means of learning AVR C development.

TinyBlinkWare provides a full C API for development of LED pattern code on TinyBlink.

## Overview

The API consists of

- `hal/` - A hardware abstraction layer (HAL) for the TinyBlink hardware
- `middleware/` - TinyBlink middleware drivers, for e.g. animations
- `app/` - Application specific code and pattern data

A main loop exercising various features of the API for pattern generation, animation display, and brightness control is present.

## Building

### Windows

#### Atmel Studio

1. Install Atmel Studio 7.0
2. Install AVRDUDE. You can also use an Arduino installation.
3. Open the `tinyblinkware.atsln` project solution file
4. In Atmel Studio, under `Tools` -> `External Tools`, add the appropriate executable and command for flashing a hex file with the name `$(ProjectDir)Debug\$(TargetName).hex` with AVRDUDE and your AVR programmer. This assumes that you are the default Debug configuration in Atmel Studio. If you wish to use a different configuration, be sure to change the name of the hex file.
5. `Build` -> `Build Solution` to compile
6. To flash, first ensure that TinyBlink is connected to your computer through your AVR programmer. Under `Tools`, select the external tool that you added previously. Atmel Studio will then flash the code. 

#### Make

1. Install `make` for Windows, e.g. [GnuWin32](http://gnuwin32.sourceforge.net/packages/make.htm)
2. Install avr-gcc, AVRDUDE, and other AVR utilities as you see fit. Refer to the `Makefile`. You can also use an Arduino installation.
3. Add these tools to your system PATH.
4. Ensure that the AVRDUDE system configuration file is in the same directory as the executable.
5. `cd tinyblinkware`
6. `make` to compile
7. To flash, ensure that TinyBlink is connected  to your computer through your AVR programmer. Then `make flash` to flash

### Debian-based

1. Install the essential AVR development tools:`sudo apt-get install gcc-avr binutils-avr avr-libc`
2. `cd tinyblinkware`
3. `make` to compile
4. To flash, ensure that TinyBlink is connected  to your computer through your AVR programmer. Then `make flash` to flash

## Authors
- Ray Sun -  Student, B.S. EE, Caltech, Class of 2020

## Licensing
This project is licensed under the terms of the MIT license.
