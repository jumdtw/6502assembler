#include"file_controller.hpp"
#include"tokenize.hpp"
#include<fstream>
#include<cstdio>

std::vector<std::string> read_file(std::string asmtext){
    string asmcode;
    vector<string> asmcodes;
    std::ifstream ifs(asmtext);
    if (ifs.fail()) {
        std::cerr << "Failed to open file." << std::endl;
        //return -1;
    }
    while (getline(ifs, asmcode)) {
        asmcodes.push_back(asmcode);
    }
    return asmcodes;
}

void write_file(vector<TOKEN> token_vector,string asmtext){
    ofstream ofs(asmtext, ios::binary);
    ofs.write(reinterpret_cast<char *>(&token_vector[0].opecode),sizeof(token_vector[0].opecode));
    if(ofs.bad()) {
        cout << "error" << endl;
    }
}