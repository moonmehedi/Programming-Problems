#include <bits/stdc++.h>
using namespace std;

int m = 1e5;
vector<int> a(m);        // Array to store the elements
vector<int> tree(4 * m); // Segment tree

// Function to build the segment tree
void build_tree(int tree_node, int start, int stop) {
    if (start == stop) {
        // Leaf node
        tree[tree_node] = a[start];
        return;
    } else {
        int mid = (start + stop) / 2;

        // Recursively build the left and right subtrees
        build_tree(2 * tree_node, start, mid);
        build_tree(2 * tree_node + 1, mid + 1, stop);

        // Merge the results of the left and right subtrees
        tree[tree_node] = max(tree[2 * tree_node], tree[2 * tree_node + 1]);
    }
}

// Function to perform maximum query on the segment tree
int max_query(int tree_node, int start, int stop, int left, int right) {
    if (start > right || stop < left) {
        // No overlap with the query range
        return INT_MIN;
    } else if (left <= start && stop <= right) {
        // Complete overlap with the query range
        return tree[tree_node];
    } else {
        // Partial overlap with the query range
        int mid = (start + stop) / 2;
        int left_max = max_query(2 * tree_node, start, mid, left, right);
        int right_max = max_query(2 * tree_node + 1, mid + 1, stop, left, right);

        // Merge the results of the left and right subtrees
        return max(left_max, right_max);
    }
}

// Function to update the value of an element in the array and segment tree
void update(int tree_node, int start, int stop, int pos, int val) {
    if (start == stop && start == pos) {
        // Leaf node representing the position to be updated
        a[start] = val;
        tree[tree_node] = val;
        return;
    }

    int mid = (start + stop) / 2;

    if (mid >= pos) {
        // Update the left subtree
        update(2 * tree_node, start, mid, pos, val);
    } else {
        // Update the right subtree
        update(2 * tree_node + 1, mid + 1, stop, pos, val);
    }

    // Update the current node with the maximum value from its children
    tree[tree_node] = max(tree[2 * tree_node], tree[2 * tree_node + 1]);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Read the elements of the array
    }

    build_tree(1, 0, n - 1); // Build the segment tree

    while (true) {
        int ch;
        cin >> ch; // Read the choice

        if (ch == 1) {
            break; // Exit the program
        } else if (ch == 2) {
            int left, right;
            cin >> left >> right;
            // Perform maximum query on the range [left, right]
            cout << max_query(1, 0, n - 1, left, right) << endl;
        } else if (ch == 3) {
            int pos, val;
            cin >> pos >> val;
            // Update the value at position 'pos' with 'val'
            update(1, 0, n - 1, pos, val);

            // Perform maximum query on the entire range [0, n-1]
            cout << max_query(1, 0, n - 1, 0, n - 1) << endl;
        }
    }

    return 0;
}

/*
The program builds a segment tree to efficiently perform maximum range queries and updates on an array of integers. Here's how it works:

The program reads the number of elements in the array, n, and the elements themselves.
The build_tree function recursively constructs the segment tree. It starts by checking if the current node represents a leaf (start == stop). If so, it stores the value of the corresponding element in the array. Otherwise, it divides the range into two halves and builds the left and right subtrees. Finally, it merges the results from the left and right subtrees by taking the maximum value.
The max_query function is used to perform a maximum range query on the segment tree. It takes the current node, its range [start, stop], and the query range [left, right]. There are three cases to consider: no overlap, full overlap, and partial overlap. It returns the maximum value accordingly by recursively querying the left and right subtrees.
The update function is used to update the value of an element in both the array and the segment tree. It starts by finding the appropriate leaf node representing the position to be updated. It then updates the value in the array and propagates the changes up the tree by updating the current node with the maximum value from its children.
In the main function, the program enters an infinite loop and waits for user input. The user can choose option 1 to exit the program, option 2 to perform a maximum range query by providing the range [left, right], or option 3 to update the value at a specific position by providing the position and the new value. After each update, it performs a maximum query on the entire range [0, n-1] to test if the update was successful.
*/