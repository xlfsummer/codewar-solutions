#include <vector>
#include <cmath>

int positive_sum (const std::vector<int> arr){
  int sum = 0;
  for(auto i: arr) sum += (std::abs(i) + i) / 2;
  return sum;
}
