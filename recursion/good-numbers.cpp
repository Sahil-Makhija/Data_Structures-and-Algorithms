#include <iostream>
using namespace std;

class Solution
{
public:
    int solve(int n, int index, bool atEvenIndex)
    {
        if (index >= n)
        {
            return 1;
        }
        if (atEvenIndex)
        {
            return 5 * solve(n, index + 1, !atEvenIndex);
        }
        else
        {
            return 4 * solve(n, index + 1, !atEvenIndex);
        }
    }

    int countGoodNumbers(int n)
    {
        return solve(n, 0, true);
    }
};

int main()
{
    int n = 10;
    Solution solution;
    cout << solution.countGoodNumbers(n) << endl;
}