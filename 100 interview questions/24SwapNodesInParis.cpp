#include <bits/stdc++.h>
using namespace std;

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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr or head->next == nullptr)
        {
            return head;
        }

        ListNode *ptr1 = head;
        ListNode *ptr2 = head->next;
        while (true)
        {

            swap(ptr1->val, ptr2->val);
            if (ptr2->next == nullptr or ptr2->next->next == nullptr)
            {
                break;
            }
            ptr1 = ptr2->next;
            ptr2 = ptr2->next->next;
        }
        return head;
    }
};

int main()
{

    Solution s;
    s.swapPairs()
}