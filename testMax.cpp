
#include <bits/stdc++.h>
using namespace std;
int **a;
int **ab;
int main()
{
    int n = 3;

    a = (int**)malloc(sizeof(int*)*n);
    for(int i = 0; i<n; i++)
        a[i] = (int*)malloc(sizeof(int)*n);
    for(int i= 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            cin >> a[i][j];
    }

    ab = (int**)malloc(sizeof(int*)*n);
    for(int i = 0; i<n; i++)
        ab[i] = (int*)malloc(sizeof(int)*n);
    for(int i= 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            cin >> ab[i][j];
    }

    for(int i= 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

     for(int i= 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            cout << ab[i][j] << " ";
        cout << endl;
    }

}
