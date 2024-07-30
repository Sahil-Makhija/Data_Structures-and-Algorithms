#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    int countWaysHelper(int n, int k, int index, int c)
    {
        if (index > n - 1)
        {
            return 1;
        }

        int totalWays;

        if (c == 0)
        {
            totalWays = k * countWaysHelper(n, k, index + 1, 1);
        }
        else if (c == 1)
        {
            int case1 = (k - 1) * countWaysHelper(n, k, index + 1, 0);
            int case2 = (1) * countWaysHelper(n, k, index + 1, 2);
            totalWays = case1 + case2;
        }
        else if (c == 2)
        {
            totalWays = (k - 1) * countWaysHelper(n, k, index + 1, 2);
        }

        return totalWays;
    }

    int countWays(int n, int k)
    {
        if (n < 3)
        {
            return pow(k, n);
        }
        return countWaysHelper(n, k, 0, 0);
    }
};

int main()
{
    int n = 3;
    int k = 3;
    Solution sol;
    cout << sol.countWays(n, k) << endl;
}