#include<bits/stdc++.h>
using namespace std;
/*this is the base class*/
class student{
    public:
    string name;
    int roll;
    void set_data(string n,int r){
        name=n;
        roll=r;
    }
    void get_data(){
        
        cout<<name<<endl;
        cout<<roll<<endl;
    }
};
/*declearing student as virtual base class as it may get derived more than one time
writing vitual before the class will help the compiler to resolve ambiguity releated error 
*/
class marks:virtual public student{
    public:
    int math;
    int physics;
    void set_marks(int m1,int m2){
        //cout<<"enter marks in math and physics "<<endl;
        math=m1;
        physics=m2;
    }
    void print_marks(){
        cout<<"your marks are "<<endl;
        cout<<"your marks in math :"<<math<<endl;
        cout<<"marks in physics :"<<physics<<endl;
    }
};
/*
here student is a virtual base class to avoid ambiguity

*/
class sprots:virtual public student{
    public:
    int score;
    void set_score(int a){
        score=a;
    }
    void get_score(){
        cout<<"your score : "<<score<<endl;
    }

};
class result:public marks,public sprots{
    public:
    int total;
    void display(){
        cout<<"your marks and info :"<<endl;
        print_marks();
        get_score();
        total=math+physics+score;
        cout<<"your total result :"<<total<<endl;
    }
};

int main(){
    result moon;
    moon.set_data("moon",202214048);
    moon.set_marks(99,96);
    moon.set_score(10);
    moon.display();
    

return 0;}