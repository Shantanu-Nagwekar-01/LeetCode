#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution
{
public:
    vector<int> closestPrimes(int left, int right)
    {
        vector<bool> primes = FindPrime(right);
        vector<int> result = {-1, -1};
        int min_d = INT_MAX, prevprime = -1;
        for (int i = right; i >= left; i--)
        { // iterated from right that is greater number to smaller prime
            if (primes[i])
            {
                if (prevprime != -1)
                {
                    min_d = min(min_d, prevprime - i);
                    if (min_d == prevprime - i)
                    {
                        result = {i, prevprime};
                    }
                }
                prevprime = i; // keeping note of previous prime number for calculating difference
            }
        }
        return result;
    }
    // Used Sieve of Eratosthenes to mark numbers that are primes.
    vector<bool> FindPrime(int limit)
    {
        vector<bool> primes(limit + 1, true);
        primes[0] = primes[1] = false;
        for (int i = 2; i <= sqrt(limit); i++)
        {
            if (primes[i])
            {
                for (int num = i * 2; num <= limit; num += i)
                {
                    if (primes[num])
                        primes[num] = false;
                }
            }
        }
        return primes;
    }
};

int main()
{
    Solution sol;
    int left = 10, right = 19;
    vector<int> result = sol.closestPrimes(left, right);
    cout << "[";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << "]" << endl;
}