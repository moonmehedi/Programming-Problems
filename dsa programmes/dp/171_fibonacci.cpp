#include <bits/stdc++.h>
using namespace std;

vector<int> dp(2000, -1); // DP table to store computed Fibonacci numbers

int fib(int n)
{
    if (n == 1 or n == 0)
    {
        return n; // Base case: if n is 0 or 1, return n
    }

    if (dp[n] != -1)
    {
        return dp[n]; // If the value for 'n' is already computed, return it
    }

    return dp[n] = fib(n - 1) + fib(n - 2); // Compute Fibonacci number recursively and store it in the DP table
}

vector<int> dp2(2000, -1); // DP table to store computed Fibonacci numbers

int bottom_up_fib(int n)
{
    dp2[0] = 0; // Base case: F(0) = 0
    dp2[1] = 1; // Base case: F(1) = 1

    for (int i = 2; i <= n; i++)
    {
        dp2[i] = dp2[i - 1] + dp2[i - 2]; // Compute Fibonacci number iteratively and store it in the DP table
    }

    return dp2[n]; // Return the computed Fibonacci number for 'n'
}

int main()
{
    int n;
    cin >> n;

    cout << fib(n) << endl;           // Compute Fibonacci number using the recursive approach (memoization)
    cout << bottom_up_fib(n) << endl; // Compute Fibonacci number using the bottom-up approach

    return 0;
}
/*This code calculates the Fibonacci number for a given input n using two different approaches: the recursive approach with memoization (fib) and the bottom-up approach (bottom_up_fib).

In the recursive approach, the function fib computes the Fibonacci number recursively. It utilizes a DP table dp to store already computed Fibonacci numbers. If the Fibonacci number for n is already present in the DP table, it returns the stored value; otherwise, it calculates the Fibonacci number by recursively summing up the two previous Fibonacci numbers (n-1 and n-2) and stores the result in the DP table.

In the bottom-up approach, the function bottom_up_fib iteratively calculates the Fibonacci numbers from 0 to n and stores them in the DP table dp2. It starts with the base cases (F(0) = 0 and F(1) = 1) and computes each subsequent Fibonacci number by summing up the two previous Fibonacci numbers (n-1 and n-2).

The main function reads the input number n and calls both the fib and bottom_up_fib functions to compute the Fibonacci number. The results are then printed on the console.*/