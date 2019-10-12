#include"tokenize.hpp"
#include<string>
#include<sstream>
#include<istream>
#include<iostream>
#include<vector>


using namespace std;



vector<TOKEN> input_opecode_info(vector<TOKEN> token_vector){
    vector<TOKEN> p;
    return p;
}

vector<LAVEL_ADDER_INFO> lavel_mapping(vector<TOKEN> token_vector){
    vector<LAVEL_ADDER_INFO> map;
    for(int i=0;i<token_vector.size();i++){

    }
    return map;
}

void check_hex_bin(TOKEN *p){
    const char Hex = '$',Bin = '%';
    if(p->operandstr.front() == Hex){
        p->Hex_FLAG = true;
        p->Bin_FLAG = false;
        p->operandstr = p->operandstr.substr(1);
    }else if(p->operandstr.front() == Bin){
        p->Hex_FLAG = false;
        p->Bin_FLAG = true;
        p->operandstr = p->operandstr.substr(1);
    }else{
        p->Hex_FLAG = false;
        p->Bin_FLAG = false;
    }
}

void check_Imm(TOKEN *p){
    const char Imm = '#';
    if(p->operandstr.front() == Imm){
        p->Imm_FLAG = true;
        p->operandstr = p->operandstr.substr(1);
    }else{
        p->Imm_FLAG = false;
    }
}

int input_token_info(TOKEN *p,string buf,int PAST_PHASE){
    string conma = ".";
    int buf_operand;
    //space 区切りでラベル、オペコード、オペランドを区分けしている。
    if(PAST_PHASE==LAVEL_PHASE){
        // ラベルがない場合があるためここで判別している。
        if(buf[0]==conma[0]){
            p->tokenize_num = LAVEL;
            p->lavel = buf;
            p->LAVEL_FLAG = true;
            PAST_PHASE = OPECODE_PHASE;
        }else{
            p->tokenize_num = OPECODE;
            p->lavel = "None";
            p->LAVEL_FLAG = false;
            p->opecodestr = buf;
            PAST_PHASE = OPERAND_PHASE;
        }
    }else if(PAST_PHASE==OPECODE_PHASE){
        p->opecodestr = buf;
        PAST_PHASE = OPERAND_PHASE;
    }else if(PAST_PHASE==OPERAND_PHASE){
        p->operandstr = buf;
        check_Imm(p);
        check_hex_bin(p);
        buf_operand = atoi(buf.c_str());
        p->operand = (unsigned char)buf_operand;
        PAST_PHASE = FINISH_PHASE;
    }else if(PAST_PHASE==FINISH_PHASE){
        cout << "err analysis" << endl;
    }
    return PAST_PHASE;
}



TOKEN analysis_line(string asmcode_line){
    // 1 TOKEN 1行文のアセンブリコードに相当する。
    TOKEN p;
    int asmline_len = asmcode_line.length();
    string buf = "",space = " ",nostr = "";
    
    // 現在のフェーズをあらわす。初期値はラベルから。
    int PAST_PHASE = 411;

    for(int i = 0;i < asmline_len;i++){
        // finish phaseになっていたらループを出る。
        if(PAST_PHASE==FINISH_PHASE)break;
        // spaceをここで排除している。
        if(asmcode_line[i] != space[0]){

            buf += asmcode_line[i];
            if(i == (asmline_len-1)){
                if(buf != nostr){
                    PAST_PHASE = input_token_info(&p,buf,PAST_PHASE);
                }
            }

        //buf == nostrは 連続でspaceがならんでいる状態であるため
        }else if(buf != nostr){

            PAST_PHASE = input_token_info(&p,buf,PAST_PHASE);
            buf = "";
        
        }
    }
    return p;
}


TOKEN tokenize(string asmcode){
    //必要な変数
    // vector によるtokenの集まり
    vector<TOKEN> token_vector;
    // このlavel mapを参照することでlavelのアドレスがわかる。
    vector<LAVEL_ADDER_INFO> lavel_map;

    // アセンブリコード一行分をここで解析する
    TOKEN s = analysis_line(asmcode);
    token_vector.push_back(s);

    // 上からvector をなぞって tokenのlavel情報からlavel mapを生成する。
    lavel_map = lavel_mapping(token_vector);

    // opecode
    token_vector = input_opecode_info(token_vector);

    return s;
}