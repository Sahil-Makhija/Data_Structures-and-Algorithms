#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#include <iostream>
#include <vector>
#include <climits>

class Solution
{
public:
    int coinChangeHelper(vector<int> &coins, int amount, vector<int> &memo)
    {
        if (amount == 0)
            return 0;

        if (memo[amount] != -1 && memo[amount] != INT_MAX)
            return memo[amount];

        int totalCoins = INT_MAX;
        for (int coin : coins)
        {
            if (coin <= amount)
            {
                int coinsForRemainingAmt = coinChangeHelper(coins, amount - coin, memo);
                if (coinsForRemainingAmt != -1)
                {
                    totalCoins = min(totalCoins, 1 + coinsForRemainingAmt);
                }
            }
        }

        if (totalCoins == INT_MAX)
            return -1;
        memo[amount] = totalCoins;
        return totalCoins;
    }

    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> memo(amount + 1, -1);
        return coinChangeHelper(coins, amount, memo);
    }
};

int main()
{
    Solution solution;
    vector<int> coins = {186, 419, 83, 408};
    int amount = 6249;
    int result = solution.coinChange(coins, amount);
    cout << "Minimum number of coins needed: " << result << endl;
    return 0;
}
