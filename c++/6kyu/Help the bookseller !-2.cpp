#include <vector>
#include <string>
#include <map>
#include <iostream>

class StockList
{
public:
    static std::string stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories)
    {
        std::string result;
        std::map<char, int> map;

        // 时间复杂度 m + n
        for (auto art : lstOfArt)
            map[art[0]] += std::stoi(art.substr(art.find(" ")));
        
        for (auto catgory : categories)
            result += "(" + catgory + " : " + std::to_string(map[catgory[0]]) + ")";

        if(!result.empty()) result = result.substr(3);

        return result;
    }
};

int main()
{
    std::vector<std::string> lstOfArt {"ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"};
    std::vector<std::string> categories {"A", "B", "C", "W"} ;
    std::cout << StockList::stockSummary(
        lstOfArt, categories
    ) << std::endl;
    return 0;
}
