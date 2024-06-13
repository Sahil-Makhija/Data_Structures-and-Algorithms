#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums[0] == target)
        {
            return 0;
        }
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                return mid;
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
                if (target > nums[mid] && nums[end] >= target)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{

    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    Solution Ans;

    cout << Ans.search(nums, 0) << endl;

    return 1;
}