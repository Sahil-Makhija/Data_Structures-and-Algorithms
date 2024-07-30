#include <iostream>
using namespace std;

class Solution
{
public:
    int solve(int n, int k, int index, int c)
    {
        if (index >= n)
            return 0;

        if (n == 1)
        {
            return k;
        }

        int totalWays;
        if (c == 2)
        {
            totalWays = solve(n, k, index + 1, 0);
        }
        else
        {
            totalWays = k * solve(n, k, index + 1, c + 1);
        }

        return totalWays;
    }

    int countWays(int n, int k)
    {
        return solve(n, k, 0, 0);
    }
};

int main()
{
    Solution sol;
    cout << sol.countWays(3, 2) << endl;
}