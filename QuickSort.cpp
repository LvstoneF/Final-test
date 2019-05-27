
#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;

}

int partition(int a[], int left, int right)
{
    int i = left;
    int j = right;
    int temp = a[left];
    while(true){
        while(a[++i] < temp);
        while(a[--j] > temp);
        if(i>=j) break;
        swap(a[i], a[j]);
    }
    a[left] = a[j];
    a[j] = temp;
    return i;
}

void quickSort(int a[], int left, int right)
{
    int dp;
    if(left < right)
    {
        dp = partition(a, left, right);
        quickSort(a, left, dp-1);
        quickSort(a, dp+1, right);
    }
}

int main()
{
int a[9]={8,2,6,12,1,9,5,5,10};
int i;
quickSort(a,0,8);/*排好序的结果*/
for(i=0;i<8;i++)
printf("%4d",a[i]);
getchar();
return 0;
}
