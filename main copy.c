// UART0のデータレジスタの番地（0x101f1000）をポインタとして定義
#define UART0_DR (*(volatile unsigned int *)0x101f1000)

// 1文字送信する関数
void uart_putc(char c) {
    UART0_DR = (unsigned int)c;
}

// 文字列を送信する関数（簡易版printf）
void uart_puts(const char *s) {
    while (*s != '\0') {
        uart_putc(*s);
        s++;
    }
}

void main() {
    uart_puts("Hello, OS World!\n");
}
