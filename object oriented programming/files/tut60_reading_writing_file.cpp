#include<bits/stdc++.h>
#include<fstream>
using namespace std;


/*the usefull classes for working with files in c++ are
1/fstreambasae
2/ifstream -->derived from fstreambase
3/ofstream -->derived from fstreambase
*/


// in order work with files in c++, you will have to open it.primarily, there are two ways to open a file:
// 1/using the constructor
// 2/using the member function open() of the class



int main(){
string write="this is writing on file \n";

//write from file
ofstream out("tut60writefile.txt");//means out not in terminal but in this file
out<<write;//here we have to write using this object

ifstream in("tut60read.txt");
string read;
in>>read;//here we have to read using this object
cout<<read<<endl;//string will not print after spacce :solved using getline()
getline(in,read);//using getline inputting full null
cout<<read<<endl;

}