#include <bits/stdc++.h>
using namespace std;

// Function to perform binary search on an infinite sorted array

// an array is infinite sorted array if it's high is unknown
int binarySearch(vector<int> &arr, int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Key not found
}

// Function to search for an element in an infinite sorted array
int searchInfiniteArray(vector<int> &arr, int key)
{
    int low = 0, high = 1;
    while (arr[high] < key)
    {
        low = high;
        high = 2 * high;
    }
    return binarySearch(arr, low, high, key);
}

// Driver code
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    int key = 21;
    int index = searchInfiniteArray(arr, key);
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}