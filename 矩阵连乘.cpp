///*
//#include <bits/stdc++.h>
//using namespace std;
//
///*其实就是构建一个两个表，一个表用来存计算的次数，另一个用来存断点的地方
// 1. 重点就是这两个矩阵，m[i][j]- i~j 需要计算的次数，s[i][j]用来存放i~j的最佳断点位置
// 2. i~j 的差值 表示有几个矩阵相乘， 最少为两个，最多为n个，
// 3. 所以这里就可以有一个循环，从矩阵数为2开始，每一次都计算出最少的计算次数和断点位置
//*/
//
//const int n = 7;
//
//void MatrixChain(int *p, int m[n][n], int s[n][n])
//{
//    /*初始化这个矩阵*/
//    for(int i = 1; i<=n; i++) m[i][i] = 0;
//    for(int r = 2; r<=n; r++)
//    {
//        for(int i = 1; i<=n-r+1; r++) // 用表示是第几个连乘子矩阵
//        {
//            /*找到每一个连乘子矩阵的首尾*/
//            int j = i+r-1;
//            /*初始化分割点和计算次数A[i][j] = A[i]*(A[i+1][j])*/
//            m[i][j] = 0x7ffff;
//            // 初始化最优的断点
//            /*然后枚举子矩阵中的每一个分割点，直到找到那个最优的*/
//            for(int k = i; k<j; k++)
//            {
//                /*分割为a[i][k] + a[k+1][j]*/
//                int t = m[i][k] + m[k+1][j] + p[i-1]*p[i]*p[j];
//                if( t < m[i][j])
//                {
//                    m[i][j] = t;
//                    s[i][j] = k;
//                }
//            }
//        }
//    }
//        cout << m[1][n-1] << endl;
//
//}
//
//void transtack(int s[n][n], int i, int j)
//{
//    if(i == j)
//        cout << "A" << i;
//    else
//    {
//        cout << "(";
//        transtack(s, i, s[i][j]);
//        transtack(s, s[i][j]+1, j);
//         cout << ")";
//    }
//}
//
//
//int main()
//{
//    int p[n]={30,35,15,5,10,20,25};
//    int m[n][n],s[n][n];
//    MatrixChain(p,m,s);
//    transtack(s,1,n-1);
//    //cout << m[1][n-1] << endl;
//    return 0;
//}
//
//*/
//



#include<iostream>
using namespace std;

const int N=7;
//p为矩阵链，p[0],p[1]代表第一个矩阵的行数和列数，p[1],p[2]代表第二个矩阵的行数和列数......length为p的长度
//所以如果有六个矩阵，length=7，m为存储最优结果的二维矩阵，s为存储选择最优结果路线的
//二维矩阵
void MatrixChainOrder(int *p,int m[N][N],int s[N][N],int length)
{
    int n=length-1;
    int l,i,j,k,q=0;
    //m[i][i]只有一个矩阵，所以相乘次数为0，即m[i][i]=0;
    for(i=1;i<length;i++)
    {
        m[i][i]=0;
    }
    //l表示矩阵链的长度
    // l=2时，计算 m[i,i+1],i=1,2,...,n-1 (长度l=2的链的最小代价)
    for(l=2;l<=n;l++)
    {
        for(i=1;i<=n-l+1;i++)
        {
            j=i+l-1; //以i为起始位置，j为长度为l的链的末位，
            m[i][j]=0x7ffff;
            //k从i到j-1,以k为位置划分
            for(k=i;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    cout << m[1][N-1] << endl;
}
void PrintAnswer(int s[N][N],int i,int j)
{
    if(i==j)
    {
        cout<<"A"<<i;
    }
    else
    {
        cout<<"(";
        PrintAnswer(s,i,s[i][j]);
        PrintAnswer(s,s[i][j]+1,j);
        cout<<")";
    }
}
int main()
{
    int p[N]={30,35,15,5,10,20,25};
    int m[N][N],s[N][N];
    MatrixChainOrder(p,m,s,N);
    PrintAnswer(s,1,N-1);
    return 0;
}


void MatrixChainOrder(int i, int j)
{
    if(i == j) return 0;
    else
    {
        int u = 0xffff;
        for(int k = i+1; k<j; k++)
        {
            int t = MatrixChainOrder(i,k)+MatrixChainOrder(k+1,j)+p[i-1]*p[k]*p[j];
            if(t<u)
            {
                s[i][j] = k;
                m[i][j] = t;
            }
        }
    }
}
