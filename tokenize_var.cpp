#include<algorithm>
#include<cctype>
#include"tokenize_var.hpp"
#include<string>

bool isdigit_my(std::string p){
    if (std::all_of(p.cbegin(), p.cend(), isdigit))
    {
        return true;
    }
    return false;
}