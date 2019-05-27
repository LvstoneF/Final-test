
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3;
    int **a;
    a = (int**)malloc(sizeof(int*)*n);
    for(int i = 0; i<n; i++)
        a[i] = (int*)malloc(sizeof(int)*n);
    for(int i= 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            cin >> a[i][j];
    }
    for(int i= 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

}
