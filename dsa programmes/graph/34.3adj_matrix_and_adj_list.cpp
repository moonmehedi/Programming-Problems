
/*
this code is for undirected graph
*/

/*
This code creates an adjacency matrix and adjacency list representation of an undirected graph.

Here's a step-by-step explanation of the code:

The code starts by including the necessary header files (<bits/stdc++.h> and <vector>) and declaring a global variable List which is an array of vectors. This array will be used to store the adjacency list representation of the graph.

In the main() function, the number of nodes and edges of the graph are read from the input.

A 2D vector v_adj_mat is created with size (number_of_nodes + 1) x (number_of_nodes + 1). This vector represents the adjacency matrix of the graph. The matrix is initialized with all zeros.

The code enters a loop to read the edges of the graph from the input. For each edge, the nodes node1 and node2 are read.

The code then updates both the adjacency matrix and adjacency list representation of the graph:

The adjacency matrix is updated by setting v_adj_mat[node1][node2] and v_adj_mat[node2][node1] to 1, indicating an edge between node1 and node2.

The adjacency list is updated by pushing node2 to the vector List[node1] and node1 to the vector List[node2]. This represents the connection between node1 and node2 in the adjacency list.

After reading all the edges and updating the representations, the code prints the adjacency matrix by iterating over v_adj_mat and printing the values.

Then, the code prints the adjacency list by iterating over each node from 1 to number_of_nodes. For each node, it prints the node number followed by "->" and then iterates over the elements of the corresponding vector in List, printing the connected nodes.

The code effectively constructs both the adjacency matrix and adjacency list representations of the graph based on the input edges, and then prints them to the console.
*/

/*
         1
      /   \
    2      3
  / |\ \  /
 4  5 6 7

*/

#include <bits/stdc++.h>
using namespace std;

// adjacency list
vector<int> List[1000]; // this line represents an array of vectors

int main()
{
    int number_of_nodes, number_of_edges;
    cin >> number_of_nodes >> number_of_edges;

    vector<vector<int>> v_adj_mat(number_of_nodes + 1, vector<int>(number_of_nodes + 1, 0));

    // this loop makes relation among the nodes
    for (int i = 0; i < number_of_edges; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;

        // this makes adjacency matrix
        v_adj_mat[node1][node2] = 1;
        v_adj_mat[node2][node1] = 1;

        // this code makes adjacency list
        //  if related them push the values in arrays node vector
        List[node1].push_back(node2);
        List[node2].push_back(node1);
    }

    cout << "adjacency matrix " << endl;
    // as starting from

    // print adj matrix
    for (int i = 1; i <= number_of_nodes; i++)
    {
        for (int j = 1; j <= number_of_nodes; j++)
        {
            cout << v_adj_mat[i][j];
        }
        cout << endl;
    }

    cout << "adjancacy List " << endl;

    // print adj list
    for (int node = 1; node <= number_of_nodes; node++)
    {
        cout << "list for " << node << "->";
        for (auto relative_nodes : List[node])
            cout << relative_nodes << " ";
        cout << endl;
    }
}