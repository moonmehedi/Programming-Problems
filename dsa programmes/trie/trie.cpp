#include <bits/stdc++.h>
using namespace std;

class trie
{
public:
    class node
    {
    public:
        bool end;
        node *next[26];
        node()
        {
            end = false;
            for (int i = 0; i < 26; i++)
            {
                next[i] = NULL;
            }
        }
    };
};

int main()
{
    vector<int> v{1, 2, 3, 4, 5};
    cout << v.size() << endl;
}