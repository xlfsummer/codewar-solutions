#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
// #include <iostream>

typedef unsigned long long num_t;

class Fracts
{
public:
    static std::string convertFrac(std::vector<std::vector<num_t>> &lst){
        std::vector<num_t> numToFindLCM(lst.size());
        std::transform(lst.begin(), lst.end(), numToFindLCM.begin(), 
            [](std::vector<num_t> pair){ return Fracts::reduction(pair)[1]; }
        );
        num_t D = Fracts::lcmList(numToFindLCM);

        std::string v;
        for(auto pair: lst){
            auto a = pair[0], b = pair[1];
            auto mod = D / b * a;

            v.push_back('(');
            v.append(std::to_string(mod));
            v.push_back(',');
            v.append(std::to_string(D));
            v.push_back(')');
        }
        return v;
    }

    static std::vector<num_t> reduction(std::vector<num_t> const input){
        auto a = input[0], b = input[1];
        auto gcd = Fracts::gcd(a, b);
        return { a / gcd, b / gcd };
    }

    static num_t lcmList (std::vector<num_t> v){
        auto lcm = std::accumulate(v.begin(), v.end(), 1ULL, Fracts::lcm);
        return lcm;
    }

    static num_t lcm (num_t a, num_t b){
        return a * b / Fracts::gcd(a, b);
    }

    static num_t gcd (num_t a, num_t b){
        auto max = std::max(a, b);
        auto min = std::min(a, b);
        auto r = max % min;
        if(r) return gcd(min, r);
        else return min;
    }
};


int main(int argc, char const *argv[])
{
    std::vector<std::vector<num_t>> v = { {1, 2}, {1, 3}, {1, 4} };
    auto s = Fracts::convertFrac(v);
    // std::cout << s << std::endl;
    return 0;
}
