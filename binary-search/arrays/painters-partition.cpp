#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

bool checkTime(vector<int> &boards, int k, int time)
{
    int timeLeft = time;
    int painters = 1;
    for (int board : boards)
    {
        if (board <= timeLeft)
        {
            timeLeft -= board;
        }
        else
        {
            painters++;
            if (painters > k)
                return false;
            timeLeft = time - board;
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    if (boards.size() == 1)
        return boards[0];

    int start = *max_element(boards.begin(), boards.end());
    int end = accumulate(boards.begin(), boards.end(), 0);

    int ans = end;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (checkTime(boards, k, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    };

    return ans;
}
int main()
{
    vector<int> boards{48, 90};
    int k = 2;
    cout << findLargestMinDistance(boards, k) << endl;
}