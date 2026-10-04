#include "uart.h"

void main() {
    uart_init(); // ドライバの初期化を呼ぶ

    // アプリケーションは「どこに出力されるか」を気にせず、ただ文字を送るだけ
    uart_putc('H');
    uart_putc('i');
    
    while(1) {
        char c = uart_getc();
        uart_putc(c); // エコーバック
    }
}