#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************
#------------------------------------------------------------------------------
# This code is supposed to work in the HOST machine and in the 
# MSP432 microcontroller, but I was not able to make it to the end
# I don't know if it's my machine, but I got locked in a error
# and after 1 week trying I gave up. Maybe I have enough good 
# material here to pass this assigment. First time using makefile
# or even compiling using flags...
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#		<TARGET>.o - Builds .o File
#		all -		 Builds .o File
#       build -  	 Same as all
#		<TARGET>.asm Assembly code
#		compile-all  Compile but doesn't build
#		clean - 	 Clean all created files
#'
# Platform Overrides:'
#      <Put a description of the supported Overrides here
#		PLATFORM=HOST   - Default and not necesssary
#		PLATFORM=MSP432 - for MSP432  enviroment
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM ?= HOST
TARGET = c1m2

# Architectures Specific Flags
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs
FPU = fpv4-sp-d16
LD_MSP = arm-none-eabi-ld
LINKER_FILE = ../msp432p401r.lds
LDFLAGS_MSP = -T $(LINKER_FILE)
CFLAGS_MSP =  -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=armv7e-m -mfloat-abi=hard -mfpu=$(FPU)		


# Compiler Flags and Defines 
LD = ld
CFLAGS = -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM)
CPPFLAGS = -E
LDFLAGS = -Wl,-Map=$(TARGET).map 
SIZE = size
MAIN = main
OBJDUMP = objdump

ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc
	CFLAGS += $(CFLAGS_MSP)
	LD = $(LD_MSP)
	LDFLAGS += $(LDFLAGS_MSP)
	SOURCES += $(SOURCES_MSP)
	OBJDUMP = arm-none-eabi-objdump
	SIZE = arm-none-eabi-size 
else
	CC = gcc
endif

OBJECTS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
ASMS = $(SOURCES:.c=.asm)
PREP = $(SOURCES:.c=.i)

.PHONY: compile-all
compile-all: $(OBJECTS)
	$(CC) $(INCLUDES) $(OBJECTS) -c $(CFLAGS) -o $(TARGET).o

.PHONY: build
build: $(TARGET).out $(TARGET).asm

.PHONY: compile-all
compile-all : $(OBJECTS)


.PHONY: clean
clean:
	rm -f $(TARGET).asm *.asm *.i *.o *.d $(TARGET).out $(TARGET).map $(PREP) $(ASMS) $(DEPS) $(OBJECTS)

$(TARGET).out: $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDES) -o $@ $(OBJECTS)
	$(SIZE) -Atd $(TARGET).out
	$(SIZE) $(TARGET).out

%.o : %.c
	$(CC) $(INCLUDES) -c $< $(CFLAGS) -o $@

%.asm : %.c
	$(CC) $(INCLUDES) -S $< $(CFLAGS) -o $@

$(TARGET).asm : $(TARGET).out
	$(OBJDUMP) -d $(TARGET).out >> $@

%.i : %.c
	$(CC) $(INCLUDES) $(CPPFLAGS) $< $(CFLAGS) -o $@

%.d : %.c
	$(CC) $(INCLUDES) -M $< $(CFLAGS) -o $@
