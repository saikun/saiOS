ENTRY(_start)
SECTIONS
{
    . = 0x10000;          /* VersatilePBのメモリ開始番地 */
    .text : { *(.text) }  /* 実行コード */
    .data : { *(.data) }  /* データ */
    .bss  : { *(.bss)  }  /* 初期化されていない変数 */
}
