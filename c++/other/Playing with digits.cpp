#include <string>
#include <math.h>

class DigPow
{
public:
  static int digPow(int n, int p){
    auto n_str = std::to_string(n);
    int sum = 0;
    for(char c: n_str) sum += pow(c - '0', p++);
    int mod = sum / n;
    return sum == mod * n
      ? mod
      : -1;
  };
};
