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
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
/*count the length*/
int count_length(node *head)
{
    node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    return length;
}

node *append_last_k_nodes(node *&head, int reversed_k)
{
    node *temp = head;
    node *newtail;
    node *newhead;
    int length = count_length(head);
    int position = 1;
    while (temp->next != NULL)
    {
        if (position == (length - reversed_k))
        {
            newtail = temp;
        }
        else if (position == (length - reversed_k) + 1)
        {
            newhead = temp;
        }
        temp = temp->next;
        position++;
    }
    temp->next = head;
    newtail->next = NULL;
    // head = newhead;
    return newhead;
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
    insert_at_tail(head, 6);
    insert_at_tail(head, 7);
    insert_at_tail(head, 8);
    display(append_last_k_nodes(head, 4));

    return 0;
}