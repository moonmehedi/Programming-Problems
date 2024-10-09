#include<stdio.h>
#include<string.h>
//char a[100],b[100];
int main(){
    int sizea,sizeb,carry=0,result[100],t,temp;
    char a[100],b[100];
    gets(a);
    gets(b);
    sizea=strlen(a);
    sizeb=strlen(b);
    t=sizea;
    result[sizea]='\0';
    printf("%d %d",sizea,sizeb);
    while(sizea>0||sizeb>]0)
    {
   temp=(a[sizea-1]-48)+(b[sizeb-1]-48);
   result[sizea-1]=temp%10+carry;
   carry=temp/10;
   sizea--;
   sizeb--;
    }
    result[sizea-1]=temp%10+carry;
    
    for(int i=0;result[i]!=t;i++){
        printf("%d",result[i]);
    }
    

}