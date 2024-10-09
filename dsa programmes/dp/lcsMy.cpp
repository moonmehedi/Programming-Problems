#include <bits/stdc++.h>
using namespace std;
int c[100][100];

int p_lcs[100][100];

void print_lcs(string x, int i, int j)
{
    if (i == -1 or j == -1 or i == 0 or j == 0)
    {
        return;
    }
    if (p_lcs[i][j] == 1)
    {
        print_lcs(x, i - 1, j - 1);
        cout << x[i - 1];
    }
    else if (p_lcs[i][j] == 2)
    {
        print_lcs(x, i - 1, j);
    }
    else
        print_lcs(x, i, j - 1);
}

int lcs(string x, string y, int i, int j)
{
    if (i == 0 or j == 0)
    {
        return c[i][j] = 0;
    }
    if (c[i][j] != -1)
        return c[i][j];

    if (x[i - 1] == y[j - 1])
    {
        p_lcs[i][j] = 1;
        return c[i][j] = lcs(x, y, i - 1, j - 1) + 1;
    }
    else
    {
        int l_lcs = lcs(x, y, i - 1, j);
        int r_lcs = lcs(x, y, i, j - 1);
        if (l_lcs >= r_lcs)
        {
            p_lcs[i][j] = 2;
        }
        else
            p_lcs[i][j] = 3;

        return c[i][j] = max(l_lcs, r_lcs);
    }
}
int tabulation_table[100][100];

void lcs2(string x, string y)
{
    int m = x.length();
    int n = y.length();

    for (int i = 0; i <= m; i++)
    { // Fix the loop limit here
        tabulation_table[i][0] = 0;
    }
    for (int i = 0; i <= n; i++)
    { // Fix the loop limit here
        tabulation_table[0][i] = 0;
    }

    for (int i = 1; i <= m; i++)
    { // Fix the loop limit here
        for (int j = 1; j <= n; j++)
        { // Fix the loop limit here
            if (x[i - 1] == y[j - 1])
            {
                tabulation_table[i][j] = tabulation_table[i - 1][j - 1] + 1;
            }
            else if (tabulation_table[i - 1][j] >= tabulation_table[i][j - 1])
            {
                tabulation_table[i][j] = tabulation_table[i - 1][j];
            }
            else
            {
                tabulation_table[i][j] = tabulation_table[i][j - 1];
            }
        }
    }

    cout << tabulation_table[m][n];
}

int main()
{

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            c[i][j] = -1;
        }
    }

    string a = "anpxyz", b = "analpnz";
    cout << lcs(a, b, a.length(), b.length());
    // lcs2(a,b);

    print_lcs(a, a.length(), b.length());
}