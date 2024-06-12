#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int binarySearch(vector<int> &nums, int target, int start, int end)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }

    int findPairs(vector<int> &nums, int k)
    {
        int n = nums.size();
        // If only 1 elem , then pairs cannot exist , hence `0`.
        if (n <= 1)
            return 0;

        sort(nums.begin(), nums.end());
        // initialize a start point and pairs count with 0
        int i = 0;
        int pairs = 0;

        while (i < n)
        {
            // if same value as last index , skip - (to find only unique pairs)
            if (i > 0 && nums[i] - nums[i - 1] == 0)
            {
                i++;
                continue;
            }
            // finding matching numbet to make a pair ...
            int targetIndex = binarySearch(nums, nums[i] + k, i + 1, n - 1);
            // if found, pairs++
            if (targetIndex != -1)
            {
                pairs++;
            }
            i++;
        }
        return pairs;
    }
};

int main()
{
    Solution ans;
    vector<int> nums{1, 1, 1, 1, 1};
    cout << ans.findPairs(nums, 0) << endl;
}