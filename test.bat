echo "normal test"
asm65 ".lavel operand 10"

echo "space test"
asm65 "                                         .lavel operand 10"
asm65 ".lavel operand 10                                       "
asm65 ".lavel operand                              10"

echo "flag test"
asm65 ".lavel operand #$16"
asm65 ".lavel operand $4046"
asm65 ".lavel operand %%10001010"
asm65 ".lavel operand LAVEL"
