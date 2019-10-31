#include"variable_parse.hpp"
#include<iostream>

using namespace std;

vector<VARIABLE_INFO> variable_parse(vector<VARIABLE_INFO> variable_map,vector<VAR_TOKEN> var_token_vector){
    VARIABLE_INFO p;
    VAR_TOKEN var_token;
    bool write_flag = false;
    for(int i=0;i<var_token_vector.size();i++){
        var_token = var_token_vector[i];
        if(var_token.num==OPERATOR){
            if(var_token.value_str=="="){
                if(write_flag){
                    cout << "err variable parse" << endl;
                }
                write_flag = true;
            }
            continue;
        }
        if(var_token.num==VARIABLE){
            p.variable_name = var_token.value_str;
            continue;
        }
        if(var_token.num==ADDRESS){
            p.value_imm_or_addr = ADDRESS;
            if(write_flag){
                p.value = var_token.value_int;

            }
            continue;
        }
        if(var_token.num==IMMDIATE){
            p.value_imm_or_addr = IMMDIATE;
            if(write_flag){
                p.value = var_token.value_int;
            }
            continue;
        }
    }
    variable_map.push_back(p);
    return variable_map;
}