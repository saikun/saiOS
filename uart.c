#include "uart.h"

// ハードウェアの番地を知っているのはこのファイルの中だけ
#define UART0_DR (*(volatile unsigned int *)0x101f1000)
#define UART0_FR (*(volatile unsigned int *)0x101f1018)

void uart_init() {
    // 将来、通信速度(ボーレート)の設定などが必要ならここに書く
}

void uart_putc(char c) {
    UART0_DR = (unsigned int)c;
}

char uart_getc() {
    while (UART0_FR & (1 << 4));
    return (char)(UART0_DR & 0xFF);
}