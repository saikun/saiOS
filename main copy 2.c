// UART0のデータレジスタ（読み書き兼用）
#define UART0_DR (*(volatile unsigned int *)0x101f1000)
// UART0のフラグレジスタ（状態確認用）
#define UART0_FR (*(volatile unsigned int *)0x101f1018)

// 1文字送信する関数
void uart_putc(char c) {
    UART0_DR = (unsigned int)c;
}

// 1文字受信する関数（ポーリング）
char uart_getc() {
    // フラグレジスタの第4ビット(0x10)が1の間（受信箱が空の間）はずっと待つ
    while (UART0_FR & (1 << 4)) {
        // 何もしないで待機
    }
    // データが届いたらデータレジスタから文字を取り出して返す
    return (char)(UART0_DR & 0xFF);
}

// 文字列を送信する関数
void uart_puts(const char *s) {
    while (*s != '\0') {
        uart_putc(*s);
        s++;
    }
}

void main() {
    uart_puts("Type something on your keyboard:\n");

    // 無限ループでキー入力を待ち、受け取った文字を画面にそのまま返す（エコーバック）
    while (1) {
        char c = uart_getc();
        
        // Enterキー（改行コード '\r'）が押されたら、画面上で改行 ('\n') も送る
        if (c == '\r') {
            uart_putc('\r');
            uart_putc('\n');
        } else {
            uart_putc(c);
        }
    }
}
