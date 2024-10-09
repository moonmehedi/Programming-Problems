#include<bits/stdc++.h>
using namespace std;
int main(){
    //DECLEARING AND INITIALIZING VECTORS (MOON)
    //VECTOR MEHEDI WILL STORE 7 ELEMENTS SIZE IS "7",,AND THEY ARE 5
vector<int>moon,mehedi(7,5);

/*you cannot input vector like v[i]=2 because it has no memory decleared you can use push back for input*/
moon.push_back(1);
moon.push_back(2);
moon.push_back(3);
moon.push_back(4);
moon.push_back(5);
moon.push_back(6);
moon.push_back(7);
//PRINTING VECTORS ELEMENT USING LOOP
for(int i=0;i<moon.size();i++)
{
    cout<<moon[i];
}cout<<endl;
//DECLEARING AN ITERATOR
vector<int>::iterator it;
//ITERATING VECTORS ELEMENT
for(it=moon.begin();it<moon.end();it++)
{
    cout<<*it;
}cout<<endl;

//PRINTING VECTOR ELEMENT USING AUTO
for(auto element:moon){
    cout<<element;
}cout<<endl;

//DON'T TAKES ANY ARGUMENT SIMPLELY REASES THE LAST ELEMENT
moon.pop_back();


//PRINTS ELEMENT OF VECTOR MEHEDI
cout<<"PRINT MEHEDI"<<endl;
for(auto element:mehedi){
    cout<<element;
}cout<<endl;

//SWAPPING VECTOR 
cout<<"SWAP"<<endl;
swap(moon,mehedi);
cout<<"VALUE OF MEHEDI"<<endl;
//PRINTING MEHEDI
for(auto element:mehedi){
    cout<<element;
}cout<<endl;
cout<<"VALUE OF MOON"<<endl;
//PRINTING MOON
for(auto element:moon){
    cout<<element;
}cout<<endl;
//SORTS ARRAY FROM LARGE TO SMALL DECENDING ORDER;
sort(mehedi.begin(),mehedi.end(),greater<int>());
for(auto element:mehedi){
    cout<<element;
}cout<<endl;
}