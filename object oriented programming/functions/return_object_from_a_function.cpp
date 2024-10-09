#include<bits/stdc++.h>
using namespace std;
class student{
    public:
    string name;
    string roll;
    string department;
    student(){};
    student(string s,string r,string d ){
        name=s;
        roll=r;
        department=d;
    }
    void get_data();
};
void student::get_data(){
    cout<<name<<endl;
    cout<<roll<<endl;
    cout<<department<<endl;
}
student match(student &o1,student &o2){
    student c;
    c.name=o1.name+o2.name;
    c.roll=o1.roll+o2.roll;
    c.department=o1.department+o2.department;
    return c;
    
}

int main(){
    student a("mehedi hasan","2022","cse"),b(" moon","14048","cse"),d;
    d=match(a,b);
    d.get_data();
}