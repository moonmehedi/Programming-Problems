#include <bits/stdc++.h>
using namespace std;
/*DESTRUCTOR*/
/*
//destructor never takes an argument nor does it returns any value
//it is automaticly called by the compiler to clean up space
//
*/
class num
{
    static int count;

public:
    num()
    {
        count++;
        cout << "this is the time when constructor is called for object number" << count << endl;
    }
    ~num()
    {
        cout << "this is the time when my destructor ia called for object number " << count << endl;
        count--;
    }
};
int num::count = 0;
int main()
{
    cout << "entering the main block" << endl;
    cout << "creating first object n1" << endl;
    num n1;
    {
        cout << "we are inside the 2nd block" << endl;
        cout << "creating two more object" << endl;
        num n2, n3;
        cout << "exiting the 2nd block" << endl;
    }
    cout << "exiting main block" << endl;
    return 0;
}