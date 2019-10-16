#ifndef INPUT_HEX_INFO_H
#define INPUT_HEX_INFO_H

// opecode
//lda
#define LDA_IMM 0xa9
#define LDA_ABS 0xad
#define LDA_ZERO 0xa5
#define LDA_INDI 0xa1
// ldx
#define LDX_IMM 0xa2
//sta
#define STA_ABS 0x8d
#define STA_ZERO 0x85
//ora
#define ORA_IMM 0x09
#define ORA_ABS 0x0D
#define ORA_ZERO 0x05
//jmp
#define JMP_ABS 0x4c
//jsr
#define JSR 0x20
//rts
#define RTS 0x60
//dec
#define DEC_ABS 0xce
#define DEC_ZERO 0xc6
//beq
#define BEQ 0xf0


vector<TOKEN> input_lavel(vector<TOKEN> token_vector,vector<LAVEL_ADDER_INFO> lavel_map);
vector<TOKEN> input_opecode_info(vector<TOKEN> token_vector);

#endif