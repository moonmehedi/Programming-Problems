#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
/*REVERSE K NODES*/

node *reverse_k_nodes(node *&head, int k)
{
    node *pre_ptr = NULL;
    node *curr_ptr = head;
    node *nxt_ptr;
    int count = 1;
    /*this will reverse the first k nodes and the recursive function will reverse
    rest of the nodes
    */
    while (curr_ptr != NULL && count <= k)
    {
        /*store the value of nxt node*/
        nxt_ptr = curr_ptr->next;
        /*point current to its previous node*/
        curr_ptr->next = pre_ptr;
        /*update pointers*/
        pre_ptr = curr_ptr;
        curr_ptr = nxt_ptr;
        count++;
    }
    /*this recursive call will made if nxt-node is note null.if it is null we dont
    need to make any recursive call*/
    if (nxt_ptr != NULL)
    {
        /*call recursice */
        /*as we have reversed the linked list head is now our tail*/
        /*this code will reverse all the k nods of the link list and add it
        at tail which is head->next
        */
        head->next = reverse_k_nodes(nxt_ptr, k);
    }
    /*new head*/
    return pre_ptr;
}

/*BASIC LINKEDLIST FUNCTION*/
/*insert at head*/
void insert_at_head(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}
/*insert at tail*/
void insert_at_tail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        insert_at_head(head, val);
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
/*display*/
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    node *head = NULL;
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 4);
    insert_at_tail(head, 5);
    insert_at_tail(head, 6);
    display(head);
    display(reverse_k_nodes(head, 4));
    return 0;
}