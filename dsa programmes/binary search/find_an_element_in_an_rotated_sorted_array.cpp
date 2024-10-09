#include <bits/stdc++.h>
using namespace std;

// Macros for faster I/O and setting integer type as long long
#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define int long long

int binary_search_in_rotated_array(vector<int> &v, int key)
{
    // Initializing high, low and mid for binary search
    int high = v.size() - 1;
    int low = 0;
    int mid;

    // Performing binary search to find the index of the pivot element
    // The pivot element is the element where the sorted array was rotated
    while (low <= high)
    {
        mid = low + (high - low) / 2;

        // Checking if mid is the pivot element
        if (v[mid] < v[mid - 1])
        {
            break;
        }
        // If mid is greater than the first element, the pivot element is to the right
        else if (v[mid] >= v[0])
        {
            low = mid + 1;
        }
        // If mid is less than the first element, the pivot element is to the left
        else if (v[mid] < v[0])
        {
            high = mid - 1;
        }
    }

    // Performing binary search on the two sub-arrays to find the index of the key
    if (key >= v[0])
    {
        // If the key is greater than or equal to the first element, search the left sub-array
        // The left sub-array is from the beginning of the original array to the pivot element
        int a = distance(v.begin(), lower_bound(v.begin(), v.begin() + mid - 1, key));
        return a;
    }
    else
    {
        // If the key is less than the first element, search the right sub-array
        // The right sub-array is from the pivot element to the end of the original array
        int b = distance(v.begin(), lower_bound(v.begin() + mid, v.end(), key));
        return b;
    }
}

signed main()
{
    fast_io(); // Enable faster I/O

    // Initialize the vector and the key
    vector<int> v = {5, 6, 7, 8, 9, 10, 1, 2, 3, 4};
    int k = 2;

    // Iterate over the key range and print the index of each key
    for (int i = 1; i < 11; i++)
        cout << i << " is on index " << binary_search_in_rotated_array(v, i) << endl;

    return 0;
}

/*
The binary_search_in_rotated_array() function performs binary search on the given rotated array to find the index of a given key.

The function first finds the pivot element, which is the element where the sorted array was rotated. This is done by performing binary search on the array until the pivot element is found.

Then, depending on whether the key is greater than or less than the first element of the original array, the function performs binary search on one of the two sub-arrays. The left sub-array is from the beginning of the original array to the pivot element, and the right sub-array is from the pivot element to the end of the original array.

Finally, the function returns the index of the key in the array.

In the main() function, the vector and the key are initialized, and the binary_search_in_rotated_array() function is called for
*/