#include<bits/stdc++.h>
using namespace std;

vector<int> dp(2000, 1); // Vector to store memoized values of LIS

// Recursive function to calculate the length of the LIS
int lis(vector<int> arr, int idx) {
    if (idx == 0) {
        return dp[0]; // If it's the initial element, return 1 because it's also a valid LIS
    }
    if (dp[idx] != 1) {
        return dp[idx]; // If the LIS for the current index is already calculated, return it
    }
    for (int i = 0; i < idx; i++) { // Iterate over previous elements
        if (arr[i] < arr[idx]) { // If the condition for increasing subsequence is satisfied
            dp[idx] = max(dp[idx], 1 + lis(arr, i)); // Update the LIS for the current index
        }
    }
    return dp[idx]; // Return the LIS for the current index
}

vector<int> dp2(1000, 1); // Vector to store dynamic programming values of LIS

// Function to calculate the length of the LIS using dynamic programming
int lis_t(vector<int> v, int n) {
    dp2[0] = 1; // Base case: LIS for the first element is always 1
    for (int i = 0; i < n; i++) { // Iterate over the elements of the sequence
        for (int j = 0; j < i; j++) { // Iterate over previous elements
            if (v[i] > v[j]) { // If the condition for increasing subsequence is satisfied
                dp2[i] = max(dp2[i], 1 + dp2[j]); // Update the LIS for the current index
            }
        }
    }
    return dp2[n - 1]; // Return the LIS for the last index
}

int main() {
    int n; cin >> n; // Read the length of the input sequence
    vector<int> arr(n); // Vector to store the input sequence
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Read each element of the sequence
    }
    cout << lis(arr, n - 1) << endl; // Calculate LIS using recursive with memoization
    cout << lis_t(arr, n) << endl; // Calculate LIS using dynamic programming
    return 0;
}
/*Concept and Working Principle:

The code calculates the length of the Longest Increasing Subsequence (LIS) of a given sequence of numbers.
The LIS represents the maximum length of a subsequence where the elements are in increasing order.
The code provides two approaches to solve the problem: recursive with memoization and dynamic programming.
The recursive approach (lis function) uses memoization to store previously calculated LIS values and avoids redundant calculations.
The dynamic programming approach (lis_t function) uses a bottom-up approach to fill a dynamic programming table to compute the LIS.
In both approaches, the code iterates over the elements of the sequence and compares them with the previous elements to determine the increasing subsequence.
The LIS value is updated based on the maximum length found so far.
Finally, the code reads the input sequence, calls the LIS functions, and outputs the calculated LIS lengths.
The time complexity of the code is O(n^2) for both approaches due to the nested loops. However, the dynamic programming approach is generally more efficient.*/