# 6502 cpu assembler 


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


## 関数について

### tokenize()
トークンナイザというなの何か別のもの。
コンパイラとは違い一つずつの要素に分けて考えなくてもよいので1トークンは、
- lavel_adder
- lavel
- opecode
- operand
の情報を持った変数TOKENで構成される。

