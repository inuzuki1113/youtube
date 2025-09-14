TARGET  := Nico3DSStream
BUILD   := build

SOURCES := $(wildcard source/*.c)
INCLUDES:= -Isource
CFLAGS  := -O2 -Wall -march=armv6k -mfloat-abi=hard
LDFLAGS := -LC:/devkitPro/libctru/lib -lctru -lsf2d -lcitro3d -lhttpc

all:
	mkdir -p $(BUILD)
	arm-none-eabi-gcc $(CFLAGS) $(INCLUDES) $(SOURCES) -o $(BUILD)/$(TARGET).elf $(LDFLAGS)
	3dstool -c $(BUILD)/$(TARGET).3dsx -elf $(BUILD)/$(TARGET).elf
