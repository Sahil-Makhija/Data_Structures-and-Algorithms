#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int stepCounter(int n, vector<int> &dp)
    {
        if (n <= 3)
            return n;

        if (dp[n] != -1)
            return dp[n];

        int totalSteps = stepCounter(n - 1, dp) + stepCounter(n - 2, dp);
        dp[n] = totalSteps;
        return totalSteps;
    }

    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return stepCounter(n, dp);
    }
};

int main()
{
    int n = 45;
    Solution solution;
    cout << solution.climbStairs(n) << endl;
}