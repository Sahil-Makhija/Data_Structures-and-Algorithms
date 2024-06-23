#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    int closestPerfectSqr(int n)
    {
        int root = sqrt(n);
        return root * root;
    }

    int numSqrHelper(int n)
    {
        if (n == 1 || n == 0)
        {
            return 1;
        }
        int closestSqr = closestPerfectSqr(n);
        if (closestSqr == n)
        {
            return 1;
        }

        return min(1 + numSqrHelper(n - closestSqr), numSqrHelper(closestSqr - 1) + numSqrHelper(1 + n - closestSqr));
    }

    int numSquares(int n)
    {
        int count = n;
        return numSqrHelper(n);
    }
};

int main()
{
    Solution solution;
    cout << solution.numSquares(3) << endl;
}