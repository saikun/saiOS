/* linker_qemu.ld */
ENTRY(_start)
SECTIONS
{
    . = 0x10000;          /* Memory start address for VersatilePB */
    .text : { *(.text) }  /* Code section */
    .data : { *(.data) }  /* Data section */
    .bss  : { *(.bss)  }  /* Uninitialized variables */
}

