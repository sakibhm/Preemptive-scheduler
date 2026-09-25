CC = arm-none-eabi-gcc

OBJCOPY = arm-none-eabi-objcopy

CFLAGS = -mcpu=cortex-m4 -mthumb -std=c11 -Wall -Wextra -IInc -g

LDFLAGS = -T linker_stm32f446.ld -nostdlib

TARGET = build/f4kernel

C_OBJECTS = build/main.o \
            build/usart2.o \
			build/task_init.o \
            build/taskA.o \
            build/taskB.o\
			build/SysTick.o \
			build/scheduler.o

ASM_OBJECTS = build/startup_stm32f446.o \
			  build/start_first_task.o \
			  build/svc_handler.o \
			  build/systick_handler.o

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

build/task_init.o: Src/task_init.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

build/taskA.o: Src/taskA.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

build/taskB.o: Src/taskB.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

build/SysTick.o: Src/Drivers/SysTick.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@


build/scheduler.o: Src/scheduler.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

build/startup_stm32f446.o: startup_stm32f446.s
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

build/start_first_task.o: start_first_task.s
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

build/svc_handler.o: svc_handler.s
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

build/systick_handler.o: systick_handler.s
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf build

flash:
	st-flash write build/f4kernel.bin 0x08000000