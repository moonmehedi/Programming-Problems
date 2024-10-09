#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'
/*linked list*/
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
/*calculate length*/
int calculate_length(node *head)
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

/*detectating intersection point*/
int intersectionpoint(node *&head1, node *&head2)
{
    int length1 = calculate_length(head1);
    int length2 = calculate_length(head2);
    int difference;
    node *ptr1;
    node *ptr2;
    if (length1 > length2)
    {
        difference = length1 - length2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        difference = length2 - length1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while (difference)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
            return -1;
        difference--;
    }
    while (ptr1 != NULL and ptr2 != NULL)
    {
        if (ptr1 == ptr2)
            return ptr1->data;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}
/*making a intersection point*/
void makeintersection(node *&head1, node *&head2, int pos)
{
    node *temp1 = head1;
    node *temp2 = head2;

    while (--pos)
    {
        temp1 = temp1->next;
    }
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
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
    insert_at_tail(head1, 2);
    insert_at_tail(head1, 3);
    insert_at_tail(head1, 4);
    insert_at_tail(head1, 5);
    insert_at_tail(head1, 6);
    insert_at_tail(head1, 7);
    node *head2 = NULL;
    insert_at_tail(head2, 10);
    insert_at_tail(head2, 11);
    insert_at_tail(head2, 12);
    makeintersection(head1, head2, 3);
    display(head1);
    display(head2);
    cout<<intersectionpoint(head1,head2);


    return 0;
}