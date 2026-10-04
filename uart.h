// Hardware addresses should not be here! Expose only the interfaces
void uart_init();
void uart_putc(char c);
char uart_getc();