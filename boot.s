.global _start
_start:
#ifdef TARGET_RPI3
    @ Raspberry Pi 3 has 4 cores. Halt all cores except core 0.
    mrc p15, 0, r1, c0, c0, 5
    and r1, r1, #3
    cmp r1, #0
    bne hang

    @ Stack pointer setup for Raspberry Pi 3 (Load address is 0x8000)
    LDR sp, =0x8000
#else
    @ Stack pointer setup for QEMU VersatilePB (Load address is 0x10000)
    LDR sp, =0x8000
#endif

    BL  main             @ Jump to C main function
hang:
    B   hang             @ Infinite loop
