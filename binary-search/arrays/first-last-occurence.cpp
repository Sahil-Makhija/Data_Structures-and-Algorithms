#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans{-1, -1};
        int n = nums.size();
        if (n == 0)
        {
            return ans;
        }
        if (n == 1)
        {
            if (nums[0] == target)
            {
                ans[0] = 0;
                ans[1] = 0;
            }
            return ans;
        }
        int firstOccurence = findFirstOccurence(nums, target, n);
        if (firstOccurence != -1)
        {
            ans[0] = firstOccurence;
            int lastOccurence = findLastOccurence(nums, target, firstOccurence, n);
            ans[1] = lastOccurence;
        }
        return ans;
    }

    int findFirstOccurence(vector<int> &nums, int target, int n)
    {
        int start = 0;
        int end = n - 1;
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
                if (mid == 0 || nums[mid] != nums[mid - 1])
                {
                    return mid;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
    int findLastOccurence(vector<int> &nums, int target, int start, int n)
    {
        int end = n - 1;
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
                if (mid == n - 1 || nums[mid] != nums[mid + 1])
                {
                    return mid;
                }
                start = mid + 1;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums{};
    Solution Ans;

    cout << Ans.searchRange(nums, 0)[0] << endl;
    cout << Ans.searchRange(nums, 0)[1] << endl;

    return -1;
}