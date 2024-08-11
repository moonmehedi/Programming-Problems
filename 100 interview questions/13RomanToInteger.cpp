#include <bits/stdc++.h>
using namespace std;

string convertString(char a)
{
    return string(1, a);
}

int main()
{
    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (mp[s[i]] < mp[s[i + 1]])
        {
            sum += (mp[s[i + 1]] - mp[s[i]]);
            i++;
            continue;
        }
        sum += mp[s[i]];
    }
    cout << sum << endl;
    return sum;
}