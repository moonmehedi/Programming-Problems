#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

// Function to check if there are two elements in an array whose sum equals a target value
bool hasArrayTwoCandidates(int arr[], int n, int x)
{
    // Sort the array in ascending order
    sort(arr, arr + n);

    // Initialize two pointers, one pointing to the first element of the array, and one to the last
    int small = 0, large = n - 1;

    // While there are still elements to check
    while (small < large)
    {
        // Calculate the sum of the elements pointed to by the two pointers
        int result = arr[small] + arr[large];

        // If the sum equals the target value, return true
        if (result == x)
        {
            return true;
        }
        // If the sum is less than the target value, move the smaller pointer to the right to consider larger elements
        else if (result < x)
        {
            small++;
        }
        // If the sum is greater than the target value, move the larger pointer to the left to consider smaller elements
        else
        {
            large--;
        }
    }
    // If no two elements are found whose sum equals the target value, return false
    return false;
}

signed main()
{
    fast_io(); // enable faster I/O

    // Initialize an array of integers
    int arr[] = {335, 501, 170, 725, 479, 359, 963, 465, 706, 146, 282, 828, 962, 492, 996, 943, 828, 437, 392, 605, 903, 154, 293, 383, 422, 717, 719, 896, 448, 727, 772, 539, 870, 913, 668, 300, 36, 895, 704, 812, 323, 334};

    // Call the hasArrayTwoCandidates function with the array, its size, and the target value
    cout << hasArrayTwoCandidates(arr, 42, 468);

    return 0;
}

/*
This program checks if there are two elements in an array whose sum equals a given target value x.

The function hasArrayTwoCandidates takes three arguments:

arr is a pointer to the first element of the array
n is the size of the array
x is the target value
The first step is to sort the array in ascending order using the sort function from the algorithm library. Then, two pointers, small and large, are initialized to the beginning and end of the array, respectively.

In the while loop, the program computes the sum of the elements pointed by the small and large pointers. If the sum equals x, the function returns true. If the sum is less than x, small is incremented to consider larger elements. If the sum is greater than x, large is decremented to consider smaller elements.

If no two elements are found whose sum equals x, the function returns false.

In the main function, an array arr of size 42 is initialized and hasArrayTwoCandidates is called with arr, 42, and 468 as arguments. The result is printed to the console.
*/