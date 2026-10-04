#include "uart.h"

// Helper function to print a string
void uart_puts(const char *str) {
    while (*str) {
        if (*str == '\n') {
            uart_putc('\r'); // Add carriage return to prevent formatting issues
        }
        uart_putc(*str++);
    }
}

// Helper function to print a decimal number
void print_dec(unsigned int val) {
    char buf[12];
    int i = 0;
    
    if (val == 0) {
        uart_putc('0');
        return;
    }
    
    // Convert to string (reverse order)
    while (val > 0) {
        buf[i++] = (val % 10) + '0';
        val /= 10;
    }
    
    // Print in correct order
    while (i > 0) {
        uart_putc(buf[--i]);
    }
}

// Simple delay function
void delay(volatile unsigned int count) {
    while(count--) {
        __asm__ volatile("nop");
    }
}

void main() {
    uart_init(); // Initialize UART

    unsigned int counter = 0;

    while(1) {
        // Print fixed string + incrementing counter
        uart_puts("Hello saiOS! Counter: ");
        print_dec(counter);
        uart_puts("\n");
        
        counter++;
        
        // Simple wait to prevent spamming output
        delay(5000000);
    }
}