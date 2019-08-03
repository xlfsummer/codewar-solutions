#include <vector>

std::vector<int> countPositivesSumNegatives(std::vector<int> input)
{
    if(input.empty()) return {};
    int countP = 0;
    int sumN = 0;
    for(int i: input) i > 0 ? countP++ : (sumN += i);
    return {countP , sumN};
}
