#include <iostream>
#include <vector>
using namespace std;

// * Again TLE...

class Solution
{
public:
    int stockHelper(vector<int> &prices, int dayIndex, int n, vector<int> &dp)
    {
        if (dayIndex >= n)
            return 0;
        if (dp[0] != -1)
        {
            if (prices[dayIndex] > dp[0])
            {
                return max(dp[1], stockHelper(prices, dayIndex + 1, n, dp));
            }
            else
            {
                return max((dp[1] + (dp[0] - prices[dayIndex])), stockHelper(prices, dayIndex + 1, n, dp));
            }
        }
        int profit = 0;
        for (int i = dayIndex; i < n; i++)
        {
            if (prices[i] > prices[dayIndex] && prices[i] - prices[dayIndex] > profit)
            {
                profit = prices[i] - prices[dayIndex];
            }
        }
        int maxProfit = max(profit, stockHelper(prices, dayIndex + 1, n, dp));
        cout << endl
             << "Max Profit : " << maxProfit << " | " << "Stock Prize : " << dayIndex << endl;
        dp[0] = prices[dayIndex];
        dp[1] = maxProfit;
        return maxProfit;
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> dp(2, -1);
        return stockHelper(prices, 0, n, dp);
    }
};

int main()
{
    vector<int> prices{7, 1, 5, 3, 6, 4};
    Solution solution;
    cout << solution.maxProfit(prices) << endl;
    return 0;
}