#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void helper(vector<string> &combinations, int &n, int openCount, int closeCount, string &str)
    {
        if (openCount >= n && closeCount >= n)
        {
            combinations.push_back(str);
            return;
        }
        if (openCount < n)
        {
            str.push_back('(');
            helper(combinations, n, openCount + 1, closeCount, str);
            str.pop_back(); // backtrack
        }

        if (openCount > closeCount)
        {
            str.push_back(')');
            helper(combinations, n, openCount, closeCount + 1, str);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> combinations;
        string str = "";
        helper(combinations, n, 0, 0, str);
        return combinations;
    }
};

int main()
{
}