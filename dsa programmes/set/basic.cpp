#include <bits/stdc++.h>
using namespace std;

int main()
{
    // fast_io(); // enable faster I/O

    // set is implemented like a balanced BST in c++
    // so the properties of BST can be noticed in sets

    set<int, greater<int>> s; // custome comparator this will allow elements to store in reverse order
    s.insert(1);
    s.insert(3);
    s.insert(7);
    s.insert(2);
    for (auto i : s) // auto type iterator
    {
        cout << i << " ";
    }
    cout << endl
         << "union: ";

    // basic operations of set
    // union of set;

    set<int> s1{1, 9, 9, 3, 4}; // here 9 will not be inserted because only unique elements are allowed
    set<int> s2{7, 6, 5, 4};
    set<int> result_set;
    set_union(s1.begin(), s1.end(),
              s2.begin(), s2.end(),
              inserter(result_set, result_set.end()));

    for (auto &i : result_set) // in result set data will be stored in a sorted order
    {
        cout << i << " ";
    }
    cout << endl
         << "intersection: ";

    // intersec of set
    result_set.clear(); // else provide error;

    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(result_set, result_set.end()));

    for (auto &i : result_set) // in result set data will be stored in a sorted order
    {
        cout << i << " ";
    }

    // set operations can also be done on vectors
    cout << endl
         << "vector union: ";
    vector<int> v1 = {1, 2, 9, 8};
    vector<int> v2 = {6, 5, 4, 3};
    vector<int> result_v;
    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(result_v));

    for (auto i : result_v)
    {
        cout << i << " ";
    }
    return 0;
}