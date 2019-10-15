#include"calc_addr.hpp"
#include"tokenize.hpp"


void input_lda_size(TOKEN *token){
    // operand == lavel
    if((!token->Bin_FLAG)&&(!token->Hex_FLAG)&&(!token->Imm_FLAG)){
        token->size = 0x03;
        return;
    }
    // imm
    if(token->Imm_FLAG){
        token->size = 0x02;
    }
    // check lda zero
    if(token->operand <= 0xff){
        token->size = 0x02;
        return;
    }else{
        token->size = 0x03;
        return;
    }
}

void input_sta_size(TOKEN *token){
    // operand == lavel
    if((!token->Bin_FLAG)&&(!token->Hex_FLAG)&&(!token->Imm_FLAG)){
        token->size = 0x03;
        return;
    }
    // check lda zero
    if(token->operand <= 0xff){
        token->size = 0x02;
        return;
    }else{
        token->size = 0x03;
        return;
    }
}

void input_ora_size(TOKEN *token){
    // operand == lavel
    if((!token->Bin_FLAG)&&(!token->Hex_FLAG)&&(!token->Imm_FLAG)){
        token->size = 0x03;
        return;
    }
    // imm
    if(token->Imm_FLAG){
        token->size = 0x02;
    }
    // check lda zero
    if(token->operand <= 0xff){
        token->size = 0x02;
        return;
    }else{
        token->size = 0x03;
        return;
    }
}

void input_jsr_size(TOKEN *token){
    token->size = 0x03;
}

void input_rts_size(TOKEN *token){
    token->size = 0x01;    
}


bool check_lda(string str){
    if(str=="lda"||str=="LDA"){
        return true;
    }
    return false;
}

bool check_sta(string str){
    if(str=="sta"||str=="STA"){
        return true;
    }
    return false;
}

bool check_ora(string str){
    if(str=="ora"||str=="ORA"){
        return true;
    }
    return false;
}

bool check_jsr(string str){
    if(str=="jsr"||str=="JSR"){
        return true;
    }
    return false;
}

bool check_rts(string str){
    if(str=="rts"||str=="RTS"){
        return true;
    }
    return false;
}

vector<TOKEN> input_addr_size(vector<TOKEN> token_vector){
    for(int i=0;i!=token_vector.size();i++){
        if(check_lda(token_vector[i].opecodestr)){input_lda_size(&token_vector[i]);continue;}
        if(check_sta(token_vector[i].opecodestr)){input_sta_size(&token_vector[i]);continue;}
        if(check_ora(token_vector[i].opecodestr)){input_ora_size(&token_vector[i]);continue;}
        if(check_jsr(token_vector[i].opecodestr)){input_jsr_size(&token_vector[i]);continue;}
        if(check_rts(token_vector[i].opecodestr)){input_rts_size(&token_vector[i]);continue;}
    }
    return token_vector;
}