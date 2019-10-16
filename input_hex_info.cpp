#include"tokenize.hpp"
#include"input_hex_info.hpp"
#include"calc_addr.hpp"

void input_lda_hex(TOKEN *token){
    
    // lavel 
    if((!token->Bin_FLAG)&&(!token->Hex_FLAG)&&(!token->Imm_FLAG)){
        token->opecode = LDA_ABS;
        return;
    }
    // imm 
    if(token->Imm_FLAG){
        token->opecode = LDA_IMM;
        return;
    }
    // hex abs or zero
    if(token->Hex_FLAG&&token->operand <= 0xff){
        token->opecode = LDA_ZERO;
        return;
    }else if(token->Hex_FLAG&&token->operand > 0xff){
        token->opecode = LDA_ABS;
        return;
    }
    // bin
    if(token->Bin_FLAG){
        token->opecode = LDA_ZERO;
        return;
    }
}

void input_sta_hex(TOKEN *token){
    // lavel 
    if((!token->Bin_FLAG)&&(!token->Hex_FLAG)&&(!token->Imm_FLAG)){
        token->opecode = STA_ABS;
        return;
    }
    // hex abs or zero
    if(token->Hex_FLAG&&token->operand <= 0xff){
        token->opecode = STA_ZERO;
        return;
    }else if(token->Hex_FLAG&&token->operand > 0xff){
        token->opecode = STA_ABS;
        return;
    }
    // bin
    if(token->Bin_FLAG){
        token->opecode = STA_ZERO;
        return;
    }
}

void input_ora_hex(TOKEN *token){
    // lavel 
    if((!token->Bin_FLAG)&&(!token->Hex_FLAG)&&(!token->Imm_FLAG)){
        token->opecode = ORA_ABS;
        return;
    }
    // imm 
    if(token->Imm_FLAG){
        token->opecode = ORA_IMM;
        return;
    }
    // hex abs or zero
    if(token->Hex_FLAG&&token->operand <= 0xff){
        token->opecode = ORA_ZERO;
        return;
    }else if(token->Hex_FLAG&&token->operand > 0xff){
        token->opecode = ORA_ABS;
        return;
    }
    // bin
    if(token->Bin_FLAG){
        token->opecode = ORA_ZERO;
        return;
    }
}

void input_jmp_hex(TOKEN *token){
    token->opecode = JMP_ABS;
    return;
}

void input_jsr_hex(TOKEN *token){
    token->opecode = JSR;
    return;
}

void input_rts_hex(TOKEN *token){
    token->opecode = RTS;
    return;
}


vector<TOKEN> input_lavel(vector<TOKEN> token_vector,vector<LAVEL_ADDER_INFO> lavel_map){
    vector<TOKEN> return_vector;
    TOKEN token;
    for(int i=0;i<token_vector.size();i++){
        token = token_vector[i];
        if((!token.Bin_FLAG)&&(!token.Hex_FLAG)&&(!token.Imm_FLAG)){
            for(int k=0;k<lavel_map.size();k++){
                cout << lavel_map[k].lavel.substr(1) << " : " << token.lavel << endl;
                if(lavel_map[k].lavel.substr(1) == token.operandstr){
                    token.operand = lavel_map[k].addr;
                }
            }
            cout << "err : not found lavel : " << token.lavel << endl;
        }
        return_vector.push_back(token);
    }
    return return_vector;
}

vector<TOKEN> input_opecode_info(vector<TOKEN> token_vector){
    vector<TOKEN> return_vector;
    TOKEN token;
    for(int i=0;i<token_vector.size();i++){
        token = token_vector[i];
        if(check_lda(token.opecodestr)){input_lda_hex(&token);return_vector.push_back(token);}
        if(check_sta(token.opecodestr)){input_sta_hex(&token);return_vector.push_back(token);}
        if(check_ora(token.opecodestr)){input_ora_hex(&token);return_vector.push_back(token);}
        if(check_jmp(token.opecodestr)){input_jmp_hex(&token);return_vector.push_back(token);}
        if(check_jsr(token.opecodestr)){input_jsr_hex(&token);return_vector.push_back(token);}
        if(check_rts(token.opecodestr)){input_rts_hex(&token);return_vector.push_back(token);}
    }
    return return_vector;
}