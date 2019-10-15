#ifndef INPUT_HEX_INFO_H
#define INPUT_HEX_INFO_H

// opecode
#define LDA_IMM 0xa9
#define LDA_ABS 0xad
#define LDA_ZERO 0xa5
#define STA_ABS 0x8d
#define STA_ZERO 0x85
#define ORA_IMM 0x09
#define ORA_ABS 0x0D
#define ORA_ZERO 0x05
#define JSR 0x20
#define RTS 0x60

vector<TOKEN> input_lavel(vector<TOKEN> token_vector,vector<LAVEL_ADDER_INFO> lavel_map);
vector<TOKEN> input_opecode_info(vector<TOKEN> token_vector);

#endif