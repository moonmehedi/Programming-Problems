#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int EoW;
    node *arr[26];

    node()
    {
        EoW = 0;
        for (int i = 0; i < 26; i++)
            arr[i] = NULL;
    }
};

class Trie
{
    node *root;

public:
    Trie()
    {
        root = new node();
    }

    void insert(string word)
    {
        node *ptr = root;

        for (int i = 0; i < word.length(); i++)
        {
            int idx = word[i] - 97;
            if (ptr->arr[idx] == NULL)
                ptr->arr[idx] = new node();
            ptr = ptr->arr[idx];
        }
        ptr->EoW++;
    }

    bool search(string word)
    {
        node *ptr = root;

        for (int i = 0; i < word.length(); i++)
        {
            int idx = word[i] - 97;
            if (ptr->arr[idx] == NULL)
                return false;
            ptr = ptr->arr[idx];
        }
        if (!ptr->EoW)
            return false;
        return true;
    }

    bool startsWith(string prefix)
    {
        node *ptr = root;

        for (int i = 0; i < prefix.length(); i++)
        {
            int idx = prefix[i] - 97;
            if (ptr->arr[idx] == NULL)
                return false;
            ptr = ptr->arr[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main()
{
    Trie t;
    t.insert("apple");
    cout << t.search("apple") << endl;
    cout << t.search("app") << endl;
    cout << t.startsWith("app") << endl;
    t.insert("app");
    cout << t.search("app") << endl;
}