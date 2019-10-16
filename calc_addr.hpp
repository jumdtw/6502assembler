#ifndef CALC_ADDR_H
#define CALC_ADDR_H

// opecode
#define LDA_IMM 0xa9
#define LDA_ABS 0xad
#define LDA_ZERO 0xa5
#define STA_ABS 0x8d
#define STA_ZERO 0x85
#define ORA_IMM 0x09
#define JMP_ABS 0x4c
#define JSR 0x20
#define RTS 0x60


#include"tokenize.hpp"

vector<TOKEN> input_addr_size(vector<TOKEN> token_vector);

bool check_lda(string str);
bool check_sta(string str);
bool check_ora(string str);
bool check_jmp(string str);
bool check_jsr(string str);
bool check_rts(string str);

#endif