#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool checkDistance(vector<int> &stalls, int k, int dist)
{
    int cows = 1;
    int lastCowPosition = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {
        if ((stalls[i] - lastCowPosition) >= dist)
        {
            lastCowPosition = stalls[i];
            cows++;
        }
    }
    cout << endl
         << "Dist : " << dist << endl
         << "Cows :" << cows << endl;
    return cows >= k;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(), stalls.end());
    int start = 1;
    int end = *max_element(stalls.begin(), stalls.end());

    int ans = end - start;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (checkDistance(stalls, k, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> stalls{51, 59, 68, 81, 87, 93, 99};
    int k = 4;

    cout << aggressiveCows(stalls, k) << endl;
}
