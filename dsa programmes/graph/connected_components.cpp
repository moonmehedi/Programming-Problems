/*

Certainly! Here's an explanation of how the code works:

The code starts by including the necessary header file bits/stdc++.h and declares the required containers and variables.

The adj variable is a vector of vectors that represents the adjacency list of the graph. Each element of the vector represents a node, and the corresponding vector contains the adjacent nodes.

The is_visited vector is used to keep track of whether a node has been visited or not. Initially, all nodes are marked as not visited (false).

The print_connected_compo function is a recursive function that implements a depth-first search (DFS) to visit the connected components of the graph.

The function takes two parameters: i represents the current node being visited, and found is a flag indicating whether a connected component has been found or not.

Inside the function, it checks if the current node i has not been visited yet. If it hasn't, it proceeds to visit it.

If found is false, it means that a new connected component is being visited, so it prints the message "connected compo :" to indicate the start of a new component.

The node i is marked as visited (is_visited[i] = true), and it is printed as part of the connected component.

Then, for each adjacent node j of the current node i, the function recursively calls print_connected_compo with j as the new current node and true as the new value for found.

The function continues the DFS process until there are no more unvisited nodes reachable from the current node. It returns true to indicate that a connected component has been visited.

If the current node i has already been visited, the function simply returns false.

In the main function, it reads the number of nodes and edges from the input.

It then reads the edges and populates the adjacency list (adj) accordingly.

Finally, it iterates through each node from 1 to nodes and calls print_connected_compo for each unvisited node, passing false as the initial value of found.

The print_connected_compo function is responsible for printing the connected components of the graph.

The code will output the connected components, where each component is preceded by the message "connected compo :".

That's the overall working of the code. It uses DFS to find and print the connected components of an undirected graph.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(200);        // Adjacency list to store the graph
vector<bool> is_visited(200, false); // Keep track of visited nodes

/*
Recursive function to print the connected components
*/
bool print_connected_compo(int i, int found)
{
    if (is_visited[i] == false) // Check if the current node is not visited
    {
        if (found == false)
        {
            cout << "connected compo :"; // Message for the start of a new connected component
        }
        is_visited[i] = true; // Mark the current node as visited
        cout << i << " ";     // Print the current node
        for (auto j : adj[i]) // Traverse the adjacent nodes of the current node
        {
            print_connected_compo(j, true); // Recursively call the function for each adjacent node
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
        print_connected_compo(i, false);
    }
}