#include <bits/stdc++.h>
using namespace std;

void Merge(int arr[], int p, int mid, int r)
{
    int lenL = (mid - p+1);
    int lenR = (r - mid);
    int *L = new int[lenL+1];
    int *R = new int[lenR+1];
    for(int i = 0; i<lenL; i++)
        L[i] = arr[p+i];
    for(int j = 0; j<lenR; j++)
        R[j] = arr[mid+j+1];
    int i = 0, j = 0;
    L[lenL] = R[lenR] = 0xfffff;
    for(int k = p; k<=r; k++)
    {
        if(L[i] < R[j])
           {
                arr[k] = L[i];
                i++;
           }
           else
           {
               arr[k] = R[j];
               j++;
           }
    }
}

void Mergesort(int arr[], int p, int r)
{
    if(p<r)
    {
        int mid = (p+r)/2;
        Mergesort(arr, p, mid);
        Mergesort(arr, mid+1, r);
        Merge(arr, p, mid, r);
    }
}



int main()
{
    int arr[] = {4,5,6,2,2,2,6,54,3,2,56,7,567,8,9,97,567,568,79};
    int len = 19;
    Mergesort(arr,0, len-1);
    for(int i = 0; i<len; i++)
        cout << arr[i] << " ";
}
