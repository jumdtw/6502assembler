#ifndef CALC_ADDR_H
#define CALC_ADDR_H

#include"tokenize.hpp"

vector<TOKEN> input_addr_size(vector<TOKEN> token_vector,vector<VARIABLE_INFO> variable_map);

bool check_lda(string str);
bool check_ldx(string str);
bool check_sta(string str);
bool check_ora(string str);
bool check_jmp(string str);
bool check_jsr(string str);
bool check_rts(string str);
bool check_rti(string str);
bool check_dec(string str);
bool check_beq(string str);
bool check_inc(string str);

#endif