#ifndef FILE_CONTROLLER_H
#define FILE_CONTROLLER_H

#include<vector>
#include<string>
#include"tokenize.hpp"

std::vector<std::string> read_file(std::string file_name);
void write_file(vector<TOKEN> token_vector,string asmtext);


#endif 