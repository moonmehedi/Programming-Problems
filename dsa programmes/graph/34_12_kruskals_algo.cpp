#include<bits/stdc++.h>
using namespace std;

vector<int> parent(200);
vector<int> sz(200);

void make_parent(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_parent(int v) {
    if (parent[v] == v) {
        return v;
    }

    return parent[v] = find_parent(parent[v]);
}

bool Union(int a, int b) {
    int u = find_parent(a);
    int v = find_parent(b);

    if (u != v) {
        if (sz[u] < sz[v])
            swap(u, v);
        parent[v] = u;
        sz[u] = sz[u] + sz[v];

        return true;
    }

    return false;
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < nodes; i++) {
        make_parent(i);
    }

    vector<vector<int>> edge;
    for (int i = 0; i < edges; i++) {
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;
        edge.push_back({weight, node1, node2});
    }

    sort(edge.begin(), edge.end());

    for (auto ele : edge) {
        int w = ele[0];
        int a = ele[1];
        int b = ele[2];

        if (Union(a, b)) {
            cout << a << " " << b << " " << w << endl;
        }
    }

    return 0;
}