/* linker_rpi3.ld */
ENTRY(_start)
SECTIONS
{
    . = 0x8000;           /* Memory start address for Raspberry Pi */
    .text : { *(.text) }  /* Code section */
    .data : { *(.data) }  /* Data section */
    .bss  : { *(.bss)  }  /* Uninitialized variables */
}

