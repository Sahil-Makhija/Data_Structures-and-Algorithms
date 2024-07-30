#include <iostream>
using namespace std;

int lastIndexHelper(string s, char p, int start)
{

    if (s.find(p) == -1)
        return -1;
    if (s.length() == 1)
        return start;

    int mid = s.length() / 2;
    string part1 = s.substr(0, mid);
    string part2 = s.substr(mid);

    return max(lastIndexHelper(part1, p, start), lastIndexHelper(part2, p, start + mid));
}

int LastIndex(string s, char p)
{
    // complete the function here
    return lastIndexHelper(s, p, 0);
}

int main()
{
    string s = "Geeks";
    cout << LastIndex(s, 'e') << endl;
}

// 0,1,2,3,4,5,6,7,8,9