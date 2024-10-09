#include <bits/stdc++.h>
using namespace std;

class Tree_node
{
public:
    int ISBN;
    string title;
    string author;
    int price;
    int quantity;
    Tree_node *left, *right, *parent;
    Tree_node()
    {
        cout << "enter the books ISBN " << endl;
        cin >> ISBN;
        cout << "enter the books title " << endl;
        cin >> title;
        cout << "enter the books author " << endl;
        cin >> author;
        cout << "enter the books price " << endl;
        cin >> price;
        cout << "enter the books quantity " << endl;
        cin >> quantity;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

class BST
{
public:
    Tree_node *root;

public:
    BST()
    {
        root = NULL;
    }
    void add_element()
    {
        Tree_node *t = new Tree_node();
        if (root == NULL)
        {
            root = t;
            return;
        }
        else
        {
            Tree_node *temp = root;
            Tree_node *parent = NULL;

            while (temp != NULL)
            {
                parent = temp;
                if (temp->ISBN > t->ISBN)
                {

                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
            t->parent = parent;
            if (parent->ISBN > t->ISBN)
            {
                parent->left = t;
            }
            else
            {
                parent->right = t;
            }
        }
    }

    void find_book()
    {
        cout << "Enter the ISBN of the book to search: " << endl;
        int ISBM;
        cin >> ISBM;

        Tree_node *temp = root;

        while (temp != NULL)
        {
            if (temp->ISBN == ISBM)
            {
                display(temp);
                return;
            }
            else if (temp->ISBN > ISBM)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }

        cout << "invalid ISBM " << endl;
    }

    void inorder(Tree_node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        display(root);
        inorder(root->right);
    }

    void update_quantity()
    {
        cout << "Enter the ISBN of the book to update quantity:  " << endl;
        int ISBM;
        cin >> ISBM;
        cout << "enter quantity " << endl;
        int q;
        cin >> q;

        Tree_node *temp = root;

        while (temp != NULL)
        {
            if (temp->ISBN == ISBM)
            {
                temp->quantity = q;
                return;
            }
            else if (temp->ISBN > ISBM)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }

        cout << "invalid ISBM " << endl;
    }
    void nochild(Tree_node *temp)
    {
        if (temp == root)
        {
            root == NULL;
            delete (temp);
            return;
        }
        else if (temp->parent->ISBN > temp->ISBN)
        {
            temp->parent->left = NULL;
        }
        else
        {
            temp->parent->right = NULL;
        }
        delete (temp);
    }

    void onechild(Tree_node *child)
    {
        Tree_node *points_to_temps_onlychild;
        if (child->left == NULL)
        {
            points_to_temps_onlychild = child->right;
        }
        else
        {
            points_to_temps_onlychild = child->left;
        }

        if (child == root)
        {
            root = points_to_temps_onlychild;
            delete (child);
            return;
        }
        else if (child->ISBN > child->parent->ISBN)
        {
            child->parent->right = points_to_temps_onlychild;
            points_to_temps_onlychild->parent = child->parent;
        }
        else
        {
            child->parent->left = points_to_temps_onlychild;
            points_to_temps_onlychild->parent = child->parent;
        }

        delete (child);
    }

    void Copy(Tree_node *child, Tree_node *right_subtree_node)
    {
        child->ISBN = right_subtree_node->ISBN;
        child->author = right_subtree_node->author;
        child->title = right_subtree_node->title;
        child->quantity = right_subtree_node->quantity;
        child->price = right_subtree_node->price;
    }
    void twochild(Tree_node *child)
    {
        Tree_node *right_subtree_node = child->right;
        while (right_subtree_node->left != NULL)
        {
            right_subtree_node = right_subtree_node->left;
        }
        Copy(child, right_subtree_node);

        if (right_subtree_node->left == NULL and right_subtree_node->right == NULL)
        {
            nochild(right_subtree_node);
        }
        else
        {
            onechild(right_subtree_node);
        }
        // right_subtree_node = NULL;
    }
    void remove()
    {

        cout << "Enter the ISBN of the book to remove: " << endl;
        int ISBM;
        cin >> ISBM;
        Tree_node *temp = root;

        while (temp != NULL)
        {
            if (temp->ISBN == ISBM)
            {
                break;
            }
            else if (temp->ISBN > ISBM)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }

        if (temp->left == NULL and temp->right == NULL)
        {
            nochild(temp);
        }
        else if (temp->left != NULL or temp->right != NULL)
        {
            onechild(temp);
        }
        else
        {
            twochild(temp);
        }
    }

    void display(Tree_node *ob)
    {
        cout << "ISBN: " << ob->ISBN << endl;
        cout << "title: " << ob->title << endl;
        cout << "author: " << ob->author << endl;
        cout << "price: " << ob->price << endl;
        cout << "quantiy: " << ob->quantity << endl;

        cout << endl;
    }
};

int main()
{
    BST moon;
    // Tree moon = NULL;
    while (true)
    {
        cout << "1 add a book to the inventory " << endl;
        cout << "2 remove a book from the inventory " << endl;
        cout << "3 update quantity of a book " << endl;
        cout << "4 search for a book by ISBN " << endl;
        cout << "5 Display all books in the inventory " << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            moon.add_element();

            break;

        case 2:
            moon.remove();
            break;

        case 4:
            moon.find_book();
            break;
        case 3:
            moon.update_quantity();
            break;
        case 5:
            cout << "INVENTORY " << endl;
            moon.inorder(moon.root);
            break;

        default:
            break;
        }
    }
}