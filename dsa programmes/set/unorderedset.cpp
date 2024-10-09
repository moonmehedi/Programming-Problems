#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_set<int> us;
    us.insert(7);
    us.insert(2);
    us.insert(3);
    us.insert(2);
    us.insert(2);
    us.insert(10);

    cout<<"unorder set :";

    for (auto i : us)
    {
        cout << i << " ";
    }

    us.erase(us.find(7));

    cout<<endl<<"after erasing 7 from the set :";

     for (auto i : us)
    {
        cout << i << " ";
    }

    cout<<endl<<"erasing the occurances of 2 :";

    us.erase(2);

     for (auto i : us)
    {
        cout << i << " ";
    }
}