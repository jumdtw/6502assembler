#include"tokenize.hpp"
#include"calc_addr.hpp"
#include"input_hex_info.hpp"
#include"tokenize_var.hpp"
#include"variable_parse.hpp"

using namespace std;

vector<LAVEL_ADDER_INFO> lavel_mapping(vector<TOKEN> token_vector){
    vector<LAVEL_ADDER_INFO> map;
    LAVEL_ADDER_INFO buf_info;
    TOKEN buf_token;
    unsigned int base_addr = 0x8000;

    for(int i=0;i!=token_vector.size();i++){
        buf_token = token_vector[i];
        if(buf_token.LAVEL_FLAG){
            buf_info.lavel = buf_token.lavel;
            buf_info.addr = base_addr;
            map.push_back(buf_info);
        }
        // plus opecode size
        base_addr += buf_token.size;      
        //cout << buf_token.opecodestr << " : 0x" << hex << buf_token.size << " : 0x" << hex << base_addr << endl;
    }
    cout << "--------------------label_map--------------------" << endl;
    for (int i=0;i!=map.size();i++){
        cout << map[i].lavel <<  " : 0x" << hex << map[i].addr << endl;
    }
    cout << "-------------------------------------------------" << endl;
    return map;
}

bool check_bin(string p){
    string Bin = "%";
    if(p.front() == Bin[0]){
        return true;
    }
    return false;
}

bool check_hex(string p){
    string Hex = "$";
    if(p.front() == Hex[0]){
        return true;
    }
    return false;
}


bool check_Imm(string p){
    string Imm = "#";
    if(p.front() == Imm[0]){
        return true;
    }else{
        return false;
    }
}

bool check_Indirect(string p){
    string Indi = "[";
    if(p.front() == Indi[0]){
        return true;
    }else{
        return false;
    }
}

