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

/*this program deletes at head*/
void delete_at_head(node *&head)
{
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    node *todelete = head;
    temp->next = head->next;
    head = head->next;
    delete todelete;
}
/*remove an element*/
void deletion(node *&head, int pos)
{
    node *temp = head;
    if (pos == 1)
    {
        delete_at_head(head);
    }
    /*as it will go to zero thus it should be redused*/
    pos--;
    while (--pos)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

/*this code insert at head*/
void insert_at_head(node *&head, int val)
{
    node *n = new node(val);
    node *temp = head;
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

/*this funcation insert at tail*/
void insert_at_tail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        insert_at_head(head, val);
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void display(node *head)
{
    node *temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

signed
main()
{
    fast_io(); // enable faster I/O
    node *head = NULL;
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 4);
    insert_at_tail(head, 5);
    insert_at_tail(head, 6);
    display(head);
    insert_at_head(head, 10);
    insert_at_head(head, 11);
    insert_at_head(head, 12);
    insert_at_head(head, 13);
    display(head);
    deletion(head, 3);
    display(head);
    delete_at_head(head);
    display(head);
    return 0;
}