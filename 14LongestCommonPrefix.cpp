#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    string LongestCommonPrefix(vector<string> &strs)
    {
        string lcp = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            string s1 = strs[i];
            for (int i = 0; i < min(lcp.length(), s1.length()); i++)
            {
                if (s1[i] == lcp[i])
                {
                    continue;
                }
                lcp = lcp.substr(0, i);
                if (lcp == "")
                    return "";
            }
        }
        return lcp;
    }
};

int main()
{
    solution a;
    vector<string> v{"dog", "racecar", "car"};
    cout << a.LongestCommonPrefix(v)
         << endl;
}