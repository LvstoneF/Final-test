
#include <bits/stdc++.h>
using namespace std;
int bestw = 0xffff;
int cw = 0;
int cc = 0;
int *x;
int m;
int n;
int d;
int **w;
int **c;

void BackTrack(int t)
{
    if(t>n)
    {
        bestw = cw;
        cout << bestw << endl;
        for(int i = 0; i<n; i++)
            cout << x[i] << " ";
        cout << endl;

    }
    else
    {
        for(int j = 1; j<=m; j++)
        {
           if(cw+w[t][j] < bestw && cc+c[t][j] <= d)
            {
                x[t] = j;
                cw += w[t][j];
                cc += c[t][j];
                BackTrack(t+1);
                cw -= w[t][j];
                cc -= c[t][j];
            }
        }
    }
}

int main()
{
    //int n,m;
    cout << "输入部件数(n)和供应商数(m)：" << endl;
    cin >> n >> m;
    //int d;
    cout << "输入限定价格(d)： " << endl;
    cin >> d;
    //int **c;
    //int **w;

    //x[n] = {0};
    cout << "输入花费：" << endl;
    c = (int**)malloc(sizeof(int)*n);
    for(int i = 0; i<n; i++)
        c[i] = (int*)malloc(sizeof(int)*m);
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
            cin >> c[i][j];
        cout << endl;
    }

    cout << "输入重量：" <<endl;
    w = (int**)malloc(sizeof(int)*n);
    for(int i = 0; i<n; i++)
        w[i] = (int*)malloc(sizeof(int)*m);
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
            cin >> w[i][j] ;
    }

    BackTrack(1);


}
