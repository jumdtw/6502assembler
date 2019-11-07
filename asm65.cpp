#include"tokenize.hpp"
#include"file_controller.hpp"
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

    if(argc<=2){
        cout << "argument err" << endl;
        return 1;
    }
    //引数受け取り
    string asmtext = argv[1];
    //ファイル読み込み
    vector<string> asmcodes = read_file(asmtext);
    //構文解析
    vector<TOKEN> token_vector = tokenize(asmcodes);
    //debug
    for(int i=0;i<token_vector.size();i++){
        cout << "-------------------" << i << "---------------" << endl;
        debug_print(&token_vector[i]);
    }
    //write file
    write_file(token_vector,argv[2]);
    return 0;
}