#include <bits/stdc++.h>
using namespace std;

vector<int> nodes[200];
// map<int, int> mp;

void toposort(map<int, char> mpc, map<int, int> mp, int node)
{
    queue<int> q;
    for (int i = 1; i < node; i++)
    {
        if (mp[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int x = q.front();
        cout << mpc[x] << " ";
        q.pop();
        for (auto ele : nodes[x])
        {
            mp[ele]--;
            if (mp[ele] == 0)
            {
                q.push(ele);
            }
        }
    }
}

int main()
{

    int node, edge;
    cin >> node >> edge;
    map<int, int> mp;

    map<int, char> mpc;
    mpc[1] = 'a';
    mpc[2] = 'b';
    mpc[3] = 'c';
    mpc[4] = 'd';
    mpc[5] = 'e';
    mpc[6] = 'f';

    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        nodes[u].push_back(v);
        mp[v]++;
    }

    toposort(mpc, mp, node);
}