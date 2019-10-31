#ifndef TOKENIZE_H
#define TOKENIZE_H

#include<string>
#include<sstream>
#include<istream>
#include<iostream>
#include<vector>

using namespace std;

// token num
#define LAVEL 56
#define OPECODE 58

// analysis phase
#define LAVEL_PHASE 411
#define OPECODE_PHASE 141
#define OPERAND_PHASE 114
#define FINISH_PHASE 111

//#define IMMDIATE 255
enum var_type{
    IMMDIATE=255,
    ADDRESS,    //256
    VARIABLE,   //257
    OPERATOR,   //258
    ERROR,      //259
};


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


//変数の名前と即値
typedef struct{
    int value_imm_or_addr;
    string variable_name;
    unsigned int value;
}VARIABLE_INFO;

typedef struct{
    int num;
    string value_str;
    unsigned int value_int;
}VAR_TOKEN;

vector<TOKEN> tokenize(vector<string> asmcode);


#endif