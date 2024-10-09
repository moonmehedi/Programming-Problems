#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

// This function takes a reference to a vector of integers as input and returns an integer
int rotation_count(vector<int> &hasan)
{
    int high = hasan.size() - 1; // set the high pointer to the last index of the array
    int low = 0;                 // set the low pointer to the first index of the array

    // continue until the low pointer is less than or equal to the high pointer
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // calculate the middle index using binary search

        // if the element at the middle index is greater than the element at the next index, return the middle index
        if (!(hasan[mid] < hasan[mid + 1]))
            return mid;

        // if the element at the middle index is less than or equal to the element at the first index,
        // the rotation has occurred in the left half of the array, so update the high pointer
        else if (hasan[mid] <= hasan[low])
        {
            high = mid - 1;
        }
        // otherwise, the rotation has occurred in the right half of the array, so update the low pointer
        else
            low = mid + 1;
    }
    // if the loop completes without finding any rotations, return -1
    return -1;
}

signed main()
{
    fast_io();     // enable faster I/O
    vector<int> v; // create a vector of integers
    int n;
    cin >> n; // read in the size of the array
    cout << "enter array elements " << endl;

    for (int i = 0; i < n; i++) // loop n times to read in the elements of the array
    {
        int temp;
        cin >> temp;
        v.push_back(temp); // add the element to the vector
    }
    int number_of_rotation = rotation_count(v); // call the rotation_count function to get the number of rotations
    cout << number_of_rotation + 1;             // print the result to the console

    return 0;
}
/*
This code is an implementation of the binary search algorithm to find the number of rotations in a rotated sorted array.

The rotation_count function takes a reference to a vector of integers hasan as an argument and returns an integer. The function first initializes the high and low pointers to the last and first indices of the vector, respectively.

The while loop continues until low is less than or equal to high. Inside the loop, the function calculates the middle index mid using the formula (high + low) / 2.

If the element at hasan[mid] is greater than the element at hasan[mid + 1], it means the array has been rotated mid times, and the function returns mid.

Otherwise, if the element at hasan[mid] is less than or equal to the element at hasan[low], the rotation has occurred in the left half of the array, and the high pointer is updated to mid - 1.

Otherwise, the rotation has occurred in the right half of the array, and the low pointer is updated to mid + 1.

If the while loop completes without finding any rotations, the function returns -1.

The main function takes an input integer n and a vector v of size n. It then calls the rotation_count function to find the number of rotations in the array and prints the result to the console.







*/