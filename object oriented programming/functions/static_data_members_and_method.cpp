#include <bits/stdc++.h>
using namespace std;
class student_cse
{
    // if we want to store the count of student we should made count static
    // static int should declear outside
    /*if we dont make count static
    1.we have to initial it with zero
    2.every object will have its saparate count*/
    static int count;

public:
    int NO;
    string name;
    int roll;
    void set_data();
    void get_data();
};
/*this declearation means
1.count is associated with class not with objects
2.count will take memeory one time
*/
int student_cse::count;

void student_cse::set_data()
{
    cout << "enter student name and roll " << endl;
    cin >> name;
    cin >> roll;
    NO = count++;
}
void student_cse::get_data()
{
    cout << "student NO " << NO << endl;
    cout << "this is '" << name << "' roll: " << roll << endl;
}
int main()
{
    int n;
    cout << "number of student " << endl;
    cin >> n;
    student_cse a[n];
    for (int i = 0; i < n; i++)
    {
        a[i].set_data();
    }
    for (int i = 0; i < n; i++)
    {
        a[i].get_data();
    }
}