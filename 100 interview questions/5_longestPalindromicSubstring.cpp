#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
pair<int, int> traverse(string s, int left, int right)
{
    int sz = 0;
    while (left >= 0 and right < s.length() and s[left] == s[right])
    {
        sz += 2;
        left--;
        right++;
    }
    return {left + 1, sz};
}
    string longestPalindrome(string s)
    {
        pair<int, int> mx({0, 1});
        for (int i = 0; i < s.length(); i++)
        {
            if (i-1>=0 and s[i - 1] == s[i])
            {
                pair<int, int> sz = traverse(s, i - 1, i);
                if (mx.second < sz.second)
                {
                    mx.first = sz.first;
                    mx.second = sz.second;
                }
            }
            if (i-2 >=0 and s[i - 2] == s[i])
            {
                pair<int, int> sz = traverse(s, i - 2, i);
                sz.second++;
                if (mx.second < sz.second)
                {
                    mx.first = sz.first;
                    mx.second = sz.second;
                }
            }
        }
        return s.substr(mx.first, mx.second);
    }
};

int main()

{
    Solution s;
    cout << s.longestPalindrome("cvbgcgc") << endl;
}