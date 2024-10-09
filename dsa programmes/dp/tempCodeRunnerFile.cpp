#include <iostream>
using namespace std;

int knapsack(int values[], int weights[], int capacity, int n) {
    // Base case: If the capacity is 0 or no items are left, the value is 0.
    if (capacity == 0 || n == 0)
        return 0;

    // If the weight of the nth item is more than the capacity, it cannot be included.
    if (weights[n - 1] > capacity)
        return knapsack(values, weights, capacity, n - 1);

    // Return the maximum of two cases:
    // 1. Include the nth item
    // 2. Exclude the nth item
    return max(values[n - 1] + knapsack(values, weights, capacity - weights[n - 1], n - 1),
               knapsack(values, weights, capacity, n - 1));
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int capacity = 50;
    int n = sizeof(values) / sizeof(values[0]);

    int result = knapsack(values, weights, capacity, n);
    cout << "Maximum value in the knapsack: " << result << endl;

    return 0;
}
