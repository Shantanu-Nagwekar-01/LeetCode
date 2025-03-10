#include <iostream>
using namespace std;
class Solution
{
public:
    bool isUgly(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        while (n % 2 == 0)
        {
            n /= 2;
        }
        while (n % 3 == 0)
        {
            n /= 3;
        }
        while (n % 5 == 0)
        {
            n /= 5;
        }
        return n == 1;
    }
};
int main()
{
    Solution sol;
    int n = 14;
    if (sol.isUgly(n))
    {
        cout << n << " is Ugly Number" << endl;
    }
    else
    {
        cout << n << " is not Ugly Number" << endl;
    }
}