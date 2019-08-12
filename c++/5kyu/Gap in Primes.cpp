// https://www.codewars.com/kata/gap-in-primes/train/cpp

#include <cmath>
#include <utility>

using ll = long long;

class PrimeGenerator
{
public:
    PrimeGenerator(ll begin, ll end)
    {
        this->begin = begin;
        this->current = begin;
        this->end = end;
    }
    ll nextPrime()
    {
        if(this->current == 0) return 0;
        for(ll i = this->current + 1; i <= this->end; i++){
            if(this->isPrime(i)){
                return this->current = i;
            }
        }
        return this->current = 0;
    }

private:
    ll begin;
    ll current;
    ll end;
    bool isPrime(ll num)
    {
        ll max = (ll)(std::sqrt(num));
        // 可以通过单独判断 2 的情况，使 i 的步长变为 2, 加快判断速度
        // 还可以判断 6k + 1 和 6k - 1 的情况
        for(ll i = 2; i <= max; i++) if(num % i == 0) return false;
        return true;
    }
};

class GapInPrimes
{
public:
    static std::pair<ll, ll> gap(int g, ll m, ll n)
    {
        PrimeGenerator gen(m, n);

        ll a = gen.nextPrime();
        for(ll b = gen.nextPrime(); b != 0; a = b, b = gen.nextPrime()){
            if(b - a == g) return {a, b};
        }
        return {0, 0};
    }
};
