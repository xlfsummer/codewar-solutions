// https://www.codewars.com/kata/rot13-1/train/cpp

#include <string>
// #include <algorithm>
// #include <cctype>
using namespace std;

// string rot13(string msg)
// {
//     transform(msg.begin(), msg.end(), msg.begin(), [](char c){
//         if(!isalpha(c)) return c;
//         if(c <= 'Z' - 13 || c >= 'a' && c <= 'z' - 13)
//             c += 13;
//         else
//             c -= 13;
//         return (char)c;
//     });

//     return msg;
// }

// clever
string rot13(string msg)
{
    for (char &c: msg){
        switch (c)
        {
            case 'a' ... 'm': case 'A' ... 'M': c += 13; break;
            case 'n' ... 'z': case 'N' ... 'Z': c -= 13; break;
        }
    }
    return msg;
}
