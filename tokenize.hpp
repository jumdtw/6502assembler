#ifndef TOKENIZE_H
#define TOKENIZE_H

using namespace std;

#include<string>

// token num
#define LAVEL 56
#define OPECODE 58

// analysis phase
#define LAVEL_PHASE 411
#define OPECODE_PHASE 141
#define OPERAND_PHASE 114
#define FINISH_PHASE 111


// opecode
#define LDA_IMM 0xa9
#define LDA_ABS 0xad
#define STA_ABS 0x8d
#define ORA_IMM 0x09

//トークン
typedef struct{
    //各フラッグ
    //ラベルがあるか否か
    bool LAVEL_FLAG;
    //immdiate
    bool Imm_FLAG;
    //bin
    bool Bin_FLAG;
    //hex
    bool Hex_FLAG;
    //dec
    bool Dec_FLAG;
    //zeropage 
    bool Zero_FLAG;
    // 解析時に使う情報
    char tokenize_num;
    string lavel;
    string opecodestr;
    string operandstr;
    // 実際にバイナリに書き込む情報
    unsigned char opecode;
    unsigned char operand;   
}TOKEN;

//ラベルの名前とアドレス情報
typedef struct{
    string lavel;
    unsigned int adder;
}LAVEL_ADDER_INFO;


TOKEN tokenize(string asmcode);


#endif