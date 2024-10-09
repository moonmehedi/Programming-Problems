#include <bits/stdc++.h>
using namespace std;

// always remember edge inticates the characters not the nodes
class Node
{
public:
    int EoW;
    Node *children[26];
    Node()
    {
        EoW = 0;
        for (int i = 0; i < 26; i++)
        {
            this->children[i] = NULL;
        }
    }
};
void trie_insert(Node *root, string s)
{

    Node *ptr = root;
    for (int i = 0; i < s.length(); i++)
    {
        int idx = s[i] - 65;

        if (ptr->children[idx] == NULL)
        {
            ptr->children[idx] = new Node();
        }

        ptr = ptr->children[idx];
    }

    ptr->EoW++;

    // cout<<ptr->EoW<<endl;
}
int trie_search(Node *root, string s, int k = 0) // k is the index
{

    if (root == NULL)
    {
        return 0;
    }

    if (k == s.length())
    {
        return root->EoW;
    }

    int idx = s[k] - 65;

    return trie_search(root->children[idx], s, k + 1);

    // Node *ptr = root;

    // for (int i = 0; i < s.length(); i++)
    // {
    //     int idx = s[i] - 65;

    //     if (ptr->children[idx] == NULL)
    //     {
    //         return -1;
    //     }

    //     ptr = ptr->children[idx];
    // }

    // if (ptr->EoW > 0)
    // {
    //     return ptr->EoW;
    // }

    // return -1;
}

void printTRIE(Node *root, string s = "") // lexicographical sort
{

    if (root->EoW > 0)
    {
        cout << s << endl;
    }

    for (int i = 25; i >= 0; i--)
    {
        if (root->children[i] != NULL)
        {
            char c = i + 65;
            printTRIE(root->children[i], s + c);
        }
    }
}
void printTRIEMORE(Node *root, string s = "") // lexicographical sort
{

    if (root->EoW > 1)
    {
        cout << s << endl;
    }

    for (int i = 25; i >= 0; i--)
    {
        if (root->children[i] != NULL)
        {
            char c = i + 65;
            printTRIEMORE(root->children[i], s + c);
        }
    }
}

void traverseprefix(Node *root, string s, int k)
{

    if (k == s.length())
    {
        printTRIE(root, s);
        return;
    }

    int idx = s[k] - 65;
    traverseprefix(root->children[idx], s, ++k); // remember you here made a mistake is should be ++k pre assigment
}

bool isLeaf(Node *root)
{
    for (int i = 0; i < 26; i++)
    {
        if (root->children[i] != NULL)
        {
            return true;
        }
    }
    return false;
}

int isJunction(Node *root)
{

    bool ischild = false;

    for (int i = 0; i < 26; i++)
    {
        if (root->children[i] != NULL)
        {
            ischild = true;
            break;
        }
    }

    if (root->EoW > 0 or ischild == true)
        return 1;
    return 0;
}

void removeEdge(Node *root, int k, int d)
{

    if (d == 0)
    {
        return;
    }

    Node *ptr = root->children[k - 65];

    root->children[k - 65] = NULL;
    delete (ptr);
}

int trieDelete(Node *root, string s, int k)
{
    if (root == NULL)
    {
        return 0;
    }

    if (k == s.length())
    {
        if (root->EoW == 0)
        {
            return 0;
        }
        if (!isLeaf(root))
        {
            root->EoW = 0;
            return 0;
        }
        return 1;
    }

    int idx = s[k] - 65;
    int d = trieDelete(root->children[idx], s, k + 1);
    int j = isJunction(root);

    removeEdge(root, s[k], d);

    if (j == 1)
    {
        return 0;
    }
    return d;
}

int main()
{
    Node *root = new Node();

    while (1)
    {
        cout << "1. Insert    2. Search    3. Delete   4. Lexicographical Sorting  5. Display Strings  6. End" << endl
             << endl;
        int choice;
        string x;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Insert String: ";
            cin >> x;
            trie_insert(root, x);
            cout << x << " is inserted in the trie" << endl;
        }
        else if (choice == 2)
        {
            cout << "Enter string to search: ";
            cin >> x;
            if (trie_search(root, x) > 0)
                cout << x << " FOUND " << endl;
            else
                cout << x << " NOT FOUND " << endl;
        }
        else if (choice == 3)
        {
            cout << "enter string " << endl;
            string s;
            cin >> s;

            trieDelete(root, s, 0);
            cout << s << " is deleted " << endl;
        }
        else if (choice == 4)
        {
            printTRIE(root);
        }
        else if (choice == 5)
        {
            printTRIE(root);
        }
        else if (choice == 6)
        {
            break;
        }
        else if (choice == 8)
        {
            printTRIEMORE(root);

            // printTRIEsuffix(root, "", s1);
        }
        else if (choice == 9)
        {
            cout << "enter suffix " << endl;
            string s;
            cin >> s;

            traverseprefix(root, s, 0);
        }
        else
        {
            cout << "Invalid Choice" << endl;
            break;
        }
        cout << endl;
    }
}
/*inputs:

1 MIST
1 MIT
1 CSE
1 CSE
1 CE
1 MISTCSE
1 ME
1 EECE
1 ABC
1 ABC
1 AB

*/
