#include<bits/stdc++.h>
using namespace std;

void crash(int *i){
    
    cout<<*i<<endl;

}

int* cb(int *j){
    *j=*j+3;
    return j;
}
int *ab(int *j){
    return NULL;
}
void f(int *i){
    int *j=i;
    j=cb(j);
    j=ab(j);
    crash(j);
}


int main(){
    int i=2;
    f(&i);  
}