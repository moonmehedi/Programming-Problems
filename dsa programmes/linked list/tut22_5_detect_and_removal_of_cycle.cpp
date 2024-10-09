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
/*remove cycle*/
void remove_cycle(node *&head)
{
    node *fast = head;
    node *slow = head;
    do
    {
        fast = fast->next->next;
        slow = slow->next;
    } while (fast != slow);
    fast = head;
    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
}
/*makes cycle*/
void make_cycle(node *&head, int pos)
{
    node *temp = head;
    node *cycle_starts_from_here;
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            cycle_starts_from_here = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = cycle_starts_from_here;
}
/*detect cycle*/
bool detect_cycle(node *&head)
{
    node *fast = head;
    node *slow = head;
    while (fast != NULL and slow != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            // cout << slow->data << endl;
            // cout << fast->data << endl;
            return true;
        }
    }
    return false;
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
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    while (true)
    {
        cout << "THIS PROGRAMME MAY PERFORM THE FOLLWOING OPERATIONS" << endl
             << "1.INSERT ELEMENT " << endl
             << "   a.insert at head " << endl
             << "   b.insert at tail " << endl
             << "2.DETECT CYCLE " << endl
             << "3.MAKE CYCLE " << endl
             << "4.REMOVE CYCLE " << endl
             << "0. DISPLAY " << endl
             << "10.EXIT " << endl;
        int perform;
        cin >> perform;
        switch (perform)
        {
        case 1:
            cout << "how would you like to insert element " << endl;
            char where_to_insert;
            cin >> where_to_insert;
            if (where_to_insert == 'a')
            {
                cout << "please enter number of elements : " << endl;
                int number_of_element;
                cin >> number_of_element;
                for (int i = 0; i < number_of_element; i++)
                {
                    int value;
                    cout << "enter element number " << i + 1 << endl;
                    cin >> value;
                    insert_at_head(head, value);
                }
            }
            else
            {
                cout << "please enter number of element : " << endl;
                int number_of_element;
                cin >> number_of_element;
                for (int i = 0; i < number_of_element; i++)
                {
                    int value;
                    cout << "enter element number " << i + 1 << endl;
                    cin >> value;
                    insert_at_tail(head, value);
                }
            }
            break;
        case 2:
            if (detect_cycle(head))
                cout << "cycle present! " << endl;
            else
                cout << "cycle not present " << endl;
            break;
        case 3:
            cout << "enter position where cycle will form" << endl;
            int position;
            cin >> position;
            make_cycle(head, position);
            break;
        case 4:
            remove_cycle(head);
            break;
        case 0:
            display(head);
            break;
        case 10:
            return 0;
        default:
            break;
        }
    }
    return 0;
}