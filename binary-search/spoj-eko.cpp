#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkHeight(vector<int> &nums, int m, int h)
{
    int wood = 0;
    for (int i : nums)
    {
        if (i > h)
        {
            wood += i - h;
        }
    }
    return wood >= m;
}

int findHeight(vector<int> &nums, int n, int m)
{
    int start = 0;
    int end = *max_element(nums.begin(), nums.end()) - 1;
    int ans = 0;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (checkHeight(nums, m, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums{4, 42, 40, 26, 46};
    int m = 20;
    int n = nums.size();
    cout << findHeight(nums, n, m) << endl;
    return 1;
}