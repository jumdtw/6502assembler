#include"calc_addr.hpp"
#include"tokenize.hpp"


void input_lda_size(TOKEN *token,vector<VARIABLE_INFO> variable_map){

    // operand == variable
    for(int i=0;i<variable_map.size();i++){
        if(variable_map[i].variable_name==token->operandstr){

            if(variable_map[i].value_imm_or_addr==IMMDIATE){
                token->size = 0x02;
                return;
            }
            if(variable_map[i].value_imm_or_addr==ADDRESS){
                if(variable_map[i].value > 0xff){
                    token->size = 0x03;
                }else{
                    token->size = 0x02;
                }
                return;
            }
        }
    }
    
    // operand == lavel
    if((!token->Bin_FLAG)&&(!token->Hex_FLAG)&&(!token->Imm_FLAG)){
        token->size = 0x03;
        return;
    }
    // indirect 
    if(token->Indi_FLAG&&token->Imm_FLAG&&token->operand <= 0xff){
        token->size = 0x02;
        return;
    }else if(token->Indi_FLAG&&token->Imm_FLAG&&token->operand > 0xff){
        token->size = 0x03;
        return;
    }else if(token->Indi_FLAG){
        token->size = 0x02;
        return;
    }
    // imm
    if(token->Imm_FLAG){
        token->size = 0x02;
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

void input_ldx_size(TOKEN *token,vector<VARIABLE_INFO> variable_map){

    /*
    // operand == lavel
    if((!token->Bin_FLAG)&&(!token->Hex_FLAG)&&(!token->Imm_FLAG)){
        token->size = 0x03;
        return;
    }
    */
    // imm
    if(token->Imm_FLAG){
        token->size = 0x02;
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

void input_sta_size(TOKEN *token,vector<VARIABLE_INFO> variable_map){

    // operand == variable
    for(int i=0;i<variable_map.size();i++){
        if(variable_map[i].variable_name==token->operandstr){

            if(variable_map[i].value_imm_or_addr==IMMDIATE){
                token->size = 0x02;
                return;
            }
            if(variable_map[i].value_imm_or_addr==ADDRESS){
                if(variable_map[i].value > 0xff){
                    token->size = 0x03;
                }else{
                    token->size = 0x02;
                }
                return;
            }
        }
    }

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

void input_jmp_size(TOKEN *token){
    token->size = 0x03;    
}

void input_rts_size(TOKEN *token){
    token->size = 0x01;    
}

void input_rti_size(TOKEN *token){
    token->size = 0x01;    
}

void input_dec_size(TOKEN *token){
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

void input_beq_size(TOKEN *token){
    token->size = 0x02;    
}

void input_inc_size(TOKEN *token){
    /*
    // operand == lavel
    if((!token->Bin_FLAG)&&(!token->Hex_FLAG)&&(!token->Imm_FLAG)){
        token->size = 0x03;
        return;
    }
    // imm
    if(token->Imm_FLAG){
        token->size = 0x02;
    }
    */
    // check lda zero
    if(token->operand <= 0xff){
        token->size = 0x02;
        return;
    }else{
        token->size = 0x03;
        return;
    }
}

// -----------------checker-------------------------


bool check_lda(string str){
    if(str=="lda"||str=="LDA"){
        return true;
    }
    return false;
}

bool check_ldx(string str){
    if(str=="ldx"||str=="LDX"){
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

bool check_jmp(string str){
    if(str=="jmp"||str=="JMP"){
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

bool check_rti(string str){
    if(str=="rti"||str=="RTI"){
        return true;
    }
    return false;
}

bool check_dec(string str){
    if(str=="dec"||str=="DEC"){
        return true;
    }
    return false;
}

bool check_beq(string str){
    if(str=="beq"||str=="BEQ"){
        return true;
    }
    return false;
}

bool check_inc(string str){
    if(str=="inc"||str=="INC"){
        return true;
    }
    return false;
}

vector<TOKEN> input_addr_size(vector<TOKEN> token_vector,vector<VARIABLE_INFO> variable_map){
    
    for(int i=0;i!=token_vector.size();i++){
        if(check_lda(token_vector[i].opecodestr)){input_lda_size(&token_vector[i],variable_map);continue;}
        if(check_ldx(token_vector[i].opecodestr)){input_ldx_size(&token_vector[i],variable_map);continue;}
        if(check_sta(token_vector[i].opecodestr)){input_sta_size(&token_vector[i],variable_map);continue;}
        if(check_ora(token_vector[i].opecodestr)){input_ora_size(&token_vector[i]);continue;}
        if(check_jmp(token_vector[i].opecodestr)){input_jmp_size(&token_vector[i]);continue;}
        if(check_jsr(token_vector[i].opecodestr)){input_jsr_size(&token_vector[i]);continue;}
        if(check_rts(token_vector[i].opecodestr)){input_rts_size(&token_vector[i]);continue;}
        if(check_rti(token_vector[i].opecodestr)){input_rti_size(&token_vector[i]);continue;}
        if(check_dec(token_vector[i].opecodestr)){input_dec_size(&token_vector[i]);continue;}
        if(check_beq(token_vector[i].opecodestr)){input_beq_size(&token_vector[i]);continue;}
        if(check_inc(token_vector[i].opecodestr)){input_inc_size(&token_vector[i]);continue;}
    }
    return token_vector;
}