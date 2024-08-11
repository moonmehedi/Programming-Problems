#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        unordered_map<int, int> mp;
        int max_frequency = INT_MIN;
        int max_ele;

        for (auto ele : nums)
        {
            mp[ele]++;
            if (mp[ele] > max_frequency){
                max_frequency = mp[ele];
                max_ele=ele;

            }
        }

        return max_ele;
    }
};

int main()
{

    Solution s;
    vector<int> v{1, 2, 5, 4,4,4,4,5,3,2,2,2,2};
    cout << s.majorityElement(v);
}