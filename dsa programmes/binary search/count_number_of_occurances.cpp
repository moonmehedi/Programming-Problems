#include <bits/stdc++.h> // includes all the necessary headers for competitive programming
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr) // macro for faster input/output operations

#define int long long // macro to define int as a long long data type
#define endl '\n'     // macro for end-of-line character

signed main()
{
    fast_io(); // enable faster input/output operations
    int n;
    cout << "enter size of array " << endl; // prompt user to enter size of array
    cin >> n;                               // read the size of array from user
    vector<int> v(n);                       // create a vector of size n to store the elements
    cout << "enter element" << endl;        // prompt user to enter the elements
    for (int i = 0; i < n; i++)             // loop to read the elements of the vector
    {
        cin >> v[i]; // read the ith element of the vector from user
    }
    cout << "enter key" << endl; // prompt user to enter the key element
    int key;
    cin >> key; // read the key element from user
    cout << "count of the element" << endl;

    auto first = lower_bound(v.begin(), v.end(), key); // find the first occurrence of key in the vector
    auto last = upper_bound(v.begin(), v.end(), key);  // find the last occurrence of key in the vector
    cout << distance(first, last);                     // calculate the distance between the first and last occurrences of key in the vector, which gives the count of key

    return 0;
}

/*

In the main() function, the user is prompted to enter the size of the array (i.e., the number of elements in the vector) and the elements of the vector. Then, the user is prompted to enter the key (i.e., the element whose count is to be found).

The lower_bound() and upper_bound() functions from the <algorithm> library are used to find the first and last occurrences of the key in the vector, respectively. The distance() function is then used to calculate the distance between these iterators, which gives the count of the key in the vector.

Finally, the count of the key is printed to the console.
*/