#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMax(const vector<int> &piles)
    {
        return *max_element(piles.begin(), piles.end());
    }

    bool canEatAll(const vector<int> &piles, int h, int k)
    {
        int timeTaken = 0;
        for (int pile : piles)
        {
            timeTaken += (pile + k - 1) / k;
            if (timeTaken > h)
                return false;
        }
        return timeTaken <= h;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int start = 1;
        int end = findMax(piles);
        int ans = end;

        while (start <= end)
        {
            int k = start + (end - start) / 2;
            if (canEatAll(piles, h, k))
            {
                ans = k;
                end = k - 1;
            }
            else
            {
                start = k + 1;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> piles{332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
    Solution solution;
    cout << solution.minEatingSpeed(piles, 823855818) << endl;
    return 0;
}