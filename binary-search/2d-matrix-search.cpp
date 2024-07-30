#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[m - 1][n - 1])
            return false;

        int start = 0;
        int end = (m * n) - 1;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            int rowIndex = mid / n;
            int colIndex = mid % n;

            int curr = matrix[rowIndex][colIndex];
            if (curr == target)
            {
                return true;
            }
            else if (curr < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
}