#include"tokenize.hpp"
#include<fstream>
#include<iostream>
#include<stdio.h>

void debug_print(TOKEN *token){
    cout << "Lavel : " << token->lavel << endl;
    cout << "Opecodestr : " << token->opecodestr << endl;
    cout << "Operandstr : " << token->operandstr << endl;
    cout << "Imm_FLAG : " << token->Imm_FLAG << endl;
    cout << "Hex_FLAG : " << token->Hex_FLAG << endl;
    cout << "Bin_FLAG : " << token->Bin_FLAG << endl;
    cout << "opecode : " << "0x" << std::hex << (unsigned int)token->opecode << endl;
    cout << "operand : " << "0x" << std::hex << token->operand << endl;
    cout << "size : " << "0x" << hex << token->size << endl;
}

int main(int argc,char *argv[]){

    if(argc==1){
        cout << "argument err" << endl;
        return 1;
    }

    string asmcode,asmtext = argv[1];
    vector<string> asmcodes;
    std::ifstream ifs(asmtext);
    if (ifs.fail()) {
        std::cerr << "Failed to open file." << std::endl;
        return -1;
    }
    while (getline(ifs, asmcode)) {
        asmcodes.push_back(asmcode);
    }
    vector<TOKEN> source = tokenize(asmcodes);
    TOKEN ppp = source[1];
    debug_print(&ppp);
    return 0;
}