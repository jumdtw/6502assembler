# 6502 cpu assembler 

## 注意点

下ではいい感じのこと言ってますが、まだ何も実装できてません。




## Description 

こちらはファミコン用の機械語をはきだすアセンブラ。
主は完全初心者のため玄人達からすると謎理論や謎実装のオンパレードかもしれませんがご容赦ください。

## 構文

アセンブリのフォーマット　format 

**.LAVEL OPECODE OPERAND**

exception
`.HOGE lda #$1f`

### LAVEL
先頭はラベルから始まる。ラベルの大文字小文字は問わないが、文頭に**.**(ドット)を付ける必要がある。

### OPECODE
次に、オペコードについて。
実装しているオペコードは

- LDA (一部)
- STA (一部)
- ORA (一部)

である。
各コードの詳細は[こちら](http://hp.vector.co.jp/authors/VA042397/nes/6502.html)


### OPERAND

頭文字に「#」、「%」、「$」のいずれかがつく。

- \# immediate
- % binary
- $ hexadecimal


### comment
コメントは文頭に[;]を付ける


## 構文記述に関する注意点

### lavel
ラベル名の制約はありませんが、頭文字に[.]がついていないとラベルとして認識してくれません。

### opecode
たとえば、ldaなどを使う際
`lda`
`LDA`
と書くぶんには問題ありませんが
`Lda`
`lDa`
`ldA`
などと書くとエラーが発生します。

## メモ
命令を追加するときは

calc_addr.cpp calc_addr.hpp input_hex_info.cpp input_hex_info.hppに加筆する



