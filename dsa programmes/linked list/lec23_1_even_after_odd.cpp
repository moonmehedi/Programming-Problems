#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

/*this is a linked list*/
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

/*this algorithm puts even after odd*/
void even_after_odd(node *&head)
{
    node *odd = head;
    node *even = head->next;
    node *evenstart = even;
    while (odd->next != NULL and even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenstart;
    if (even != NULL)
        even = NULL;
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
    node *head = NULL;
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 4);
    insert_at_tail(head, 5);
    // insert_at_tail(head, 6);

    display(head);

    even_after_odd(head);

    display(head);

    return 0;
}