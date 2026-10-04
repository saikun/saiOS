arm-none-eabi-gcc -c -mcpu=arm926ej-s -g boot.s -o boot.o
arm-none-eabi-gcc -c -mcpu=arm926ej-s -fno-builtin -g uart.c -o uart.o
arm-none-eabi-gcc -c -mcpu=arm926ej-s -fno-builtin -g main.c -o main.o
arm-none-eabi-ld -T linker.ld boot.o uart.o main.o -o kernel.elf
arm-none-eabi-objcopy -O binary kernel.elf kernel.bin
