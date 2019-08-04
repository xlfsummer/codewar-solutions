#include <vector>
#include <string>
#include <iostream>

class StockList
{
public:
    static std::string stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories)
    {
        std::string result;
        if(lstOfArt.empty() || categories.empty()) return result;
        for (auto catgory : categories)
        {
            int quantity = 0;
            for (auto art : lstOfArt) if(art[0] == catgory[0]) 
                quantity += std::stoi(art.substr(art.find(" ")));
            result += "(" + catgory + " : " + std::to_string(quantity) + ") - ";
        }
        if(result != "") result = result.substr(0, result.length() - 3);
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
