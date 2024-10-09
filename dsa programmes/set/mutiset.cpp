#include <bits/stdc++.h>
using namespace std;
int main()
{

    multiset<int> ms;
    ms.insert(9);
    ms.insert(8);
    ms.insert(5);
    ms.insert(3);
    ms.insert(3);
    ms.insert(3);
    ms.insert(1);
     cout<<"printed in sorted oreder ";
    for (auto i : ms)
    {
        cout << i << " ";
    }
    cout << endl
         << "erase first occurance of 3:";
    ms.erase(ms.find(3)); // gives first iterator of 3

    for (auto i : ms)
    {
        cout << i << " ";
    }

    cout<<endl<<"delete all occurances of 3 :";
    ms.erase(3);//delateds all occurances of 3


    for(auto i: ms){
    cout<<i<<" ";
}
}