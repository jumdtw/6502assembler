#include"tokenize.hpp"
#include<iostream>
#include<stdio.h>

int main(int argc,char *argv[]){

    if(argc==1){
        cout << "argument err" << endl;
        return 1;
    }
    string asmcode = argv[1];
    vector<TOKEN> source = tokenize(asmcode);
    TOKEN ppp = source[0];
    cout << "Lavel : " << ppp.lavel << endl;
    cout << "Opecodestr : " << ppp.opecodestr << endl;
    cout << "Operandstr : " << ppp.operandstr << endl;
    cout << "Imm_FLAG : " << ppp.Imm_FLAG << endl;
    cout << "Hex_FLAG : " << ppp.Hex_FLAG << endl;
    cout << "Bin_FLAG : " << ppp.Bin_FLAG << endl;
    cout << "opecode : " << "0x" << std::hex << ppp.opecode << endl;
    cout << "operand : " << "0x" << std::hex << ppp.operand << endl;
    cout << "size : " << "0x" << hex << ppp.size << endl;
    return 0;
}