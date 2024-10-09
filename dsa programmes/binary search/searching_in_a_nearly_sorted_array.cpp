#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

// define a function to search for an element in a nearly sorted array
int searching_in_a_nearly_sorted_array(vector<int> &v, int key)
{
    int high = v.size() - 1; // define highest index
    int low = 0;             // define lowest index
    while (low <= high)      // continue until low and high cross each other
    {
        int mid = low + (high - low) / 2;          // find the middle index
        if (v[mid] == key)                         // if middle element is the key
            return mid;                            // return its index
        else if (mid > 1 && v[mid - 1] == key)     // if previous element is the key
            return mid - 1;                        // return its index
        else if (mid < high and v[mid + 1] == key) // if next element is the key
            return mid + 1;                        // return its index
        else if (v[mid] > key)                     // if middle element is greater than key
        {
            high = mid - 1; // search in left half
        }
        else if (v[mid] < key) // if middle element is smaller than key
        {
            low = mid + 1; // search in right half
        }
    }
    return -1; // return -1 if key not found
}

signed main()
{
    fast_io();                                          // call macro to enable faster I/O
    vector<int> v = {10, 3, 40, 20, 50, 80, 70};        // initialize vector
    int key = 40;                                       // set the key to search
    cout << searching_in_a_nearly_sorted_array(v, key); // call the search function and print the result

    return 0; // indicate successful completion of program
}

/*

whis is a nearly sorted array
condition;
an element which is suppose to be at index i could be present at
index i-1 and i+1;


*/