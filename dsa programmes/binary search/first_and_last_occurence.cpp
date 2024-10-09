#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

// function to find the first occurrence of key in the array
int first_occurrence(int a[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int result = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2; // to avoid integer overflow
        if (a[mid] == key)
        {
            result = mid;
            high = mid - 1;
        }
        else if (a[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}

// function to find the last occurrence of key in the array
int last_occurrence(int a[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int result = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2; // to avoid integer overflow
        if (a[mid] == key)
        {
            result = mid;
            low = mid + 1;
        }
        else if (a[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}

signed main()
{
    fast_io(); // enable faster I/O

    // input the array size and elements
    cout << "Enter the size of the array: " << endl;
    int n;
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // input the key to search
    cout << "Enter the element to search: " << endl;
    int key;
    cin >> key;

    // find the first and last occurrence of key in the array
    int first_index = first_occurrence(arr, n, key);
    int last_index = last_occurrence(arr, n, key);

    // print the results
    if (first_index == -1)
    {
        cout << "Element not found in the array" << endl;
    }
    else
    {
        cout << "First occurrence of " << key << " is at index " << first_index << endl;
        cout << "Last occurrence of " << key << " is at index " << last_index << endl;
    }

    return 0;
}

/*
The code defines two functions first_occurrence() and last_occurrence() that take an array a, its size n, and a key to search for key as input. These functions implement the Binary Search algorithm to find the first and last occurrences of the key in the array.

The first_occurrence() function initializes the low, high, and result variables to 0, n - 1, and -1, respectively. It then enters a loop that runs while low <= high, and calculates the mid index as low + (high - low) / 2 to prevent integer overflow. If a[mid] is equal to key, the result variable is updated to mid, and the high variable is updated to mid - 1 to search for the first occurrence of the key. If a[mid] is greater than key, the high variable is updated to mid - 1 to search in the left half of the array. If a[mid] is less than key, the low variable is updated to mid + 1 to search in the right half of the array. The function returns the result variable, which contains the index of the first occurrence of the key in the array.

The last_occurrence() function works in a similar way to the `first_occurrence
*/