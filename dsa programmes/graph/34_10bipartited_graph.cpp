/*
The purpose of the provided code is to check whether a given undirected graph is bipartite or not. A bipartite graph is a graph that can be divided into two disjoint sets such that every edge connects a node from one set to a node from the other set.

Let's analyze the code to understand how it achieves this:

The code starts by including the necessary header file bits/stdc++.h and declares the required containers and variables.

The adj vector is a 2D vector that represents the adjacency list of the graph. Each element of the vector represents a node, and the corresponding vector contains the adjacent nodes.

The visited vector is used to keep track of whether a node has been visited or not. It is initially set to false for all nodes.

The colored vector is used to assign colors to nodes. Initially, all nodes are colored as -1 to indicate that they have not been assigned any color.

The boolean variable is_bipartited is used to determine whether the graph is bipartite or not. It is initially set to true.

The color function is a recursive function that assigns colors to the nodes using a modified depth-first search (DFS) algorithm.

The color function takes two parameters: i, which represents the current node being colored, and curr_color, which is the color (0 or 1) assigned to the current node.

Inside the function, it checks if the current node i has a conflicting color with the current color curr_color. If a conflict is found, it sets is_bipartited to false, indicating that the graph is not bipartite. Then, it prints the value of is_bipartited and exits the program.

If the current node has already been assigned a color, it simply returns without further exploration.

If the current node has not been assigned a color, it assigns the current color to the node (colored[i] = curr_color) and recursively calls the color function for each adjacent node, passing the opposite color (curr_color xor 1) as the new color.

In the main function, it reads the number of nodes and edges from the input.

It then reads the edges and populates the adjacency list (adj) accordingly.

The code iterates through each node and checks if it has been assigned a color. If not, it calls the color function for that node, starting with color 0.

After coloring all nodes, it checks the value of is_bipartited to determine if the graph is bipartite or not. It prints the corresponding message accordingly.

The code determines whether the graph is bipartite by applying a modified DFS algorithm that assigns colors to nodes and checks for color conflicts.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(200);
vector<bool> visited(200);
vector<int> colored(200, -1);
bool is_bipartited = true;

void color(int i, int curr_color)
{
    if (colored[i] != curr_color and colored[i] != -1)
    {
        is_bipartited = false;
        cout << is_bipartited;
        exit;
    }
    else
    {
        if (colored[i] != -1)
        {
            return;
        }
        colored[i] = curr_color;
        for (auto j : adj[i])
        {
            color(j, curr_color xor 1);
        }
    }
}
int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 1; i <= nodes; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;

        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    for (int i = 1; i <= nodes; i++)
    {
        if (colored[i] == -1)
            color(i, 0);
    }

    if (is_bipartited)
    {
        cout << "graph is bipartited " << endl;
    }
    else
    {
        cout << "graph is not bipartited " << endl;
    }
}