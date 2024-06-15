#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int getTotalMissingInts(vector<int> &arr, int limit)
    {
        int foundInts = 0;
        for (int i : arr)
        {
            if (i <= limit)
            {
                foundInts++;
            }
            else
            {
                break;
            }
        }
        return limit - foundInts;
    }

    int findKthPositive(vector<int> &arr, int k)
    {
        int start = k;
        int n = arr.size();
        int end = arr[n - 1] + k;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            int missingInts = getTotalMissingInts(arr, mid);
            if (missingInts > k)
            {
                end = mid - 1;
            }
            else if (missingInts < k)
            {
                start = mid + 1;
            }
            else
            {
                return mid;
            }
        }

        return INT_MAX;
    }
};

int main()
{
    Solution solution;
    vector<int> arr{2, 3, 4, 7, 11};
    cout << "kth Element : " << solution.findKthPositive(arr, 5) << endl;
}