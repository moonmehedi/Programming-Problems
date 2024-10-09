#include <bits/stdc++.h>
using namespace std;

void merge_two_array(int arr[], int l, int mid, int r)
{

    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1];
    int b[n2]; // temp arrays

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 and j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            i++;
        }
        else
        {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);

        merge_two_array(arr, l, mid, r);
    }
}

int main()
{
    int arr[]={5,4,3,2,1};
    merge_sort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
