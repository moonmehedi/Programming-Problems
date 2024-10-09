#include<bits/stdc++.h>
using namespace std;
bool is_safe(int **arr,int x,int y,int n)
{
    return(x<n&&y<n&&arr[x][y]!=0);
}
bool rat_in_maze(int **arr,int x,int y,int n,int **solarr){
    if(x==n-1&&y==n-1&&arr[x][y]!=0){
        solarr[x][y]=1;
        return true;
    }
    if(is_safe(arr,x,y,n)){
        solarr[x][y]=1;
        if(rat_in_maze(arr,x+1,y,n,solarr))
        return true;
        if(rat_in_maze(arr,x,y+1,n,solarr))
        return true;
        solarr[x][y]=0;
        return false;
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int **arr=new int *[n];//DECLEARING 2D ARRAY AND NUMBER OF ROWS OR NUMBER OF 1D ARRAY
    for(int i=0;i<n;i++){
        arr[i]=new int[n];//DECLEARING MEMORY ALLOCATION FOR EVERY N SIZE 1D ARRAY 
    }
    /*INPUT ARRAY*/
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int **solarr=new int *[n];//DECLEARING SOLUTION ARRAY
    for(int i=0;i<n;i++){
        solarr[i]=new int [n];
        for(int j=0;j<n;j++){
            solarr[i][j]=0;
        }
    }
    if(rat_in_maze(arr,0,0,n,solarr)){
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<solarr[i][j]<<" ";
        }cout<<endl;
    }
    }

}