#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100];
    int i,j,flag=0;
    gets(a);
    gets(b);
    int p=strlen(a);
    for(i=0,j=p-1;a[i]!='\0';i++,j--)
    {
        if(a[i]!=b[j])
        {
            flag=1;
            break;
        }
    }
    if(flag==1) printf("NO");
    else printf("YES");
    return 0;
}