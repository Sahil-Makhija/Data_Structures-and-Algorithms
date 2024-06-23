#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int start = 0;
        int n = nums.size();
        int end = n - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            else if (nums[start] <= nums[mid])
            {
                if (nums[start] <= target && target <= nums[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else
            {
            }
        }
    }
};