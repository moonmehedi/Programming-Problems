#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
class List
{
    node *head = NULL;
    node *tail = NULL;

public:
    void insert_at_tail(int val)
    {
        node *n = new node;
        n->data = val;
        n->next = NULL;
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
    }
    void insert_at_head(int val)
    {
        node *n = new node;
        n->next = head;
        n->data = val;
        head = n;
    }
    void search(int key)
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "element present " << endl;
                return;
            }

            temp = temp->next;
        }
        cout << "element not found" << endl;
    }
    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    List moon;
    moon.insert_at_tail(1);
    moon.insert_at_tail(2);
    moon.insert_at_tail(3);
    moon.insert_at_tail(4);
    moon.insert_at_tail(5);
    moon.insert_at_tail(6);

    moon.display();
    cout << endl;
    moon.insert_at_head(7);
    moon.insert_at_head(8);
    moon.insert_at_head(9);
    moon.display();
    moon.search(9);
    moon.search(10);
}