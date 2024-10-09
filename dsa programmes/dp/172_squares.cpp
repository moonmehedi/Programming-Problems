#include <bits/stdc++.h>
using namespace std;

// Memoization (Top-down) Approach
vector<int> dp(2000, INT_MAX); // DP table to store computed values

int sq(int n)
{
    if (n == 0)
    {
        return 0; // Base case: If n is 0, return 0
    }

    if (dp[n] != INT_MAX)
    {
        return dp[n]; // If the value for 'n' is already computed, return it
    }

    for (int i = 1; i * i <= n; i++)
    {
        dp[n] = min(dp[n], 1 + sq(n - i * i)); // Recursively compute the minimum number of squares
    }

    return dp[n]; // Return the computed value for 'n'
}

// Bottom-up Approach
vector<int> dp1(2000, INT_MAX); // DP table to store computed values

int sq1(int n)
{
    dp1[0] = 0; // Base case: If n is 0, the answer is 0

    for (int i = 1; i <= n; i++)
    { // Build the DP table from 1 to n
        for (int j = 1; j * j <= i; j++)
        { // Build smaller blocks using perfect squares

            dp1[i] = min(dp1[i], 1 + dp1[i - j * j]); // Recursively compute the minimum number of squares
        }
    }

    return dp1[n]; // Return the computed value for 'n'
}

int main()
{
    int n;
    cin >> n;

    cout << sq(n) << endl;  // Calculate using the memoization (top-down) approach
    cout << sq1(n) << endl; // Calculate using the bottom-up approach

    return 0;
}
/*This code solves the problem of finding the minimum number of perfect squares that sum up to a given number n. It implements two approaches to solve the problem: the memoization (top-down) approach (sq) and the bottom-up approach (sq1).

In the memoization approach, a DP table dp is used to store already computed values. The function sq recursively computes the minimum number of squares by trying all possible perfect squares less than or equal to n. It utilizes the DP table to avoid recomputing values and optimize the solution.

In the bottom-up approach, a DP table dp1 is used to build the solution iteratively. The function sq1 iterates from 1 to n, considering each number as the target sum. For each number, it builds smaller blocks using perfect squares and computes the minimum number of squares required. By building the solution from smaller subproblems, it gradually builds up to the target sum n.

The main function reads the input number n and calls both the sq and sq1 functions to compute the minimum number of squares required. The results are then printed on the console.*/