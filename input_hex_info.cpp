#include"tokenize.hpp"
#include"input_hex_info.hpp"
#include"calc_addr.hpp"

void input_lda_hex(TOKEN *token,vector<VARIABLE_INFO> variable_map){
    
    // lavel or variable
    if((!token->Bin_FLAG)&&(!token->Hex_FLAG)&&(!token->Imm_FLAG)){
        for(int i=0;i<variable_map.size();i++){
            if(token->operandstr==variable_map[i].variable_name){
                if(variable_map[i].value_imm_or_addr==IMMDIATE){
                    token->opecode = LDA_IMM;
                    return;
                }
            }
        }
        if(token->size==0x02){
            token->opecode = LDA_ZERO;
        }else{
            token->opecode = LDA_ABS;
        }
        return;
    }
    // indirect 
    if(token->Indi_FLAG&&token->Imm_FLAG&&token->operand <= 0xff){
        token->opecode = LDA_ZERO_X;
        return;
    }else if(token->Indi_FLAG&&token->Imm_FLAG&&token->operand > 0xff){
        token->opecode = LDA_ABS_X;
        return;
    }else if(token->Indi_FLAG){
        token->opecode = LDA_INDI;
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

void input_ldx_hex(TOKEN *token){
    /*
    // lavel 
    if((!token->Bin_FLAG)&&(!token->Hex_FLAG)&&(!token->Imm_FLAG)){
        token->opecode = LDA_ABS;
        return;
    }
    */
    // imm 
    if(token->Imm_FLAG){
        token->opecode = LDX_IMM;
        return;
    }
    
    // hex abs or zero
    if(token->Hex_FLAG&&token->operand <= 0xff){
        token->opecode = LDX_ZERO;
        return;
    }else if(token->Hex_FLAG&&token->operand > 0xff){
        token->opecode = LDX_ABS;
        return;
    }
    // bin
    if(token->Bin_FLAG){
        token->opecode = LDX_ZERO;
        return;
    }
    
}

void input_sta_hex(TOKEN *token){
    // lavel or variable
    if((!token->Bin_FLAG)&&(!token->Hex_FLAG)&&(!token->Imm_FLAG)){
        if(token->size==0x02){
            token->opecode = STA_ZERO;
        }else{
            token->opecode = STA_ABS;
        }
        return;
    }

    // indirect 
    if(token->Indi_FLAG&&token->Imm_FLAG&&token->operand <= 0xff){
        token->opecode = STA_ZERO_X;
        return;
    }else if(token->Indi_FLAG&&token->Imm_FLAG&&token->operand > 0xff){
        token->opecode = STA_ABS_X;
        return;
    }else if(token->Indi_FLAG){
        token->opecode = STA_INDI;
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

void input_rti_hex(TOKEN *token){
    token->opecode = RTI;
    return;
}

void input_dec_hex(TOKEN *token){
    // variable
    if(token->size==0x02){
        token->opecode = DEC_ZERO;
        return;
    }
    // lavel 
    if((!token->Bin_FLAG)&&(!token->Hex_FLAG)&&(!token->Imm_FLAG)){
        token->opecode = DEC_ABS;
        return;
    }
    // hex abs or zero
    if(token->Hex_FLAG&&token->operand <= 0xff){
        token->opecode = DEC_ZERO;
        return;
    }else if(token->Hex_FLAG&&token->operand > 0xff){
        token->opecode = DEC_ABS;
        return;
    }
    // bin
    if(token->Bin_FLAG){
        token->opecode = DEC_ZERO;
        return;
    }
}

void input_dex_hex(TOKEN *token){
    token->opecode = DEX;
}

void input_beq_hex(TOKEN *token){
    token->opecode = BEQ;
}

void input_bne_hex(TOKEN *token){
    token->opecode = BNE;
}

void input_inc_hex(TOKEN *token){
    /*
    // lavel 
    if((!token->Bin_FLAG)&&(!token->Hex_FLAG)&&(!token->Imm_FLAG)){
        token->opecode = ORA_ABS;
        return;
    }
    */
    // hex abs or zero
    if(token->Hex_FLAG&&token->operand <= 0xff){
        token->opecode = INC_ZERO;
        return;
    }else if(token->Hex_FLAG&&token->operand > 0xff){
        token->opecode = INC_ABS;
        return;
    }
    // bin
    if(token->Bin_FLAG){
        token->opecode = INC_ZERO;
        return;
    }
}

void input_adc_hex(TOKEN *token){
    /*
    // lavel 
    if((!token->Bin_FLAG)&&(!token->Hex_FLAG)&&(!token->Imm_FLAG)){
        token->opecode = ORA_ABS;
        return;
    }
    */
    // hex abs or zero
    if(token->Hex_FLAG&&token->operand <= 0xff){
        token->opecode = ADC_ZERO;
        return;
    }else if(token->Hex_FLAG&&token->operand > 0xff){
        token->opecode = ADC_ABS;
        return;
    }
    // bin
    if(token->Bin_FLAG){
        token->opecode = ADC_ZERO;
        return;
    }
}

void input_sbc_hex(TOKEN *token){
    /*
    // lavel 
    if((!token->Bin_FLAG)&&(!token->Hex_FLAG)&&(!token->Imm_FLAG)){
        token->opecode = ORA_ABS;
        return;
    }
    */
    // hex abs or zero
    if(token->Hex_FLAG&&token->operand <= 0xff){
        token->opecode = SBC_ZERO;
        return;
    }else if(token->Hex_FLAG&&token->operand > 0xff){
        token->opecode = SBC_ABS;
        return;
    }
    // bin
    if(token->Bin_FLAG){
        token->opecode = SBC_ZERO;
        return;
    }
}

void input_sei_hex(TOKEN *token){
    token->opecode = SEI;
}

void input_clc_hex(TOKEN *token){
    token->opecode = CLC;
}

void input_sec_hex(TOKEN *token){
    token->opecode = SEC;
}

void input_pha_hex(TOKEN *token){
    token->opecode = PHA;
}

void input_pla_hex(TOKEN *token){
    token->opecode = PLA;
}

int search_label(string operand,vector<LAVEL_ADDER_INFO> lavel_map){
    for(int k=0;k<lavel_map.size();k++){
        if(lavel_map[k].lavel.substr(1) == operand){
            return lavel_map[k].addr;
        }
    }
    return 0;
}

bool check_branch(string opecode){
    if(check_beq(opecode)||check_bne(opecode)){
        return true;
    }
    return false;
}

vector<TOKEN> input_lavel_or_variable(vector<TOKEN> token_vector,vector<LAVEL_ADDER_INFO> lavel_map,vector<VARIABLE_INFO> variable_map){
    vector<TOKEN> return_vector;
    TOKEN token;
    int addr = 0x8000;

    for(int i=0;i<token_vector.size();i++){
        token = token_vector[i];
        //分岐命令
        if(check_branch(token.opecodestr)){
            int bcode_addr = addr + 2;
            int des_addr = search_label(token.operandstr,lavel_map);
            int branch_operand = des_addr - bcode_addr;
            if(branch_operand >= 0){
                token.operand = branch_operand;
            }else{
                token.operand = 256 + branch_operand;
            }

        }else if((!token.Bin_FLAG)&&(!token.Hex_FLAG)&&(!token.Imm_FLAG)){
            // lavel            
            token.operand = search_label(token.operandstr,lavel_map);
            // variable
            for(int k=0;k<variable_map.size();k++){
                if(variable_map[k].variable_name == token.operandstr){
                    token.operand = variable_map[k].value;
                }
            }
        }
        addr += token.size;
        return_vector.push_back(token);
    }
    return return_vector;
}

vector<TOKEN> input_opecode_info(vector<TOKEN> token_vector,vector<VARIABLE_INFO> variable_map){
    vector<TOKEN> return_vector;
    TOKEN token;
    for(int i=0;i<token_vector.size();i++){
        token = token_vector[i];
        if(check_lda(token.opecodestr)){input_lda_hex(&token,variable_map);return_vector.push_back(token);continue;}
        if(check_ldx(token.opecodestr)){input_ldx_hex(&token);return_vector.push_back(token);continue;}
        if(check_sta(token.opecodestr)){input_sta_hex(&token);return_vector.push_back(token);continue;}
        if(check_ora(token.opecodestr)){input_ora_hex(&token);return_vector.push_back(token);continue;}
        if(check_jmp(token.opecodestr)){input_jmp_hex(&token);return_vector.push_back(token);continue;}
        if(check_jsr(token.opecodestr)){input_jsr_hex(&token);return_vector.push_back(token);continue;}
        if(check_rts(token.opecodestr)){input_rts_hex(&token);return_vector.push_back(token);continue;}
        if(check_rti(token.opecodestr)){input_rti_hex(&token);return_vector.push_back(token);continue;}
        if(check_dec(token.opecodestr)){input_dec_hex(&token);return_vector.push_back(token);continue;}
        if(check_dex(token.opecodestr)){input_dex_hex(&token);return_vector.push_back(token);continue;}
        if(check_beq(token.opecodestr)){input_beq_hex(&token);return_vector.push_back(token);continue;}
        if(check_bne(token.opecodestr)){input_bne_hex(&token);return_vector.push_back(token);continue;}
        if(check_inc(token.opecodestr)){input_inc_hex(&token);return_vector.push_back(token);continue;}
        if(check_adc(token.opecodestr)){input_adc_hex(&token);return_vector.push_back(token);continue;}
        if(check_sbc(token.opecodestr)){input_sbc_hex(&token);return_vector.push_back(token);continue;}
        if(check_sei(token.opecodestr)){input_sei_hex(&token);return_vector.push_back(token);continue;}
        if(check_clc(token.opecodestr)){input_clc_hex(&token);return_vector.push_back(token);continue;}
        if(check_sec(token.opecodestr)){input_sec_hex(&token);return_vector.push_back(token);continue;}
        if(check_pha(token.opecodestr)){input_pha_hex(&token);return_vector.push_back(token);continue;}
        if(check_pla(token.opecodestr)){input_pla_hex(&token);return_vector.push_back(token);continue;}
        cout << "not found opecode" << endl;
        exit(1);
    }
    return return_vector;
}