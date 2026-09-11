CC = arm-none-eabi-gcc

OBJCOPY = arm-none-eabi-objcopy

CFLAGS = -mcpu=cortex-m4 -mthumb -std=c11 -Wall -Wextra -IInc

LDFLAGS = -T linker_stm32f446.ld -nostdlib

TARGET = build/f4kernel

C_OBJECTS = build/main.o \
            build/usart2.o

ASM_OBJECTS = build/startup_stm32f446.o

OBJECTS = $(C_OBJECTS) $(ASM_OBJECTS)


all: $(TARGET).bin


$(TARGET).elf: $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@


$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@


build/main.o: Src/main.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@


build/usart2.o: Src/Drivers/usart2.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@


build/startup_stm32f446.o: startup_stm32f446.s
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf build

flash:
	st-flash write build/f4kernel.bin 0x08000000