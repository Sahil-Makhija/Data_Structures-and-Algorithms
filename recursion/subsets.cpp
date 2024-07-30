#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> &subset, int index)
    {
        if (index >= nums.size())
        {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        helper(nums, ans, subset, index + 1);
        subset.pop_back();

        helper(nums, ans, subset, index + 1);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> subset;
        vector<vector<int>> ans;
        helper(nums, ans, subset, 0);
        return ans;
    }
};

int main()
{
}