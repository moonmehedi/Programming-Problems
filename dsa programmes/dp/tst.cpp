#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int coins[3] = {1, 2, 3};
vector<int> dp(2000, INT_MAX);

int min_n(int n) {
    if (n == 0) {
        return 0;
    } else if (n < 0) {
        return INT_MAX;
    } else if (dp[n] != INT_MAX) {
        return dp[n];
    }

    for (int i = 0; i < 3; i++) {
        dp[n] = min(dp[n], 1 + min_n(n - coins[i]));
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << min_n(n) << endl;
}