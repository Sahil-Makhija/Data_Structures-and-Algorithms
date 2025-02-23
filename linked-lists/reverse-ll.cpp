#include <iostream>
using namespace std;

//  * Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseHelper(ListNode *curr, ListNode *prev)
    {
        if (curr == NULL)
        {
            return prev;
        }
        ListNode *next = curr->next;
        curr->next = prev;
        return reverseHelper(next, curr);
    }

    ListNode *reverseList(ListNode *head)
    {
        return reverseHelper(head, NULL);
    }
};

int main()
{
}