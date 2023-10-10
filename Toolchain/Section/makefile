#prebeard by Eng Ahmed Maher 
CC=arm-none-eabi-gcc
CFLAGS= -mcpu=cortex-m4  -c -mthumb -std=gnu11 -Wall
LDFLAGS= -T STM32f446_Linkerscript.ld -nostdlib -Wl,-Map=final.map


all: main.o STM32F446_Startup.o GPIO_Program.o final.elf
	
	
final.elf: main.o 	GPIO_Program.o STM32F446_Startup.o
	$(CC) $(LDFLAGS) $^ -o $@
	
main.o: main.c
	$(CC) $(CFLAGS) $^ -o $@
	
%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@
	@echo "========Build is done========" 
	
startup.o: STM32F446_Startup.c
	$(CC) $(CFLAGS) $^ -o $@
	
Load: 
	openocd -f board/st_nucleo_f4.cfg

clean:
	rm -rf *.o *.elf