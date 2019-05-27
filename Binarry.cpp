#include <bits/stdc++/h>
using namespace std;
/*�ǵݹ黯*/
int BinarySearch(int arr[], int e, int p, int r)
{
    while(p<=r)
    {
        int mid = (p+r)/2;
        if(arr[mid] == e) return mid;
        if(arr[mid] > e) { r = m-1}
        else
            p = m+1;
    }

    return -1;
}


/*�ݹ黯*/
int BinarySearch(int arr[], int e, int p, int r)
{
    int mid = (p+r)/2;
    if(arr[mid] == e) return mid;
    if(arr[mid] > e) {BinarySearch(arr, e, p, mid-1); }
    else
        BinarySearch(arr, e, mid+1, r);
}
