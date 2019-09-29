# Makefile
#
# Description:
#       This is a Makefile intended for building tinyblinkware with avr-gcc 
#       and AVRDUDE.
#
#       THIS IS NOT THE ATMEL STUDIO MAKEFILE!!!
#
# Dependencies:
#       Please make sure you have at least avr-gcc and AVRDUDE, and these are 
#       specified in the system PATH.
#
# Notes:
#       This Makefile defaults to flashing with a USBtinyISP programmer. If 
#       you would like to use a different programmer, create an explicit rule 
#       for it that defines the PROGRAMMER and PROGRAMMER_ARGS as below.
#
# Notes for Windows:
#       To maintain cross-platform compatibility, the AVRDUDE configuration 
#       file must be placed in the same directory as the 'avrdude.exe'
#       executable. See below for details.
#
# Author:           Ray Sun
# Last Updated:     09/06/2019
#


############################# SYSTEM DEFINITIONS ###############################


DEVICE     = attiny85

# Default programmer - USBtinyISP
PROGRAMMER = usbtiny

# Extra AVRDUDE arguments - default none
PROGRAMMER_ARGS = 

# This Makefile does not permit fuse flashing, in order to prevent grief
# from developers that don't know what they're doing 
#FUSES      = -U lfuse:w:0x62:m -U hfuse:w:0xdf:m -U efuse:w:0xff:m


#################################### FILES #####################################


# Directories for files
APPDIR  = app
MWDIR   = middleware
HALDIR  = hal

# File lists
SOURCES = $(wildcard *.c $(APPDIR)/*.c $(HALDIR)/*.c $(MWDIR)/*.c)
OBJECTS = $(SOURCES:.c=.o)
HEADERS = $(SOURCES:.c=.h) 
HEADERS += $(wildcard *.h $(APPDIR)/*.h $(HALDIR)/*.h $(MWDIR)/*.h)


#################################### TOOLS #####################################


CC          = avr-gcc
CFLAGS      = -Wall -Os
CSTANDARD   = -std=gnu11

OBJDUMP     = avr-objdump
AVRSIZE     = avr-size
AVRDUDE     = avrdude

# For experimental program features - default nothing
CDEF    = 

# Macro to define for experimental features
XPDEF   = EXECUTE


COMPILE = $(CC) $(CFLAGS) $(CSTANDARD) -mmcu=$(DEVICE) $(CDEF)


# Note: For cross-platform compatibility, on Windows, you must place the AVRDUDE
# configuration file in the same directory as the avrdude.exe executable.
# This is NOT default if you are using Arduino; copy the 'avrdude.conf' file 
# at the AVRCONF directory below to AVRDUDEPATH
#
# Alternatively you can use the UPLOAD definition that specifies -C $(AVRCONF)

#ARDUINOAVRCONF = "C:\Program Files (x86)\Arduino\hardware\tools\avr/etc/avrdude.conf"
#ARDUINOAVRDUDEPATH = "C:\Program Files (x86)\Arduino\hardware\tools\avr\bin"

UPLOAD = avrdude -c $(PROGRAMMER) -p $(DEVICE) $(PROGRAMMER_ARGS)
#UPLOAD = avrdude -C $(ARDUINOAVRCONF) -c $(PROGRAMMER) -p $(DEVICE) $(PROGRAMMER_ARGS)


#################################### RULES #####################################


all:	main.hex

    
# For experimental program features; define the XPDEF macro
execute: CDEF = -D$(XPDEF)
execute: all


# Implicit rules
.c.o: $(HEADERS)
	$(COMPILE) -c $< -o $@

.S.o:
	$(COMPILE) -x assembler-with-cpp -c $< -o $@

.c.s:
	$(COMPILE) -S $< -o $@


.PHONY: all clean flash fuse size disasm cpp


# Verify device
verify:	all
	$(UPLOAD)

# Upload flash
flash:	all
	$(UPLOAD) -U flash:w:main.hex:i

# Alias
install: flash
upload: flash


# Alternative flash rules for different programmers

# USBtinyISP (default)
flash_usbtiny: PROGRAMMER = usbtiny
flash_usbtiny: PROGRAMMER_ARGS =
flash_usbtiny: flash

# Arduino as ISP
flash_arduinoISP: PROGRAMMER      = avrisp
# For Linux
flash_arduinoISP: PROGRAMMER_ARGS = -b 19200 -P /dev/ttyACM0 
# For Windows 
#flash_arduinoISP: PROGRAMMER_ARGS = -b 19200 -P COM5
flash_arduinoISP: flash


# No fuse programming
fuse:
	@echo "You sure you need to flash fuses? Let's see if you know what you're doing."


clean:
	rm -f main.hex main.elf $(OBJECTS)


main.elf: $(OBJECTS)
	$(COMPILE) -o main.elf $(OBJECTS)


main.hex: main.elf
	rm -f main.hex
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex


size: main.elf
	$(AVRSIZE) -C --mcu=$(DEVICE) main.elf
  
  
disasm:	main.elf
	$(OBJDUMP) -d main.elf


# Print help messages for usage
help:
	@echo 
	@echo "make                       compile"
	@echo "make execute               compile with experimental features"
	@echo "make flash                 flash with default programmer"
	@echo "make flash_usbtiny         flash with USBtinyISP"
	@echo "make flash_arduinoISP      flash with Arduino as ISP"
	@echo "make clean                 remove binaries"
	@echo "make size                  display program size"
	@echo "make disasm                disassemble"
	@echo 
