#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

class node
{
public:
    /*data feild stores data*/
    int data;
    /*pointer fild stores pointer*/
    node *next;
    /*constructor*/
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

/*solve using recursion*/
node *mergerecursion(node *&head1, node *&head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    node *result;
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = mergerecursion(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergerecursion(head1, head2->next);
    }
    return result;
}

/*merge two sorted linked list*/
node *merge_two_sorted_linked_list(node *&head1, node *&head2)
{
    node *ptr1 = head1;
    node *ptr2 = head2;
    node *dummy = new node(-1);
    node *ptr3 = dummy;
    while (ptr1 != NULL and ptr2 != NULL)
    {
        if (ptr1->data < ptr2->data)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
            ptr3 = ptr3->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
            ptr3 = ptr3->next;
        }
    }
    /*inserting rest of the link list*/
    if (ptr1 != NULL)
    {
        ptr3->next = ptr1;
    }
    else
        ptr3->next = ptr2;

    return dummy->next;
}

/*insert at tail*/
void insert_at_tail(node *&head, int val)
{ // we will be changing the value of head that's why taking it by reference
    /*dynamic memory allocation using pointer*/
    node *n = new node(val);
    if (head == NULL)
    {
        head = n; // here we are change the address stored in head for this like we took head by reference
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void insert_at_head(node *&head, int val)
{
    node *n = new node(val);
    n->next = head; //
    head = n;       // here we are changing the address stored in head
}

/*DISPLAY NODE*/
void display(node *head)
{ // we are taking head by value because we dont't need to change the address of head
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

signed main()
{
    fast_io(); // enable faster I/O
    node *head1 = NULL;
    insert_at_tail(head1, 1);
    insert_at_tail(head1, 3);
    insert_at_tail(head1, 5);
    insert_at_tail(head1, 7);
    insert_at_tail(head1, 9);
    insert_at_tail(head1, 11);
    insert_at_tail(head1, 13);
    display(head1);
    node *head2 = NULL;
    insert_at_tail(head2, 2);
    insert_at_tail(head2, 4);
    insert_at_tail(head2, 6);
    insert_at_tail(head2, 8);
    display(head2);

    /*one function is for merge recursive and the other is for iteration recursive*/
    // node *newhead1 = merge_two_sorted_linked_list(head2, head1);
    // node *newhead2 = mergerecursion(head2, head1);
    display(newhead1);
    display(newhead2);

    return 0;
}