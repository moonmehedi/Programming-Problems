#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

signed main()
{
    fast_io(); // enable faster I/O
    vector<int> v = {12, 3, 7, 1, 6, 9};
    int size = v.size();
    int target = 16;

    // iterate through all elements except the last two
    for (int i = 0; i < size - 2; i++)
    {
        int small = i + 1, heigh = size - 1; // initialize two pointers
        // use two pointers to solve the two sum problem for the current element
        while (small < heigh)
        {
            int result = v[i] + v[small] + v[heigh]; // calculate sum of current element and two pointers
            if (target == result)                    // if sum is equal to target, output true and exit program
            {
                cout << "true" << endl;
                return 0;
            }
            else if (target > result) // if sum is less than target, move left pointer to the right
            {
                small++;
            }
            else if (target < result) // if sum is greater than target, move right pointer to the left
            {
                heigh--;
            }
        }
    }
    cout << "false" << endl; // if program reaches this point, no triplet sum equals target

    return 0;
}
/*
This is an implementation of the "three sum problem" using the "two sum problem" algorithm. The goal is to find if there exists a triplet in a given vector of integers whose sum is equal to a given target value.

The algorithm used here is based on the fact that the two sum problem can be solved in linear time using a hash table. However, the three sum problem cannot be solved in linear time, but it can be reduced to three iterations of the two sum problem.

The outer loop of the code iterates through all elements of the vector except for the last two, as the last two elements will be covered in the inner loop.

The inner loop uses two pointers, one pointing to the next element after the current one, and the other pointing to the last element. It then calculates the sum of the current element and the two pointers. If the sum is equal to the target, the program outputs "true" and exits. If the sum is less than the target, the left pointer is moved to the right, and if the sum is greater than the target, the right pointer is moved to the left.

If the program reaches the end of the outer loop without finding a triplet that sums to the target, it outputs "false".

Overall, this algorithm has a time complexity of O(n^2) and a space complexity of O(1).
*/