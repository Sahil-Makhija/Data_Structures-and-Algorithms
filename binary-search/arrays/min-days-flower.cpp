#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    Solution solution;
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;
    cout << solution.minDays(bloomDay, m, k) << endl; // Output: 3
    return 0;
}
class Solution
{
public:
    bool areFlowersEnough(vector<int> &bloomDay, int m, int k, int days)
    {
        int bouquets = 0;
        int flowersBloomed = 0;
        for (int bloom : bloomDay)
        {
            if (bloom <= days)
            {
                flowersBloomed++;
                if (flowersBloomed == k)
                {
                    bouquets++;
                    flowersBloomed = 0;
                }
            }
            else
            {
                flowersBloomed = 0;
            }
            if (bouquets >= m)
                return true;
        }
        return bouquets >= m;
    }

    int findMax(vector<int> &bloomDay)
    {
        return *max_element(bloomDay.begin(), bloomDay.end());
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        if (static_cast<long long>(m) * k > bloomDay.size())
            return -1;
        int start = 1;
        int end = findMax(bloomDay);
        int ans = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (areFlowersEnough(bloomDay, m, k, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};