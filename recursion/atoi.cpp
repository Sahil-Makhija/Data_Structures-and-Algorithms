#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int myAtoiHelper(string s, int index, int ans, bool isNegative)
    {
        if (index == s.length())
        {
            // when string size == 0
            if (ans == INT_MIN)
            {
                return 0;
            }
            return isNegative ? -1 * ans : ans;
        }

        int digit = s[index];

        if (ans == INT_MIN)
        {
            if (digit == ' ')
            {
                return myAtoiHelper(s, index + 1, ans, isNegative);
            }
            if (digit == '+')
            {
                return myAtoiHelper(s, index + 1, 0, false);
            }
            if (digit == '-')
            {
                return myAtoiHelper(s, index + 1, 0, true);
            }
            if (digit < '0' || digit > '9')
            {
                return 0;
            }
            if (digit >= '0' && digit <= '9')
            {
                ans = digit - '0';
                return myAtoiHelper(s, index + 1, ans, isNegative);
            }
        }
        else
        {
            if (digit >= '0' && digit <= '9')
            {
                if (ans > (INT_MAX - (digit - '0')) / 10)
                {
                    return isNegative ? INT_MIN : INT_MAX;
                }
                ans = ans * 10 + (digit - '0');
                return myAtoiHelper(s, index + 1, ans, isNegative);
            }
            return isNegative ? -1 * ans : ans;
        }

        return 0;
    }

    int myAtoi(string s)
    {
        return myAtoiHelper(s, 0, INT_MIN, false);
    }
};

int main()
{
    Solution solution;
    cout << solution.myAtoi("-94313_232132") << endl;
}

/*
cannot do { -1 * fn(...remaing_str) } , because the remaing answer can actually be eqault to INT_MAX , which should return -1 * INT_MAX , but the little gimmick , when there is a '-' sign , that turns INT_MAX value from remaing answer to INT_MIN , will mess up the answer by value of 1,

So, its better to have a flag value , that helps converts the answer in +ve or -ve .
*/