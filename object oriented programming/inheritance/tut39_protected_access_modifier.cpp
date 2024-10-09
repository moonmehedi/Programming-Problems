#include <bits/stdc++.h>
using namespace std;
class base
{
    /*protected data can be inherited but can not be accessed by 3rd party functions*/
protected:
    int a = 10;
    int b = 11;
};
class derived : public base // thoush it's public declearation private data will be inherited privately
{
public:
    int c;
    void set_data()
    {
        c = a + b;
    }
};

int main()
{
    derived a;
    a.set_data();
    cout << a.c;
    //   cout<<a.b;
    base m;
    //  cout<<m.a; produces as its protected

    return 0;
}