#include <bits/stdc++.h>
using namespace std;
class bank
{
    string name;
    int principal;
    int year;
    float intrest;

public:
    bank(){};
    bank(string s,int p,int y, float R);
    bank(string s,int p,int y, int r);
    void show()
    {
        cout << "intrest rate and principal amount. "
             << "intrest rate: " << intrest << "principal amount after "
             << year << " years " << principal << endl;
    }
};
bank::bank(string s, int p, int y, float R)
{ 
    cout<<"calling for bd2 "<<endl;
    name = s;
    principal = p;
    year = y;
    intrest = R;
    for (int i = 1; i <= year; i++)
        principal = principal + principal * R ;
}
bank::bank(string s, int p, int y, int r)
{
    cout<<"calling for bd1"<<endl;
    name = s;
    principal = p;
    year = y;
    intrest = r;
    for (int i = 1; i <= year; i++)
        principal = principal + principal * (float(r) / 100) ;
}

int main()
{
    bank bd1,bd2;
    int a, b, c;
    float f;
    string s;
    /*input for int*/
    cin >> s >> a >> b >> c;
    /*this is how you call a dynamic constructor*/
    bd1=bank(s, a, b, c);
    bd1.show();
    /*input for float*/
    cin >> s >> a >> b >> f;
    bd2=bank(s, a, b, f);
    bd2.show();

    return 0;
}