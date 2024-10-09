#include<stdio.h>
int fac(int p){
    int sum=1;
    for(int i=1;i<=p;i++){
        sum=sum*i;
    }
    return sum;
}
int main(){
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int p=0;
        for(int j=1;j<=n;j++){
            if(j<n-i){
                printf(" ");
            }
            else
            {
                printf("%d ",(fac(i)/(fac(p)*fac(i-p))));
                p++;
            }
        }printf("\n");
    }
}