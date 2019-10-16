#ifndef TOKENIZE_H
#define TOKENIZE_H

using namespace std;

#include<string>
#include<sstream>
#include<istream>
#include<iostream>
#include<vector>

// token num
#define LAVEL 56
#define OPECODE 58

// analysis phase
#define LAVEL_PHASE 411
#define OPECODE_PHASE 141
#define OPERAND_PHASE 114
#define FINISH_PHASE 111


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
    //indirect
    bool Indi_FLAG;
    // 解析時に使う情報
    string lavel;
    string opecodestr;
    string operandstr;
    unsigned int size;
    // 実際にバイナリに書き込む情報
    unsigned char opecode;
    unsigned int operand;   
}TOKEN;

//ラベルの名前とアドレス情報
typedef struct{
    string lavel;
    unsigned int addr;
}LAVEL_ADDER_INFO;


vector<TOKEN> tokenize(vector<string> asmcode);


#endif