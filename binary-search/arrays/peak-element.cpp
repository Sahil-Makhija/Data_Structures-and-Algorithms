#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1 || nums[0] > nums[1])
        {
            return 0;
        }
        if (nums[n - 1] > nums[n - 2])
        {
            return n - 1;
        }
        int start = 1;
        int end = n - 2;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            else if (nums[mid] > nums[mid - 1] && nums[mid + 1] > nums[mid])
            {
                start = mid + 1;
            }
            else if (nums[mid] < nums[mid - 1] && nums[mid + 1] < nums[mid])
            {
                end = mid - 1;
            }
            else if (nums[mid] < nums[mid - 1] && nums[mid + 1] > nums[mid])
            {
                end = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums{1, 2, 1, 3, 5, 6, 4};
    Solution Ans;

    cout << Ans.findPeakElement(nums) << endl;

    return 1;
}