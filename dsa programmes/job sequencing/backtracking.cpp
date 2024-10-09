#include <bits/stdc++.h>
using namespace std;

bool arr[100][100];

bool isSafe(int i, int j, int n)
{
    for (int r = 0; r < i; r++)
    {
        if (arr[r][j])
            return false;
    }
    for (int r = i, c = j; r >= 0 and c >= 0; r--, c--)
    {
        if (arr[r][c]==1)
        {
            return false;
        }
    }
    for(int r=i,c=j ; r>=0 and c<=n;r--,c++  ){
        if(arr[r][c]==1){
            return false;
        }
    }
    return true;
}

bool backtraking(int x,int n){
    if(x>=n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j];
            }cout<<endl;
        }cout<<"another"<<endl;
    }

    for(int col=0;col<n;col++){
        if(isSafe(x,col,n)){
            arr[x][col]=1;
            if(backtraking(x+1,n)){
                return true;
            }
            arr[x][col]=0;

        }
        
    }
    return false;


}

int main()
{
    int n=4;
    backtraking(0,n);
}