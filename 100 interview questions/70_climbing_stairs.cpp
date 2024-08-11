#include <iostream>
#include <vector>
using namespace std;

int arr[10000000];
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1 || n == 0)
        {
            return 1;
        }

        if (arr[n] != 0) // Check if the result is already memoized
        {
            return arr[n];
        }

        return arr[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};

int main()
{
    Solution s;
    cout << s.climbStairs(5) << endl;
    return 0;
}
