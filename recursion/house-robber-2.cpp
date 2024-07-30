#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int robHelper(vector<int> &nums, int index, int size, vector<int> &memo)
    {
        if (index >= size)
        {
            return 0;
        }
        if (memo[index] != -1)
        {
            return memo[index];
        }
        int Option1 = nums[index] + robHelper(nums, index + 2, size, memo);
        int Option2 = robHelper(nums, index + 1, size, memo);

        memo[index] = max(Option1, Option2);
        return memo[index];
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> memo(n, -1);
        if (n == 1)
        {
            return nums[0];
        }

        int pickFirst = robHelper(nums, 0, n - 1, memo);
        fill(memo.begin(), memo.end(), -1);
        int skipFirst = robHelper(nums, 1, n, memo);

        return max(pickFirst, skipFirst);
    }
};

int main()
{
    vector<int> nums{2, 3, 2};
    Solution sol;
    cout << sol.rob(nums) << endl;
}