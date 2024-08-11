#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string s)
    {

        string num[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> ans;
        int l = s.length();

        for (int i = 0; i < l; i++)
        {
            if (s[0] == '1')
            {
                s.erase(0, 1);
                continue;
            }
            break;
        }

        if (s.length() == 0)
        {
            return {};
        }
        else if (s.length() == 1)
        {
            int n = s[0] - '1' + 1;

            for (int i = 0; i < num[n].length(); i++)
            {
                ans.push_back(string(1, num[n][i]));
            }
        }

        else if (s.length() == 2)
        {
            int n1 = s[0] - '1' + 1;
            int n2 = s[1] - '1' + 1;

            for (int i = 0; i < num[n1].length(); i++)
            {
                for (int j = 0; j < num[n2].length(); j++)
                    ans.push_back(string(1, num[n1][i]) + string(1, num[n2][j]));
            }
        }

        else if (s.length() == 3)
        {
            int n1 = s[0] - '1' + 1;
            int n2 = s[1] - '1' + 1;
            int n3 = s[2] - '1' + 1;

            for (int i = 0; i < num[n1].length(); i++)
            {
                for (int j = 0; j < num[n2].length(); j++)
                    for (int k = 0; k < num[n3].length(); k++)
                        ans.push_back(string(1, num[n1][i]) + string(1, num[n2][j]) + string(1, num[n3][k]));
            }
        }

        else if (s.length() == 4)
        {
            int n1 = s[0] - '1' + 1;
            int n2 = s[1] - '1' + 1;
            int n3 = s[2] - '1' + 1;
            int n4 = s[3] - '1' + 1;

            for (int i = 0; i < num[n1].length(); i++)
            {
                for (int j = 0; j < num[n2].length(); j++)
                    for (int k = 0; k < num[n3].length(); k++)
                        for (int m = 0; m < num[n4].length(); m++)
                            ans.push_back(string(1, num[n1][i]) + string(1, num[n2][j]) + string(1, num[n3][k]) + string(1, num[n4][m]));
            }
        }
        return ans;
    }
};
int main()
{
    Solution S;
    vector<string> ans = S.letterCombinations("2345");

    cout << "Generated Combinations: ";
    for (auto ele : ans)
    {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}