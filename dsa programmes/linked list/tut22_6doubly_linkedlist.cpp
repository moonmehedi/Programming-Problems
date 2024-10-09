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
    node *previous;
    node(int val)
    {
        data = val;
        next = NULL;
        previous = NULL;
    }
};

/*delete_at_head*/
void delete_at_head(node *&head)
{
    node *todelete = head;
    head = head->next;
    head->previous = NULL;
    delete todelete;
}

/*deletion*/
void deletion(node *&head, int poskid)
{
    if (poskid == 1)
    {
        delete_at_head(head);
        return;
    }
    node *temp = head;
    int count = 1;
    while (temp != NULL && count != poskid)
    {
        temp = temp->next;
        count++;
    }
    temp->previous->next = temp->next;

    if (temp->next != NULL)
        temp->next->previous = temp->previous;
    delete temp;
}

/*insert at head*/
void insert_at_head(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
    {
        head->previous = n;
    }
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
    n->previous = temp;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "END" << endl;
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
    display(head);
    deletion(head, 5);
    display(head);

    return 0;
}