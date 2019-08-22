// https://www.codewars.com/kata/565abd876ed46506d600000d/train/cpp

#include <cmath>
#include <functional>
#include <iostream>

class SimpsonIntegration
{
public:
    static double simpson(int n){
        auto f = [](double x){ return 3.0 / 2.0 * std::pow(std::sin(x), 3.0); };
        auto sigma = [](int upperBound, std::function<double (int)> fn){
            double add;
            for(int i = 1; i <= upperBound; i++) add += fn(i);
            return add;
        };

        const double a = 0;
        const double b = M_PI;
        const double h = (b - a)/n;

        return (b - a) / (3.0 * n) * (
            f(a) + f(b)
            + 4.0 * sigma(n / 2, [=](int i){ return f(a + (2 * i - 1) * h); }) 
            + 2.0 * sigma(n / 2 - 1, [=](int i){ return f(a + 2 * i * h); })
        );
    }
};


int main(int argc, char const *argv[])
{
    SimpsonIntegration::simpson(20);
    return 0;
}
