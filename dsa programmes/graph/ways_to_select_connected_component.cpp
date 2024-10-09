/*
this code print the number of ways to select two node in between connected components of a graph

*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(200);        // Adjacency list to store the graph
vector<bool> is_visited(200, false); // Keep track of visited nodes
vector<int> connected_component_size;
int ans = 0;
/*
Recursive function to print the connected components
*/
bool print_connected_compo(int i, int found, int &ans)
{
    if (is_visited[i] == false) // Check if the current node is not visited
    {
        if (found == false)
        {
            cout << "connected compo :"; // Message for the start of a new connected component
        }
        is_visited[i] = true; // Mark the current node as visited
        cout << i << " ";     // Print the current node
        ++ans;
        for (auto j : adj[i]) // Traverse the adjacent nodes of the current node
        {
            print_connected_compo(j, true, ans); // Recursively call the function for each adjacent node
        }
        return true; // Indicate that a connected component has been visited
    }
    else
    {
        return false; // Indicate that the current node has already been visited
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges; // Read the number of nodes and edges from input

    // Read the edges and populate the adjacency list
    for (int i = 1; i <= edges; i++)
    {
        int nodes1, nodes2;
        cin >> nodes1 >> nodes2;
        adj[nodes1].push_back(nodes2);
        adj[nodes2].push_back(nodes1);
    }

    // Visit and print the connected components
    for (int i = 1; i <= nodes; i++)
    {
        if (!is_visited[i])
        {
            print_connected_compo(i, false, ans);
            connected_component_size.push_back(ans);
            ans = 0;
        }
    }

    cout << endl
         << "length of connected elements ";

    for (auto i : connected_component_size)
    {
        cout << i << " ";
    }

    for (auto i : connected_component_size)
    {
        // it means number of possible connection of every connect elements of a graph with rest of the dis-connected elements
        ans += i * (nodes - i);
    }
    // here we are counting connection from a to b and b to a as well se we have to divide the ans with two
    cout << endl
         << "the number of ways to select two node in between connected components of a graph :" << ans / 2;
}