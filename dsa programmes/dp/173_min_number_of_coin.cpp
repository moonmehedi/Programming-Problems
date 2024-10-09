#include<bits/stdc++.h>
using namespace std;

int coins[3] = {1, 2, 3};
vector<int> dp(2000, 1e9); // Dynamic programming table

int minCoins(int n) {
    if (n == 0) {
        return 0; // Base case: If n is 0, no coins are needed
    }
    if (n < 0) {
        return 1e9; // Base case: If n is negative, return a large value to indicate infeasibility
    }
    if (dp[n] != 1e9) {
        return dp[n]; // If the minimum number of coins for n is already computed, return the result from dp
    }

    for (int i = 0; i < 3; i++) {
        dp[n] = min(dp[n], 1 + minCoins(n - coins[i])); // Recursively calculate the minimum number of coins
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n; // Read the value of n from the user

    cout << "Minimum number of coins required to make " << n << ": ";
    cout << minCoins(n) << endl; // Calculate and print the minimum number of coins required

    return 0;
}
/*Explanation:

The code defines an array coins that represents the available coin denominations, in this case, [1, 2, 3].
The vector dp is initialized with a large value 1e9. This vector is used as a dynamic programming table to store the minimum number of coins required for different values of n.
The minCoins function is a recursive function that calculates the minimum number of coins needed to make a value n. It uses the dynamic programming approach to avoid redundant calculations.
The function checks for base cases: if n is 0, it returns 0 as no coins are needed. If n is negative, it returns a large value 1e9 to indicate infeasibility.
If the minimum number of coins for n is already computed and stored in the dynamic programming table dp, it directly returns the result.
Otherwise, it iterates through the available coin denominations and recursively calculates the minimum number of coins required by subtracting each coin from n.
The minimum number of coins is updated in the dynamic programming table dp.
Finally, in the main function, the code reads the value of n from the user, calls the minCoins function to calculate the minimum number of coins required, and prints the result.
Overall, the program uses dynamic programming to efficiently solve the minimum number of coins problem and provides the minimum number of coins required to make the given value n using the available coin denominations.*/