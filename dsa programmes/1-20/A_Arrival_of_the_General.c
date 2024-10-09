#include<stdio.h>
int main()
{
    int arr[200],sum=0,min=100,max=1,n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]<arr[min])
        min=i;//index
         if(arr[i]>arr[max])
        max=i;//index
    }
    int i=min;int j=max;
    while (1)
    {
        if(i!=n-1)
        {
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
            i++;
            sum+=1;
        }
        if(max!=0)
        {
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j++;
            sum+=1;
        }
        if(i==n-1&&j==0)
        break;
    }
    printf("%d",sum);
}