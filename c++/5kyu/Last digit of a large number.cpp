#include <string>
#include <iostream>
#include <cmath>

// a ^ b
//      1 2 3 4 5 6 7 8 ...
// 0 -> 0
// 1 -> 1
// 2 -> 2 4 8 6
// 3 -> 3 9 7 1
// 4 -> 4 6
// 5 -> 5
// 6 -> 6
// 7 -> 7 9 3 1
// 8 -> 8 4 2 6
// 9 -> 9 1
int last_digit(std::string str1, std::string str2) {
    if(str2 == "0") return 1;
    int aLastDigit = str1[str1.length() - 1] - '0';
    // int map[] = {1, 1, 4, 4, 2, 1, 1, 4, 4, 2}; // 这些 4 取余都为 0, 可以简化为 4
    int str2L = str2.length();
    int numB = std::stoi(str2.substr(std::max(str2L - 2, 0), str2L));
    // int mod = (numB + 3) % map[aLastDigit] + 1;
    // int mod = (numB + 3) % 4 + 1;
    int mod = numB % 4 + 4;
    return (int)std::pow(aLastDigit, mod) % 10;
}

int main(int argc, char const *argv[])
{
    return 0;
}
