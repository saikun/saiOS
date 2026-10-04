.global _start
_start:
    LDR sp, =0x8000      @ スタックポインタを設定
    BL  main             @ C言語のmain関数へジャンプ
hang:
    B   hang             @ 終わったら無限ループ
