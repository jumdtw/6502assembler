#include"tokenize.hpp"
#include<iostream>
#include<stdio.h>


using namespace std;

int main(int argc,char *argv[]){

    if(argc==1){
        cout << "argument err" << endl;
        return 1;
    }
    string asmcode = argv[1];
    TOKEN source = tokenize(asmcode);
    cout << "Lavel : " << source.lavel << endl;
    cout << "Opecode : " << source.opecodestr << endl;
    printf("Operand : 0x%x\n",source.operand);
    cout << "Imm_FLAG : " << source.Imm_FLAG << endl;
    cout << "Hex_FLAG : " << source.Hex_FLAG << endl;
    cout << "Bin_FLAG : " << source.Bin_FLAG << endl;
    return 0;
}