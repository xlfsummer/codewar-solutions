#include <cmath>
#include <iostream>

using namespace std;

class Evaporator
{
  public:
  static int evaporator(double content, double evap_per_day, double threshold){
    return ceil(log(threshold / 100) / log(1 - evap_per_day / 100));
  }
};

int main(int argc, char const *argv[])
{
    cout << Evaporator::evaporator(10, 10, 10) << endl;
    return 0;
}
