#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    bool checkCombination(vector<int> &nums, int k, int limit)
    {
        int subArrs = 1;
        int arrSize = limit;
        for (int i : nums)
        {
            if (i <= arrSize)
            {
                arrSize -= i;
            }
            else
            {
                subArrs++;
                if (subArrs > k)
                    return false;
                arrSize = limit - i;
            }
        }
        return true;
    }

    int splitArray(vector<int> &nums, int k)
    {
        if (nums.size() == k)
        {
            return *max_element(nums.begin(), nums.end());
        }
        if (k == 1)
            return accumulate(nums.begin(), nums.end(), 0);

        int start = *max_element(nums.begin(), nums.end());
        int end = accumulate(nums.begin(), nums.end(), 0) - *min_element(nums.begin(), nums.end());

        int ans = end;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (checkCombination(nums, k, mid))
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
    vector<int> nums{2, 3, 1, 2, 4, 3};
    cout << solution.splitArray(nums, 5) << endl;
}

// * We have to consider sum of subArrs , the sum-range will atleast be largest element of the whole array...