# 6502 cpu assembler 
主は完全初心者のため玄人達からすると謎理論や謎実装のオンパレードかもしれませんがご容赦ください。

## Description 

まだ何もできていなし、とりあえず
- lda (A9) imm
- sta (8d) imm

しか実装しない。

今後増えるかも

アセンブリのフォーマット　format 
.LAVEL OPECODE OPERAND

exception

`.HOGE lda #$1f`

- \# -> imm
- $ -> hex

先頭はラベルから始まる。ラベルの大文字小文字は問わないが、文頭に**「.」**を付ける必要がある。