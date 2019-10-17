#include"file_controller.hpp"
#include"tokenize.hpp"
#include<fstream>
#include<cstdio>

// return_edian_high($4016) -> return 0x40
char return_edian_high(unsigned int code){
    code = code >> 8;
    return (unsigned char)code; 
}

// return_edian_low($4016) -> return 0x16
unsigned char return_edian_low(unsigned int code){
    return (unsigned char)code;
}

bool check_space_tab(string text){
    string space = " ";
    int c = 0;
    for(int i=0;i<text.length();i++){
        if(text[i]==space[0]){
            c++;
        }
    }
    if(text.length()==c){return false;}
    return true;
}


std::vector<std::string> read_file(std::string asmtext){
    string asmcode;
    vector<string> asmcodes;
    std::ifstream ifs(asmtext);
    if (ifs.fail()) {
        std::cerr << "Failed to open file." << std::endl;
        //return -1;
    }
    while (getline(ifs, asmcode)) {
        if(check_space_tab(asmcode)){
            asmcodes.push_back(asmcode);
        }
    }
    return asmcodes;
}

void write_file(vector<TOKEN> token_vector,string asmtext){
    unsigned char low,high;
    ofstream ofs(asmtext, ios::binary);
    const unsigned int file_size_16k = 16384;
    unsigned int file_size_count = 0; 
    unsigned char pate = 0xff,zero = 0x00,end_0x80 = 0x80;

    for(int i=0;i<token_vector.size();i++){
        cout << "0x" << hex << (unsigned int)token_vector[i].opecode << endl;
        ofs.write(reinterpret_cast<char *>(&token_vector[i].opecode),sizeof(token_vector[i].opecode));
        file_size_count += 1;
        if(token_vector[i].size >= 2){
            low = return_edian_low(token_vector[i].operand);
            ofs.write(reinterpret_cast<char *>(&low),sizeof(low));
            cout << "0x" << hex << (unsigned int)low << endl;
            file_size_count += 1;
        }
        if(token_vector[i].size >= 3){
            high = return_edian_high(token_vector[i].operand);
            ofs.write(reinterpret_cast<char *>(&high),sizeof(high));
            cout << "0x" << hex << (unsigned int)high << endl;
            file_size_count += 1;
        }
    }
    
    for(int i=0;i<(file_size_16k-file_size_count-6);i++){
        ofs.write(reinterpret_cast<char *>(&pate),sizeof(pate));
    }
    ofs.write(reinterpret_cast<char *>(&zero),sizeof(zero));
    ofs.write(reinterpret_cast<char *>(&zero),sizeof(zero));
    ofs.write(reinterpret_cast<char *>(&zero),sizeof(zero));
    ofs.write(reinterpret_cast<char *>(&end_0x80),sizeof(end_0x80));
    ofs.write(reinterpret_cast<char *>(&zero),sizeof(zero));
    ofs.write(reinterpret_cast<char *>(&zero),sizeof(zero));

    if(ofs.bad()) {
        cout << "error" << endl;
    }
}