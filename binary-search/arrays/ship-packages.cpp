#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    bool checkCapacity(const vector<int> &weights, int days, int capacity)
    {
        // Start with one day
        int daysTaken = 1;
        int capacityLeft = capacity;

        for (int w : weights)
        {
            if (capacityLeft >= w)
            {
                capacityLeft -= w;
            }
            else
            {
                daysTaken++;
                capacityLeft = capacity - w;
                if (daysTaken > days)
                    return false;
            }
        }

        return true;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        // start with heaviest package..
        int start = *max_element(weights.begin(), weights.end());
        // max package weight can be total of all weights ..
        int end = accumulate(weights.begin(), weights.end(), 0);
        int ans = end;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (checkCapacity(weights, days, mid))
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

int main()
{
    Solution solution;
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << solution.shipWithinDays(weights, 5) << endl; // Output: 15
    return 0;
}
