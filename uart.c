#include "uart.h"

#ifdef TARGET_RPI3
// Base address for Raspberry Pi 3 (PL011)
#define UART_BASE 0x3F201000
#else
// Base address for QEMU (VersatilePB)
#define UART_BASE 0x101f1000
#endif

#define UART_DR (*(volatile unsigned int *)(UART_BASE + 0x00))
#define UART_FR (*(volatile unsigned int *)(UART_BASE + 0x18))

void uart_init() {
    // Baud rate settings can be added here in the future
    // (For Raspberry Pi, GPU firmware configures this, so it works empty)
}

void uart_putc(char c) {
    // Wait until transmit buffer is empty (FR bit 5 is TXFF: Transmit FIFO Full)
    while (UART_FR & (1 << 5));
    UART_DR = (unsigned int)c;
}

char uart_getc() {
    // Wait until receive buffer has data (FR bit 4 is RXFE: Receive FIFO Empty)
    while (UART_FR & (1 << 4));
    return (char)(UART_DR & 0xFF);
}
