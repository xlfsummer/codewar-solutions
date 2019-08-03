#include "stdio.h"
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> invert (std::vector<int> values)
{
    // way 1
    // for(auto i = values.begin(); i < values.end(); i++){
    //     *i = -*i;
    // }

    // way 2
    // for(auto &i : values) i *= -1;

    //way 3
    transform(values.begin(), values.end(),
        values.begin(), std::negate<int>());

    return values;
}

int main(int argc, char const *argv[])
{
    auto v = invert({1, 2, 3, 4});
  
    std::string result;
    for(auto i = v.begin(); i < v.end(); i++){
        result.append(std::to_string(*i));
        result.push_back( i < v.end() - 1 ? ',' : '\n');
    }

    printf("%s", result.c_str());
    
    return 0;
}
