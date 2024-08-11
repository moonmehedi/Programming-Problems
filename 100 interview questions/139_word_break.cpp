#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    class node
    {
    public:
        int EoW;
        unordered_map<int, node *> children;
        node()
        {
            EoW = 0;
        }
    };
    class Trie
    {
    public:
        node *root;

        Trie()
        {
            root = new node();
        }
        void insert(string s)
        {
            node *ptr = root;
            for (int i = 0; i < s.length(); i++)
            {
                int idx = s[i] - 97;
                if (ptr->children[idx] == NULL)
                    ptr->children[idx] = new node();
                ptr = ptr->children[idx];
            }
            ptr->EoW++;
        }

        bool find_word(string s)
        {

            node *ptr = root;

            for (int i = 0; i < s.length(); i++)
            {
                int idx = s[i] - 97;
                if (ptr == root and !ptr->children[idx])
                {
                    return false;
                }
                if (ptr->children[idx] == NULL and ptr->EoW)
                {
                    ptr = root;
                    i--;
                    continue;
                }
                else if (ptr->children[idx] == NULL and !ptr->EoW)
                    return false;
                ptr = ptr->children[idx];
            }
            if (!ptr->EoW)
                return false;
            return true;
        }
    };

    bool wordBreak(string s, vector<string> wordDict)
    {
        Trie t;
        for (auto ele : wordDict)
            t.insert(ele);

        return t.find_word(s);
    }
};
int main()
{
    Solution s;
    cout << s.wordBreak("bb", {"apple", "a", "b", "bbb", "bbbb", "leet", "code", "mehedi", "hasan", "moon"});
}