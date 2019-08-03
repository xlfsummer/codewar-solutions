#include <vector>
#include <string>
#include <regex>

int countSmileys(std::vector<std::string> arr)
{
    int count = 0;
    std::regex isSmile("[:;][~-][D)]");
    for(auto s: arr) count += std::regex_match(s, isSmile);
    return count;
}
