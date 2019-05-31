//
//#include <bits/stdc++.h>
//using namespace std;
//int bestw = 0xffff;
//int cw = 0;
//int cc = 0;
//int *x;
//int m;
//int n;
//int d;
//int **w;
//int **c;
//
//void BackTrack(int t)
//{
//    if(t>n)
//    {
//        bestw = cw;
//        cout << bestw << endl;
//        for(int i = 0; i<n; i++)
//            cout << x[i] << " ";
//        cout << endl;
//
//    }
//    else
//    {
//        for(int j = 1; j<=m; j++)
//        {
//           if(cw+w[t][j] < bestw && cc+c[t][j] <= d)
//            {
//                x[t] = j;
//                cw += w[t][j];
//                cc += c[t][j];
//                BackTrack(t+1);
//                cw -= w[t][j];
//                cc -= c[t][j];
//            }
//        }
//    }
//}
//
//int main()
//{
//    //int n,m;
//    cout << "输入部件数(n)和供应商数(m)：" << endl;
//    cin >> n >> m;
//    //int d;
//    cout << "输入限定价格(d)： " << endl;
//    cin >> d;
//    //int **c;
//    //int **w;
//
//    //x[n] = {0};
//    cout << "输入花费：" << endl;
//    c = (int**)malloc(sizeof(int)*n);
//    for(int i = 0; i<n; i++)
//        c[i] = (int*)malloc(sizeof(int)*m);
//    for(int i = 0; i<n; i++)
//    {
//        for(int j = 0; j<m; j++)
//            cin >> c[i][j];
//        cout << endl;
//    }
//
//    cout << "输入重量：" <<endl;
//    w = (int**)malloc(sizeof(int)*n);
//    for(int i = 0; i<n; i++)
//        w[i] = (int*)malloc(sizeof(int)*m);
//    for(int i = 0; i<n; i++)
//    {
//        for(int j = 0; j<m; j++)
//            cin >> w[i][j] ;
//    }
//
//    BackTrack(1);
//
//
//}



#include<iostream>
#include<stdio.h>
using namespace std;
int w[100][100];//w[i][j]为第i个零件在第j个供应商的重量
int c[100][100];//c[i][j]为第i个零件在第j个供应商的价格
int bestx[100];//bestx[i]表示一次搜索到底后的最优解，用来存放第i个零件的供应商，
int x[100];//x[i]临时存放第i个零件的供应商
int cw=0,cc=0,bestw=0xffff;
int cost;//限定价格
int n;//部件数
int m;//供应商数
void Backtrack(int t)
{
    int j;
    if(t>n)//搜索到叶子结点，一个搜索结束，所有零件已经找完
    {
        bestw=cw;//当前最小重量
        cout<<"每个部件的供应商："<<endl;
        for(j=1;j<=n;j++)
           cout << x[j] << " " ;
           cout << endl;
    }
    else
    {
        for(j=1;j<=m;j++)
        {
            if(cc+c[t][j]<=cost && cw+w[t][j]<bestw)
            {
                x[t]=j;
                cc+=c[t][j];
                cw+=w[t][j];
                Backtrack(t+1);
                cc-=c[t][j];
                cw-=w[t][j];
            }
        }
    }
}

int main()
{
    int i,j;
    cout<<"请输入部件数："<<endl;
    cin>>n;
    cout<<"请输入供应商数："<<endl;
    cin>>m;
    cout<<"请输入限定价格："<<endl;
    cin>>cost;
    cout<<"请输入各部件的在不同供应商的重量："<<endl;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            cin>>w[i][j];
    cout<<"请输入各部件的在不同供应商的价格："<<endl;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            cin>>c[i][j];
    Backtrack(1);
//    for(i=1;i<=n;i++)
//        cout<<bestx[i]<<' ';
//    cout<<endl;
    cout<<bestw;
    return 0;
}

