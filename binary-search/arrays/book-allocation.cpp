#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool checkCombination(vector<int> &arr, int n, int m, int pages)
{
    int pagesLeft = pages;
    int students = 1;
    for (int i : arr)
    {
        if (i <= pagesLeft)
        {
            pagesLeft -= i;
        }
        else
        {
            students++;
            if (students > m)
                return false;
            pagesLeft = pages - i;
        }
    }
    return true;
}

int findPages(vector<int> &arr, int n, int m)
{
    // Write your code here.
    if (n < m)
        return -1;
    if (n == m)
        return *max_element(arr.begin(), arr.end());
    int start = *min_element(arr.begin(), arr.end());
    int end = accumulate(arr.begin(), arr.end(), 0);
    int ans = end;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (checkCombination(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n = 5;
    int m = 4;
    vector<int> arr{25, 46, 28, 49, 24};
    cout << findPages(arr, n, m) << endl;
}