#include<bits/stdc++.h>
using namespace std;
int m,n,k;
//SEARCHES MATRIX INDEX
int search(int arr[][]);
void multiplication(){
    int row1,coloum1,row2,coloum2;
    cin>>row1>>coloum1>>row2>>coloum2;
int mat1[row1][coloum1],mat2[row2][coloum2],mat[row1][coloum2]={0};
    for(int i=0;i<row1;i++)
    for(int j=0;j<coloum1;j++){
        cin>>mat1[i][j];
    }
    for(int i=0;i<row2;i++)
    for(int j=0;j<coloum2;j++){
        cin>>mat2[i][j];
    }
    if(coloum1!=row2){
        cout<<"NO";return ;
    }
    for(int i=0;i<row1;i++){
        for(int j=0;j<coloum2;j++){
            for(int k=0;k<row2;k++){
                mat[i][j]+=mat1[i][k]*mat2[k][j];
             }

        }
    }
    //output matrix
    for(int i=0;i<row1;i++)
    for(int j=0;j<coloum2;j++)
    cout<<mat[i][j]<<" ";
    cout<<endl;
}

int main(){
    cin>>n>>m>>k;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    //PRINTS TRANSPOSE MATRIX
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        cout<<arr[i][j];
        cout<<endl;
    }
    multiplication();
    search(arr);
}
int search(int arr[][]){
    int row=0,coloum=m-1;
    while(row<n&&coloum>=0)
    {
        if(arr[row][coloum]==k)
        cout<<k<<endl;
        if(arr[row][coloum]<k)
        row++;
        if(arr[row][coloum]>k)
        coloum--;
    }
}