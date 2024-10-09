#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
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
/*deletion*/
/*deletion at head*/
void deletion_head(node *&head)
{
    node *todelet_node = head;
    head = head->next;
    delete todelet_node;
}
/*delation*/
void deletion(node *&head, int key)
{
    /*if link list is empty return*/
    if (head == NULL)
    {
        return;
    }
    /*if data we want to delete in head delete head*/
    if (head->data == key)
    {
        deletion_head(head);
        return;
    }
    /*if element not in head search the element and delete*/
    node *temp = head;
    while (temp != NULL)
    {
        //found the element 
        if (temp->next->data == key)
        {
            node *todelet = temp->next;
            //changing links
            temp->next = temp->next->next;
            //deleting element
            delete todelet;
            return;
        }
        temp = temp->next;
    }
    cout<<"NOT FOUND"<<endl;
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
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    insert_at_tail(head,6);
    display(head);
    deletion(head, 5);
    deletion_head(head);
    display(head);

    return 0;
}