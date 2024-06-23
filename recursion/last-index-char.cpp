#include <iostream>
using namespace std;

int LastIndexHelper(string s, char p, int start)
{
    if (s.find(p) == -1)
    {
        return -1;
    }

    if (s.length() == 1)
    {
        return start;
    }

    int mid = s.length() / 2;
    return max(LastIndexHelper(s.substr(0, mid), p, start), LastIndexHelper(s.substr(mid), p, mid + start));
}

int LastIndex(string s, char p)
{
    return LastIndexHelper(s, p, 0);
}

int main()
{
    string s = "SahilMakhijadfhjadsjfjsafjkas";
    cout << LastIndex(s, 'a') << endl;
}