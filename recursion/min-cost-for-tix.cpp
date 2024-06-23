#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int ticketPassHelper(vector<int> &days, vector<int> &costs, int index, int passValidity, vector<int> &dp)
    {
        if (index >= days.size())
        {

            return 0;
        }
        if (passValidity >= days[index])
        {
            return ticketPassHelper(days, costs, index + 1, passValidity, dp);
        }
        if (dp[index] != -1)
        {
            return dp[index];
        }
        int costWith1dayPass, costWith7dayPass, costWith30dayPass = 0;
        costWith1dayPass = costs[0] + ticketPassHelper(days, costs, index + 1, days[index], dp);
        costWith7dayPass = costs[1] + ticketPassHelper(days, costs, index + 1, days[index] + 6, dp);
        costWith30dayPass = costs[2] + ticketPassHelper(days, costs, index + 1, days[index] + 29, dp);

        int minCost = min(costWith1dayPass, min(costWith30dayPass, costWith7dayPass));
        dp[index] = minCost;
        return minCost;
    }

    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        vector<int> dp(days.size(), -1);
        return ticketPassHelper(days, costs, 0, 0, dp);
    }
};

int main()
{
}