#include<bits/stdc++.h>
using namespace std;
void print_2d_array(){
    int row,coloum;
    cin>>row>>coloum;
    int a[row][coloum];
    for(int *p=&a[0][0];p<=&a[row-1][coloum-1];p++)
    cin>>*p;
    for(int *p=&a[0][0];p<=&a[row-1][coloum-1];p++){
    cout<<*p;
    if(p=&a)
}}
/*PRINTS THE SUM OF ALL ELEMENTS*/
int sum(int arr[],int size){
    int sum=0;
    for(int *p=arr;p<arr+size;p++){
        sum=sum+*p;
    }
    printf("%d",sum);
    return 0;
}
/*PRINTS ARRAY IN REVERSE*/
int print_reverse(int arr[],int size){
    for(int *p=arr+size-1;p>=arr;p--){
        cout<<*p;
    }
    cout<<endl;
    return 0;
}
/*RETURNS POINTER FROM A FUNCTION*/
int *return_pointer(int arr[],int size){
    //this funciton returns an address
    return &arr[size/2];
}
/*FIND MAXIMUM AND MIN VALUE*/
int maxmin(int arr[],int size,int *max,int *min){
    for(int *p=arr+1;p<arr+size;p++){
        if(*max<*p)
        *max=*p;
        if(*min>*p)
        *min=*p;
    }
    return 0;
}
/*PRINTS ARRAY */
int traversing_array_using_pointer(int arr[],int size){
    for(int *q=arr;q<arr+size;q++){
        cout<<*q;
    }
    cout<<endl;
    return 0;
}
//SWAPS FUNCTION
int swap(int *p,int *q){
    int temp=*p;
    *p=*q;
    *q=temp;
    return 0;
}
int main(){
    cout<<"SWAP VALUE"<<endl;
    //SWAPS VALUE
    int a=2;
    int b=4;
    swap(&a,&b);
    cout<<a<<" "<<b<<endl;
    //ARRAY
    int size;
    cin>>size;
    int arr[size];
    //INPUTING ARRAY
    cout<<"input array"<<endl;
    for(int *p=arr;p<arr+size;p++){
        cin>>*p;//p invalid it means taking an address
    }
    traversing_array_using_pointer(arr,size);
    /*FIND MAXIMUM MINIMUM IN ARRAY*/
    int max=arr[0],min=arr[0];
    maxmin(arr,size,&max,&min);
    cout<<"maximum and minimum "<<endl;
    cout<<max<<endl<<min<<endl;
    cout<<"mid element using pointer "<<endl;
    int *o=return_pointer(arr,size);
    cout<<*o<<endl;
    //cout<<*return_pointer(arr,size);{works same }
    //prints array in reverse
    cout<<"prints array in reverse ";
    print_reverse(arr,size);
    cout<<endl;
    cout<<" SUM OF ALL ELEMENTS OF ARRAY ";
    sum( arr, size);
    cout<<endl;
    //TRAVERSE 2D ARRAY
    print_2d_array();
}