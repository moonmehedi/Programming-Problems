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
    int n;
    cout << "enter size of the array" << endl;
    cin >> n;
    vector<int> arr(n); // create a vector of size n to store array elements
    cout << "enter elements " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // input array elements
    }
    int key;
    cout << "enter the key " << endl;
    cin >> key;
    /*
    this funcitons take pointers and lower bound returns the iterator or pointer
    to the address that is slightly less than the key and the upper bound
    retunrs the iterator that is slighty greater than the key

    NOTE:they don't reutnr the address to the first and last occurance
    */

    // input key to search
    auto first = lower_bound(arr.begin(), arr.end(), key); // find the lower bound of the key in the array
    auto last = upper_bound(arr.begin(), arr.end(), key);  // find the upper bound of the key in the array
    if (first == arr.end() || *first != key)               // if the key is not found in the array, print "key not found" and return 0
    {
        cout << "key not found " << endl;
        return 0;
    }
    cout << distance(arr.begin(), first) << endl;      // print the index of the first occurrence of the key in the array
    cout << distance(arr.begin(), prev(last)) << endl; // print the index of the last occurrence of the key in the array
    return 0;                                          // exit the program
}

/*


*/