#include<bits/stdc++.h>
using namespace std;
//passing by reference not copying time complexity o(1)
void print(vector<int>&v){
for(auto element:v)
cout<<element;
cout<<endl;
}
int main(){
                                                    /*COPYONG IN VECTORS IS AN EXPENSIVE OPERATION SO NEVER COPY ELEMENTS IN VECTORS
                                                                        IF IT IS NOT NECESSARY
                                                                         */

    vector <int> moon{1,2,3,4,5,6},mehedi;
    //as copying it will take time complexity o(n)
    mehedi=moon;
    print(mehedi);

}