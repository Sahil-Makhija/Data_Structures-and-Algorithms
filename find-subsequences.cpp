#include <iostream>
#include <string>
using namespace std;

void findSubsequences(string s, int i, string base)
{
    if (i >= s.length())
    {
        cout << "\"" << base << "\"" << endl;
        return;
    }
    char ch = s[i];

    findSubsequences(s, i + 1, base);
    base.push_back(ch);
    findSubsequences(s, i + 1, base);
}

int main()
{
    string input = "abc";
    findSubsequences(input, 0, "");
    return 1;
}