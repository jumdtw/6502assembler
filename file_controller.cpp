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

bool check_comment(string text){
    string comment = ";";
    for(int i=0;i<text.length();i++){
        if(text[i]==comment[0]){
            return false;
        }
    }
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
            if(check_comment(asmcode)){
                asmcodes.push_back(asmcode);
            }
        }
    }
    return asmcodes;
}

void write_file(vector<TOKEN> token_vector,string asmtext){
    unsigned char low,high;
    unsigned char main_low = 0x00,main_high = 0x80;
    unsigned char NMI_low = 0x00,NMI_high = 0x00;
    ofstream ofs(asmtext, ios::binary);
    char outfile[] = "C:/Users/ttnmr/HOME/amegurefami/kotoha.nes";  //読み込むファイルの指定
    ifstream fin( outfile, ios::in | ios::binary );
    const unsigned int file_size_16k = 16384;
    unsigned int file_size_count = 0; 
    unsigned char pate = 0xff,zero = 0x00,N=0x4e,E=0x45,S=0x53,sub=0x1a,size=0x01;
    int base_addr = 0x8000;
    std::string Main_label = ".main";
    std::string NMI_label = ".NMI";

    if (!fin){
        cout << "readファイル が開けません";
        return;
    }

    
    ofs.write(reinterpret_cast<char *>(&N),sizeof(N));
    ofs.write(reinterpret_cast<char *>(&E),sizeof(E));
    ofs.write(reinterpret_cast<char *>(&S),sizeof(S));
    ofs.write(reinterpret_cast<char *>(&sub),sizeof(sub));
    ofs.write(reinterpret_cast<char *>(&size),sizeof(size));
    ofs.write(reinterpret_cast<char *>(&size),sizeof(size));
    ofs.write(reinterpret_cast<char *>(&zero),sizeof(zero));
    ofs.write(reinterpret_cast<char *>(&zero),sizeof(zero));
    ofs.write(reinterpret_cast<char *>(&zero),sizeof(zero));
    ofs.write(reinterpret_cast<char *>(&zero),sizeof(zero));
    ofs.write(reinterpret_cast<char *>(&zero),sizeof(zero));
    ofs.write(reinterpret_cast<char *>(&zero),sizeof(zero));
    ofs.write(reinterpret_cast<char *>(&zero),sizeof(zero));
    ofs.write(reinterpret_cast<char *>(&zero),sizeof(zero));
    ofs.write(reinterpret_cast<char *>(&zero),sizeof(zero));
    ofs.write(reinterpret_cast<char *>(&zero),sizeof(zero));
    
    for(int i=0;i<token_vector.size();i++){
        if(token_vector[i].lavel==Main_label){
            main_low = return_edian_low(base_addr);
            main_high = return_edian_high(base_addr);
        }
        if(token_vector[i].lavel==NMI_label){
            NMI_low = return_edian_low(base_addr);
            NMI_high = return_edian_high(base_addr);
        }
        base_addr += token_vector[i].size;
        //cout << "0x" << hex << (unsigned int)token_vector[i].opecode << endl;
        ofs.write(reinterpret_cast<char *>(&token_vector[i].opecode),sizeof(token_vector[i].opecode));
        file_size_count += 1;
        if(token_vector[i].size >= 2){
            low = return_edian_low(token_vector[i].operand);
            ofs.write(reinterpret_cast<char *>(&low),sizeof(low));
            //cout << "0x" << hex << (unsigned int)low << endl;
            file_size_count += 1;
        }
        if(token_vector[i].size >= 3){
            high = return_edian_high(token_vector[i].operand);
            ofs.write(reinterpret_cast<char *>(&high),sizeof(high));
            //cout << "0x" << hex << (unsigned int)high << endl;
            file_size_count += 1;
        }
    }
    
    for(int i=0;i<(file_size_16k-file_size_count-6);i++){
        ofs.write(reinterpret_cast<char *>(&pate),sizeof(pate));
    }
    ofs.write(reinterpret_cast<char *>(&NMI_low),sizeof(NMI_low));
    ofs.write(reinterpret_cast<char *>(&NMI_high),sizeof(NMI_high));
    ofs.write(reinterpret_cast<char *>(&main_low),sizeof(main_low));
    ofs.write(reinterpret_cast<char *>(&main_high),sizeof(main_high));
    ofs.write(reinterpret_cast<char *>(&zero),sizeof(zero));
    ofs.write(reinterpret_cast<char *>(&zero),sizeof(zero));

    char buf_read;

    for(int i=0;i<4096;i++){
        fin.read( ( char * ) &buf_read, sizeof( zero ) );
        ofs.write(reinterpret_cast<char *>(&buf_read),sizeof(zero));
    }

    for(int i=0;i<4096;i++){
        ofs.write(reinterpret_cast<char *>(&zero),sizeof(zero));
    }

    if(ofs.bad()) {
        cout << "error" << endl;
    }
}