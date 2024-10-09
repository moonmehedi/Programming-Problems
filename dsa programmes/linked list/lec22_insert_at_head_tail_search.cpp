#include <bits/stdc++.h>
using namespace std;
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
/*SEARCHING*/
void search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            cout << "yes" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "NO" << endl;
}

int main()
{
    node *head = NULL;
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_head(head, 5);
    display(head);
    search(head, 5);
    search(head, 7);

    return 0;
}