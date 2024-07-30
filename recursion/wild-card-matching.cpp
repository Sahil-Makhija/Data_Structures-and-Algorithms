#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int index = 0;
        int n = p.length();
        while (index < n)
        {
            if (p[index] == '?' || p[index] == s[index])
            {
                index++;
            }
            else if (p[index] == '*')
            {
                int s_index = s.length() - (n - (index + 1));
                if (s_index >= s.length())
                    return true;
                return isMatch(s.substr(s_index), p.substr(index + 1));
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string s = "acdcb";
    string p = "a*c?b";
    Solution solution;
    bool isMatched = solution.isMatch(s, p);
    if (isMatched)
    {
        cout << "Pattern Matched!" << endl;
    }
    else
    {
        cout << "Pattern Not Matched!" << endl;
    }
}