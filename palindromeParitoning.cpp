#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    void rec(vector<string>v,string s ,int p,int start,int stop){

        if(p==0){
            v.push_back(s.substr(start, s.length()));
            return;
        }
        if(stop>=s.length()){
            return;
        }

        rec(v, s, p,  start, stop+1);
        v.push_back(s.substr(start, stop));
        rec(v, s, p-1,  stop, stop+1);
    }

    vector<vector<string>> partition(string s)
    {

        for (int partition_number = 1; partition_number < s.length();partition_number++){

            rec({},s,partition_number, 0, 0);
        }
    }
};

int main()
{

    Solution s;
    s.partition("1234")
}
