#include <vector>
#include <string>

int countSmileys(std::vector<std::string> arr)
{
    int count = 0;
    for(auto s: arr) isSmiley(s) && count++;
    return count;
}

bool isSmiley(std::string s){
    int i = 0;
    if(s[i] != ':' && s[i] != ';') return false;
    i++;
    if(s[i] == '-' || s[i] == '~') i++;
    if(s[i] == ')' || s[i] == 'D') return true;
        return false;
}
