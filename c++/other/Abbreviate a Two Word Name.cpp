#include <string>
#include "stdio.h"

std::string abbrevName(std::string name){
    char c1 = toupper(name[0]);
    char c2 = toupper(name[name.find(' ') + 1]);
    return { c1, '.', c2 };
}

int main (int argc, char* argv[]){

    auto input = std::string(argv[1]);
    input.append(" ");
    input.append(argv[2]);
    printf("input is %s\n", input.c_str());
    std::string a = abbrevName(input).append("\n").c_str();
    const char * result = a.c_str();
    printf("result is %s\n", result);
    // auto b = { 1 };
    
    return 0;
    
}
