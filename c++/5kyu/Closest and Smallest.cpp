// https://www.codewars.com/kata/closest-and-smallest/train/cpp

#include <string>
#include <vector>
#include <algorithm>
#include <tuple> 
#include <iostream> 

namespace Closest
{

    std::vector<std::string> split(std::string str, char divider){
        int prevPos = 0;
        int curPos = 0;
        std::vector<std::string> result;
        while (curPos != std::string::npos)
        {
            curPos = str.find(divider, prevPos);
            result.push_back(str.substr(prevPos, curPos - prevPos));
            prevPos = curPos + 1;
        }
        return result;
    }

    template<typename T>
    unsigned int findIndex(std::vector<T> vec, T value){
        for(int i = 0; i < vec.size(); i++){
            if(vec[i] == value){
                return i;
            }
        }
        return -1;
    }

    int weight(std::string str){
        const char *cs = str.c_str();
        int add = 0;
        for(int i = 0; *(cs + i) != '\0'; i++){
            add += *(cs + i) - '0';
        }
        return add;
    }

    std::vector<std::tuple<int, unsigned int, long long>> closest(const std::string &strng)
    {
        if(strng.empty()) return std::vector<std::tuple<int, unsigned int, long long>> {
            std::make_tuple(0, 0, 0),
            std::make_tuple(0, 0, 0)
        };

        auto vecOrigin = split(strng, ' ');
        std::vector<std::string> vec(vecOrigin.size());
        std::copy(vecOrigin.begin(), vecOrigin.end(), vec.begin());

        std::stable_sort(vec.begin(), vec.end(), [=](std::string a, std::string b){
            return weight(a) - weight(b) < 0;
        });

        int min = INT32_MAX;
        int minIndex = 0;
        for(int i = 0; i < vec.size() - 1; i++){
            auto difference = weight(vec[i + 1]) - weight(vec[i]);
            if(min > difference){
                min = difference;
                minIndex = i;
            }
        }
        std::string a = vec[minIndex];
        std::string b = vec[minIndex + 1];

        return std::vector<std::tuple<int, unsigned int, long long>> {
            std::make_tuple(weight(a), findIndex(vecOrigin, a), std::stoll(a)),
            std::make_tuple(weight(b), findIndex(vecOrigin, b), std::stoll(b))
        };
    }
}

int main(int argc, char const *argv[])
{
    auto a = Closest::closest("103 123 4444 99 2000");
    std::cout << std::get<0>(a[0]) << "," << std::get<1>(a[0]) << "," << std::get<2>(a[0]) << std::endl;
    std::cout << std::get<0>(a[1]) << "," << std::get<1>(a[1]) << "," << std::get<2>(a[1]) << std::endl;
    return 0;
}
