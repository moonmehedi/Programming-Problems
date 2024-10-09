#include<bits/stdc++.h>
using namespace std;
/*THIS CODE WILL SORT AN STRING*/
void SORT(){
    string s="gfedcba";
    sort(s.begin(),s.end());
    cout<<s<<endl;//this will print "abcdefg"
}
/*CONVERTS STIRNG TO INTEGER*/
void STOI(){
    string s="419";
    cout<<stoi(s)+1<<endl;//this converts s into string then add 1

}
/*PRINTS SUB STRING FROM A STRING*/
void SUBSTR(){
    string s="hello dear moon";
    cout<<s.substr(11,4)<<endl;//prints "moon";11 starign index 4 character number

}
/*THIS FUNCTION INSERT PARICULAR SUB STRING IN AN STRIGN AT A DECLARED POSITION*/
void INSERT(){
    string s="hello moon";
    cout<<s.insert(5," dear")<<endl;//this insert string " dear" at index 5
}
/*THIS CODE PRINTS SEARCH INDEX OF PARTICULAR SUB STRING FROM A STRING*/
void FIND(){
    string s="hello dear moon!";
    cout<<s.find("moon")<<endl;//this code prints the starting index of "moon";
    
}
/*THIS FUNCTION DELETS PARTICULAR CHARACTER FROM STRING*/
void ERASE(){
string s1="hello my error dear!";
cout<<s1.erase(9,6)<<endl;//erase "error"

}
/*COMPARING TWO STRING*/
void COMPARE(){
    string s1="ab";
    string s2="ab";
    string s3="ef";
    cout<<s1.compare(s2)<<"  equal"<<endl;
    cout<<s2.compare(s3)<<"  first string is smaller"<<endl;
    cout<<s3.compare(s1)<<"  first string is larger"<<endl;
}
/*THIS CODE CLEARS AN STRING*/
void CLEAR(){
    string s1;
    cin>>s1;
    s1.clear();
    cout<<s1;
}
/*THIS FUNCTION CONCATINATE STRING*/
void concat(){
    string s1;
    string s2;
    cout<<"print value you want to concat"<<endl;
    cin>>s1>>s2;
    s1.append(s2);
    cout<<s1<<endl;
    cout<<"s1=s1+s2 would do the same"<<endl;
}
/*INPUT STRING WITH SPACES*/
void input(){
    string str;
    getline(cin,str);
    cout<<str<<endl;
}
int main(){
    string str(5,'j'),str1;
    //str(5,"moon");illegal works for charector only
    //str1(4,'a');illigeal wont work
    cout<<str<<endl;

    /*INPUTS STRING WITH SPACES*/
    cout<<"INPUTS STRING WITH SPACES"<<endl;
    input();
    cout<<"************THIS FUNCTION CONCATINATES STRING*********"<<endl;
    concat();
    /*THIS LINE OF CODE PRINTS AN INDIVIDUAL CHARACTER FROM STIRNG*/
    cout<<"THIS LINE OF CODE PRINTS AN INDIVIDUAL CHARACTER FROM STIRNG"<<endl;
    string s3;int m;
    cin>>s3;
    cout<<"which index you want to print"<<endl;
    cin>>m;
    cout<<s3[m]<<endl;
    /*THIS CODE CLEARS AN STRING*/
    cout<<"THIS CODE CLEARS AN STRING"<<endl;
    CLEAR();
    /*STRING COMPARING*/
    cout<<"THIS CODE COMPARE STRINGS"<<endl;
    COMPARE();
    /*THIS FUNCTION DELETS PARTICULAR CHARACTER FROM STRING*/
    cout<<"THIS FUNCTION ERASE PARTICULAR CHARACTER FROM STRING"<<endl;
    ERASE();
    /*THIS CODE PRINTS INDEX OF PARTICULAR SUB STRING FROM A STRING*/
    cout<<"THIS CODE PRINTS INDEX OF PARTICULAR SUB STRING FROM A STRING"<<endl;
    FIND();
    /*THIS FUNCTION INSERT PARICULAR SUB STRING IN AN STRIGN AT A DECLARED POSITION*/
    cout<<"THIS FUNCTION INSERT PARICULAR SUB STRING IN AN STRIGN AT A DECLARED POSITION"<<endl;
    INSERT();
    /*PRINTS SUB STRING FROM A STRING*/
    cout<<"PRINTS SUB STRING FROM A STRING"<<endl;
    SUBSTR();
    /*CONVERTS STIRNG TO INTEGER*/
    cout<<"*****CONVERTS STRING TO INTEGER********"<<endl;
    STOI();
    /*THIS CODE WILL SORT AN STRING*/
    cout<<"THIS CODE WILL SORT AN STRING"<<endl;
    SORT();
}