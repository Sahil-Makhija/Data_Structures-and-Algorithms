#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Solution
{
public:
    int myAtoiHelper(string s, int index, int n, int ans)
    {
        cout << endl
             << "Ans : " << ans << endl;
        if (index >= n || s[index] >= 'A' && s[index] <= 'Z' || s[index] >= 'a' && s[index] <= 'z')
        {
            return ans;
        }
        if (s[index] == ' ' || s[index] == '\t' || s[index] == '0')
        {
            return ans + myAtoiHelper(s, index + 1, n, ans);
        }
        if (s[index] == '-')
        {
            return -1 * myAtoiHelper(s, index + 1, n, ans);
        }
        if (s[index] >= '1' && s[index] <= '9')
        {
            int currVal = ans * 10 + (int)(s[index] - '0');
            cout << endl
                 << "Curr Val : " << currVal << endl;
            return currVal + myAtoiHelper(s, index + 1, n, currVal);
        }
        return ans;
    }

    int myAtoi(string s)
    {
        return myAtoiHelper(s, 0, s.length(), 0);
    }
};

int main()
{
    string s = "   -042";
    Solution solution;
    cout << solution.myAtoi(s);
}