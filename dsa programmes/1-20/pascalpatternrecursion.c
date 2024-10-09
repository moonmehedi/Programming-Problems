#include<stdio.h>
int fac(int n){
    if(n==0) return 1;
    return n*fac(n-1);

}
int printfac(int i,int k){
if(k>i) return 0;
printf("%d ",(fac(i)/(fac(k)*fac(i-k))));
k++;
return printfac(i,k);
}
int pattern(int n,int i,int j){
    if(i==n&&j==0)
        return 0;
    else{    
        if(j<(n-1-i))
        {printf(" ");j++;
        }
        else if(j>=(n-1-i))
        {
           printfac(i,0);
           i++;
           j=0;
           printf("\n");
        }
       }
        return pattern(n,i,j);
}
int main(){
    int n=5;
    pattern(n,0,0);
}