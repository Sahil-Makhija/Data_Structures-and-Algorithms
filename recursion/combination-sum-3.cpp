#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void helper(vector<vector<int>> &ans, vector<int> &nums, vector<int> &comb, int k, int target, int index)
    {
        if (target == 0 && k == 0)
        {
            ans.push_back(comb);
            return;
        }
        if (target < 0 || index >= nums.size())
        {
            return;
        }

        comb.push_back(nums[index]);
        helper(ans, nums, comb, k - 1, target - nums[index], index + 1);
        comb.pop_back();
        helper(ans, nums, comb, k, target, index + 1);
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> ans;
        vector<int> comb;
        if (k < n)
        {
            helper(ans, nums, comb, k, n, 0);
        }
        return ans;
    }
};

int main()
{
}