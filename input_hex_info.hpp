#ifndef INPUT_HEX_INFO_H
#define INPUT_HEX_INFO_H

// opecode
//lda
#define LDA_IMM 0xa9
#define LDA_ABS 0xad
#define LDA_ABS_X 0xbd
#define LDA_ZERO 0xa5
#define LDA_ZERO_X 0xb5
#define LDA_INDI 0xa1
// ldx
#define LDX_IMM 0xa2
#define LDX_ABS 0xae
#define LDX_ZERO 0xa6
//sta
#define STA_ABS 0x8d
#define STA_ABS_X 0x9d
#define STA_ZERO 0x85
#define STA_ZERO_X 0x95
#define STA_INDI 0x81
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
//rti
#define RTI 0x40
//dec
#define DEC_ABS 0xce
#define DEC_ZERO 0xc6
//dex
#define DEX 0xca
//beq
#define BEQ 0xf0
//bne
#define BNE 0xd0
//inc
#define INC_ABS 0xee
#define INC_ZERO 0xe6
//adc
#define ADC_ABS 0x6d
#define ADC_ZERO 0x65
//sbc
#define SBC_ABS 0xed
#define SBC_ZERO 0xe5
//sei
#define SEI 0x78
//clc
#define CLC 0x18
//sec
#define SEC 0x38
//pha
#define PHA 0x48
//pla
#define PLA 0x68

vector<TOKEN> input_lavel_or_variable(vector<TOKEN> token_vector,vector<LAVEL_ADDER_INFO> lavel_map,vector<VARIABLE_INFO> variable_map);
vector<TOKEN> input_opecode_info(vector<TOKEN> token_vector,vector<VARIABLE_INFO> variable_map);

#endif