unsigned int change_str_chr(string token,bool Hex_FLAG,bool Bin_FLAG,bool Imm_FLAG){
    if(Hex_FLAG){             // 16進数の場合
        return (unsigned int)stoi(((token).c_str()),nullptr,16);
    }else if(Bin_FLAG){       // 2進数の場合
        return (unsigned int)stoi(((token).c_str()),nullptr,2);
    }else if(Imm_FLAG){       // 10進数の場合(hexでもbinでもないのにimmなのは10進数しかありえない。すべてfalseの場合はlavelである。)
        return (unsigned int)atoi(token.c_str());
    }
    return 1;
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
        
        if(check_Indirect(p->operandstr)){
            p->Indi_FLAG = true;
            p->operandstr = p->operandstr.substr(1);
            p->operandstr = p->operandstr.substr(0,p->operandstr.length()-1);
        }else{
            p->Indi_FLAG = false;
        }

        if(check_Imm(p->operandstr)){
            p->Imm_FLAG = true;
            p->operandstr = p->operandstr.substr(1);
        }else{
            p->Imm_FLAG = false;
        }

        if(check_hex(p->operandstr)){
            p->Hex_FLAG = true;
            p->Bin_FLAG = false;
            p->operandstr = p->operandstr.substr(1);
        }else if(check_bin(p->operandstr)){
            p->Hex_FLAG = false;
            p->Bin_FLAG = true;
            p->operandstr = p->operandstr.substr(1);
        }else{
            p->Hex_FLAG = false;
            p->Bin_FLAG = false;
        }

        if(p->Hex_FLAG || p->Bin_FLAG || p->Imm_FLAG){
            p->operand = change_str_chr(p->operandstr,p->Hex_FLAG,p->Bin_FLAG,p->Imm_FLAG);
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
    string buf = "",space = " ",nostr = "",coron = ":";
    
    // 現在のフェーズをあらわす。初期値はラベルから。
    int PAST_PHASE = 411;

    for(int i = 0;i < asmline_len;i++){
        // finish phaseになっていたらループを出る。
        if(PAST_PHASE==FINISH_PHASE);
        // spaceをここで排除している。
        if(asmcode_line[i] != space[0]){
            buf += asmcode_line[i];
            if(PAST_PHASE==FINISH_PHASE&&buf==nostr){
                break;
            }
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

bool check_variable(string text){
    string variable = ":";
    for(int i=0;i<text.length();i++){
        if(text[i]==variable[0]){
            return true;
        }
    }
    return false;
}

vector<VAR_TOKEN> new_token_variable(string p,vector<VAR_TOKEN> var_token_vector){
    VAR_TOKEN var_token;
    string nostr="";
    if(p!=nostr){
        bool hex=false,bin=false,imm=false;
        if(check_Imm(p)){
            imm = true;
            p = p.substr(1);
        }
        if(check_hex(p)){
            hex = true;
            p = p.substr(1);
        }
        if(check_bin(p)){
            bin = true;
            p = p.substr(1);
        }

        if(isdigit_my(p)){
            if(imm){
                var_token.num = IMMDIATE;
            }else if(hex||bin){
                var_token.num = ADDRESS;
            }else{
                var_token.num = ERROR;
                var_token_vector.push_back(var_token);
            }
            var_token.value_int = change_str_chr(p,hex,bin,imm);
            var_token_vector.push_back(var_token);
        }else{
            var_token.num = VARIABLE;
            var_token.value_str = p;
            var_token_vector.push_back(var_token);
        }
    }
    return var_token_vector;
}

vector<VAR_TOKEN> tokenize_variable(int start,string text){
    vector<VAR_TOKEN> var_token_vector;
    string p = "",nostr="";
    for(int i=start;i<text.length();i++){
        VAR_TOKEN var_token;
        if(i==(text.length()-1)){
            p += text[i];
            var_token_vector = new_token_variable(p,var_token_vector);
            p = "";
            continue;
        }
        //space
        if(text[i]==' '){
            var_token_vector = new_token_variable(p,var_token_vector);
            p = "";
            continue;
        }
        //operator
        if(text[i]=='='){
            var_token_vector = new_token_variable(p,var_token_vector);
            p = "";
            var_token.num = OPERATOR;
            var_token.value_str = text[i]; 
            var_token_vector.push_back(var_token);
            continue;
        }
        p += text[i];
    }
    for(int i=0;i<var_token_vector.size();i++){
        VAR_TOKEN t = var_token_vector[i];
        //cout << "num : " << t.num << endl;
        //cout << "value_str : " << t.value_str << endl;
        //cout << "value_int : " << t.value_int << endl;
    }
    return var_token_vector;
}


vector<VARIABLE_INFO> mapping_variable(string text,vector<VARIABLE_INFO> variable_map){
    VARIABLE_INFO var_info;
    vector<VAR_TOKEN> var_token_vector;
    int start;
    string variable = ":",space=" ";
    // search variable
    for(int i=0;i<text.length();i++){
        if(text[i]==space[0]){
            continue;
        }
        if(text[i]==variable[0]){
            start = i+1;
            break;
        }
    }
    var_token_vector = tokenize_variable(start,text);
    
    variable_map = variable_parse(variable_map,var_token_vector);

    return variable_map;
}


vector<TOKEN> tokenize(vector<string> asmcodes){
    //必要な変数
    // vector によるtokenの集まり
    vector<TOKEN> token_vector;
    // このlavel mapを参照することでlavelのアドレスがわかる。
    vector<LAVEL_ADDER_INFO> lavel_map;
    // 変数のマップ
    vector<VARIABLE_INFO> variable_map;

    // 変数のマップを作成する。また、その際変数宣言の構文は削除する。
    vector<string> buf_asmcodes;
    for(int i=0;i!=asmcodes.size();i++){
        string asmcode = asmcodes[i];
        if(check_variable(asmcode)){
            variable_map = mapping_variable(asmcode,variable_map);
            continue;
        }
        buf_asmcodes.push_back(asmcode);
    }
    asmcodes = buf_asmcodes;

    // 文字列全体を検査する。
    for(int i=0;i!=asmcodes.size();i++){
        string asmcode = asmcodes[i];
        // アセンブリコード一行分をここで解析する
        TOKEN s = analysis_line(asmcode);
        token_vector.push_back(s);
    }

    // 一行ごとのサイズを割り出す
    token_vector = input_addr_size(token_vector,variable_map);
    // 上からvector をなぞって tokenのlavel情報からlavel mapを生成する。
    lavel_map = lavel_mapping(token_vector);
    // opecode
    token_vector = input_opecode_info(token_vector,variable_map);
    // operand
    token_vector = input_lavel_or_variable(token_vector,lavel_map,variable_map);

    return token_vector;
}