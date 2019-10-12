#include"tokenize.hpp"
#include"calc_addr.hpp"


vector<TOKEN> input_opecode_info(vector<TOKEN> token_vector,vector<LAVEL_ADDER_INFO> lavel_map){
    vector<TOKEN> p;
    return p;
}


vector<LAVEL_ADDER_INFO> lavel_mapping(vector<TOKEN> token_vector){
    vector<LAVEL_ADDER_INFO> map;
    LAVEL_ADDER_INFO buf_info;
    TOKEN buf_token;
    unsigned int base_addr = 0x8000;

    for(int i=0;i<token_vector.size();i++){
        buf_token = token_vector[i];
        if(buf_token.LAVEL_FLAG){
            buf_info.lavel = buf_token.lavel;
            buf_info.addr;
        }
        map.push_back(buf_info);
        // plus opecode size
        base_addr += buf_token.size;        
    }
    return map;
}


void check_hex_bin(TOKEN *p){
    const char Hex = '$',Bin = '%';
    if(p->operandstr.front() == Hex){
        p->Hex_FLAG = true;
        p->Bin_FLAG = false;
        cout << "debug hex operandstr.substr(1) : "<< hex << p->operandstr.substr(1) << endl;
        p->operandstr = p->operandstr.substr(1);
    }else if(p->operandstr.front() == Bin){
        p->Hex_FLAG = false;
        p->Bin_FLAG = true;
        cout << "debug bin operandstr.substr(1) : "<< hex << p->operandstr.substr(1) << endl;
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
        cout << "debug imm operandstr.substr(1) : "<< hex << p->operandstr.substr(1) << endl;
        p->operandstr = p->operandstr.substr(1);
    }else{
        p->Imm_FLAG = false;
    }
}

void change_str_chr(TOKEN *token){
    if(token->Hex_FLAG){             // 16進数の場合
        cout << "debug stoi(((token->operandstr).c_str()),nullptr,16) : "<< hex << (unsigned int)stoi(((token->operandstr).c_str()),nullptr,16) << endl;
        token->operand = (unsigned int)stoi(((token->operandstr).c_str()),nullptr,16);
    }else if(token->Bin_FLAG){       // 2進数の場合
        token->operand = (unsigned int)stoi(((token->operandstr).c_str()),nullptr,2);
    }else if(token->Imm_FLAG){       // 10進数の場合(hexでもbinでもないのにimmなのは10進数しかありえない。すべてfalseの場合はlavelである。)
        token->operand = (unsigned int)atoi(token->operandstr.c_str());
    }
}

int input_token_info(TOKEN *p,string buf,int PAST_PHASE){
    string conma = ".";
    int buf_operand;
    //space 区切りでラベル、オペコード、オペランドを区分けしている。
    if(PAST_PHASE==LAVEL_PHASE){
        // ラベルがない場合があるためここで判別している。
        if(buf[0]==conma[0]){
            p->lavel = buf;
            p->LAVEL_FLAG = true;
            PAST_PHASE = OPECODE_PHASE;
        }else{
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
        if(p->Hex_FLAG || p->Bin_FLAG || p->Imm_FLAG){
            change_str_chr(p);
        }
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


vector<TOKEN> tokenize(string asmcode){
    //必要な変数
    // vector によるtokenの集まり
    vector<TOKEN> token_vector;
    // このlavel mapを参照することでlavelのアドレスがわかる。
    vector<LAVEL_ADDER_INFO> lavel_map;

    // アセンブリコード一行分をここで解析する
    TOKEN s = analysis_line(asmcode);
    token_vector.push_back(s);

    // 一行ごとのサイズを割り出す
    token_vector = input_addr_size(token_vector);

    // 上からvector をなぞって tokenのlavel情報からlavel mapを生成する。
    lavel_map = lavel_mapping(token_vector);

    // opecode
    //token_vector = input_opecode_info(token_vector,lavel_map);

    return token_vector;
}