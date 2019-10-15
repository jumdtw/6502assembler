#include"file_controller.hpp"
#include"tokenize.hpp"
#include<fstream>

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

void write_file(vector<TOKEN> token_vector){

}