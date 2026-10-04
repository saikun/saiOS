@echo off
setlocal

echo ====================================
echo Building for QEMU (VersatilePB)
echo ====================================
if not exist build_qemu mkdir build_qemu

arm-none-eabi-gcc -c -x assembler-with-cpp -mcpu=arm926ej-s -D TARGET_QEMU -g boot.s -o build_qemu/boot.o
arm-none-eabi-gcc -c -mcpu=arm926ej-s -D TARGET_QEMU -fno-builtin -g uart.c -o build_qemu/uart.o
arm-none-eabi-gcc -c -mcpu=arm926ej-s -D TARGET_QEMU -fno-builtin -g main.c -o build_qemu/main.o
arm-none-eabi-ld -T linker_qemu.ld build_qemu/boot.o build_qemu/uart.o build_qemu/main.o -o build_qemu/kernel.elf
arm-none-eabi-objcopy -O binary build_qemu/kernel.elf build_qemu/kernel.bin

echo ====================================
echo Building for Raspberry Pi 3 Model B+
echo ====================================
if not exist build_rpi3 mkdir build_rpi3

arm-none-eabi-gcc -c -x assembler-with-cpp -mcpu=cortex-a7 -D TARGET_RPI3 -g boot.s -o build_rpi3/boot.o
arm-none-eabi-gcc -c -mcpu=cortex-a7 -D TARGET_RPI3 -fno-builtin -g uart.c -o build_rpi3/uart.o
arm-none-eabi-gcc -c -mcpu=cortex-a7 -D TARGET_RPI3 -fno-builtin -g main.c -o build_rpi3/main.o
arm-none-eabi-ld -T linker_rpi3.ld build_rpi3/boot.o build_rpi3/uart.o build_rpi3/main.o -o build_rpi3/kernel7.elf
arm-none-eabi-objcopy -O binary build_rpi3/kernel7.elf build_rpi3/kernel7.img

echo.
echo ====================================
echo Build completed successfully!
echo QEMU Binary: build_qemu\kernel.bin
echo RPi3 Binary: build_rpi3\kernel7.img
echo ====================================
echo [Note for Raspberry Pi 3]
echo Please copy the following files to the boot partition of your SD card:
echo 1. build_rpi3\kernel7.img
echo 2. config.txt (copy from the root directory)
