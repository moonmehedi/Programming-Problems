#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        vector<bool> b;
        int flag = false;
        for (int i = 0, j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            if (v.size() == 0)
            {
                v.push_back(a);
                b.push_back(true);
                i++;
               // cout << "1" << endl;
            }
            else if (v[i - 1] <= a and flag == false)
            {
                v.push_back(a);
                b.push_back(true);
                i++;
               // cout << "2" << endl;
            }
            else if (a <= v[0] and flag == false)
            {
                v.push_back(a);
                b.push_back(true);
                i++;
                flag = true;
               // cout << "3" << endl;
            }
            else if (a <= v[0] and v[i - 1] <= a)
            {
                v.push_back(a);
                b.push_back(true);
                i++;
                // flag=true;
               // cout << "3" << endl;
            }
            else
            {
                b.push_back(false);
              //  cout << "4" << endl;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << b[i];
        }
        cout << endl;
    }
}