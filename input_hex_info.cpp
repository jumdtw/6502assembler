#include"tokenize.hpp"
#include"input_hex_info.hpp"
#include"calc_addr.hpp"

void input_lda_hex(TOKEN *token){
    // lavel 
    if((!token->Bin_FLAG)&&(!token->Hex_FLAG)&&(!token->Imm_FLAG)){
        token->opecode = LDA_ABS;
    }
    // imm 
    if(token->Imm_FLAG){
        token->opecode = LDA_IMM;
    }
    // hex abs or zero
    if(token->Hex_FLAG&&token->operand <= 0xff){
        token->opecode = LDA_ZERO;
    }else if(token->Hex_FLAG&&token->operand > 0xff){
        token->opecode = LDA_ABS;
    }
    // bin
    if(token->Bin_FLAG){
        token->opecode = LDA_ZERO;
    }
}

void input_sta_hex(TOKEN *token){
    // lavel 
    if((!token->Bin_FLAG)&&(!token->Hex_FLAG)&&(!token->Imm_FLAG)){
        token->opecode = STA_ABS;
    }
    // hex abs or zero
    if(token->Hex_FLAG&&token->operand <= 0xff){
        token->opecode = STA_ZERO;
    }else if(token->Hex_FLAG&&token->operand > 0xff){
        token->opecode = STA_ABS;
    }
    // bin
    if(token->Bin_FLAG){
        token->opecode = STA_ZERO;
    }
}

void input_ora_hex(TOKEN *token){
    // lavel 
    if((!token->Bin_FLAG)&&(!token->Hex_FLAG)&&(!token->Imm_FLAG)){
        token->opecode = ORA_ABS;
    }
    // imm 
    if(token->Imm_FLAG){
        token->opecode = ORA_IMM;
    }
    // hex abs or zero
    if(token->Hex_FLAG&&token->operand <= 0xff){
        token->opecode = ORA_ZERO;
    }else if(token->Hex_FLAG&&token->operand > 0xff){
        token->opecode = ORA_ABS;
    }
    // bin
    if(token->Bin_FLAG){
        token->opecode = ORA_ZERO;
    }
}

void input_jsr_hex(TOKEN *token){
    token->opecode = JSR;
}

void input_rts_hex(TOKEN *token){
    token->opecode = RTS;
}


vector<TOKEN> input_lavel(vector<TOKEN> token_vector,vector<LAVEL_ADDER_INFO> lavel_map){
    TOKEN token;
    for(int i=0;i<token_vector.size();i++){
        token = token_vector[i];
        if((!token.Bin_FLAG)&&(!token.Hex_FLAG)&&(!token.Imm_FLAG)){
            for(int k=0;k<lavel_map.size();k++){
                if(lavel_map[k].lavel.substr(1) == token.lavel){
                    token.operand = lavel_map[k].addr;
                }
            }
            cout << "err : not found lavel : " << token.lavel << endl;
        }
        
    }
}

vector<TOKEN> input_opecode_info(vector<TOKEN> token_vector){
    vector<TOKEN> return_vector;
    TOKEN token;
    for(int i=0;i<token_vector.size();i++){
        token = token_vector[i];
        if(check_lda(token.lavel)){input_lda_hex(&token);return_vector.push_back(token);continue;}
        if(check_sta(token.lavel)){input_sta_hex(&token);return_vector.push_back(token);continue;}
        if(check_ora(token.lavel)){input_ora_hex(&token);return_vector.push_back(token);continue;}
        if(check_jsr(token.lavel)){input_jsr_hex(&token);return_vector.push_back(token);continue;}
        if(check_rts(token.lavel)){input_rts_hex(&token);return_vector.push_back(token);continue;}
    }
}