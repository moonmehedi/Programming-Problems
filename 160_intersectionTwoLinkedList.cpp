#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;

        while (ptr1 != ptr2)
        {
            if (ptr1 == NULL)
            {
                ptr1 = headB;
            }
            if (ptr2 == NULL)
            {
                ptr2 = headA;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
};

int main()
{
}