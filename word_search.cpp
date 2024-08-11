#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool mp[100][100];
    bool rec(vector<vector<char>> &board, string word, int m, int n, int wl, int i, int a, int b)
    {
        if (i == wl)
            return true;

        mp[a][b] = true;

        if (a + 1 < m and board[a + 1][b] == word[i] and mp[a + 1][b] == false)
        {
            if (rec(board, word, m, n, wl, i + 1, a + 1, b))
                return true;
            mp[a + 1][b] = false;
        }
        if (b + 1 < n and board[a][b + 1] == word[i] and mp[a][b + 1] == false)
        {
            if (rec(board, word, m, n, wl, i + 1, a, b + 1))
                return true;
            mp[a][b + 1] = false;
        }
        if (a - 1 >= 0 and board[a - 1][b] == word[i] and mp[a - 1][b] == false)
        {
            if (rec(board, word, m, n, wl, i + 1, a - 1, b))
                return true;
            mp[a - 1][b] = false;
        }
        if (b - 1 >= 0 and board[a][b - 1] == word[i] and mp[a][b - 1] == false)
        {
            if (rec(board, word, m, n, wl, i+1, a, b - 1))
                return true;
            mp[a][b - 1] = false;
        }
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        int wl = word.length();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0] and rec(board, word, m, n, wl, 1, i, j))
                {
                    return true;
                }
                mp[i][j] = false;
            }
        }

        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> v{{'a', 'c'}, {'d', 'e'}};
    s.exist(v, "abcd");
}
