#include <string>
#include <regex>

bool solution(std::string const &str, std::string const &ending) {
    return std::regex_search(str, std::regex(ending + "$"));
}
