#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Initialize binary sequence and maximum number of allowed zeros
    vector<int> v = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k = 3;

    // Initialize variables to keep track of zeros and maximum substring length
    int zerocount = 0, length = 0;

    // Use sliding window approach to find maximum substring length
    for (int right = 0, left = 0; right < v.size(); right++)
    {
        // Increment zerocount if current element is 0
        if (v[right] == 0)
            zerocount++;

        // If zerocount exceeds k, slide the window to the right until zerocount <= k
        while (zerocount > k)
        {
            if (v[left] == 0)
                zerocount--;
            left++;
        }

        // Update maximum substring length with the difference between right and left index
        length = max(length, right - left + 1);
    }

    // Output the length of the largest substring of 1's with at most k zeros
    cout << length << endl;

    return 0;
}

/*
This is a C++ program that finds the length of the largest substring of 1's in a given vector of binary values, with at most k zeros allowed.

The program first initializes a vector v with a binary sequence. It then sets an integer k to the maximum number of zeros allowed in the substring. Two variables zerocount and length are also initialized to keep track of the number of zeros in the current substring and the length of the largest substring found so far.

The program uses a sliding window approach to iterate over the vector v. The for loop runs over the right end of the window, which starts at index 0. At each step, if the value at the current index is 0, the zerocount variable is incremented. If the zerocount variable exceeds k, the program slides the window to the right by incrementing the left index and decrementing the zerocount variable, until zerocount is less than or equal to k.

After each slide, the program updates the length variable with the maximum length of the current substring of 1's. The maximum length is calculated as the difference between the current right index and the left index, plus 1. Finally, the program prints the length of the largest substring of 1's with at most k zeros.

This program has a time complexity of O(n), where n is the size of the vector v. The space complexity is O(1), as it only uses a constant amount of extra memory for variables zerocount, length, and k.
*/