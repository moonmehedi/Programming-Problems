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
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_front(4);
    cout << "emlements " << endl;
    for (auto i : dq)
        cout << i << endl;
    
    cout<<"element of "<<endl;
    cout<<"front "<<dq.front()<<endl;
    cout<<"back "<<dq.back()<<endl;

    cout<<"after poping front and back elements "<<endl;

    dq.pop_front();
    dq.pop_back();

    for(auto ele: dq)
    cout<<ele<<endl;

    return 0;
}