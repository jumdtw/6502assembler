# 6502 cpu assembler 
主は完全初心者のため玄人達からすると謎理論や謎実装のオンパレードかもしれませんがご容赦ください。

## Description 

こちらはファミコン用の機械語をはきだすアセンブラ。

アセンブリのフォーマット　format 
.LAVEL OPECODE OPERAND

exception

`.HOGE lda #$1f`

### LAVEL
先頭はラベルから始まる。ラベルの大文字小文字は問わないが、文頭に**.**(ドット)を付ける必要がある。

### OPECODE
次に、オペコードについて。
実装しているオペコードは

- LDA
- STA

である。
各コードの詳細は[こちら](http://hp.vector.co.jp/authors/VA042397/nes/6502.html)


### OPERAND

頭文字に「#」、「%」、「$」のいずれかがつく。

- \# immediate
- % binary
- $ hexadecimal


#### 余談
実は即値(immediate)に関しては、オペコードで判別しているため「#」はなくても実装
はできるが、可読性をあげるために「#」をつけないとエラーを出すようにしている。