///*
//#include <bits/stdc++.h>
//using namespace std;
//
///*��ʵ���ǹ���һ��������һ�������������Ĵ�������һ��������ϵ�ĵط�
// 1. �ص��������������m[i][j]- i~j ��Ҫ����Ĵ�����s[i][j]�������i~j����Ѷϵ�λ��
// 2. i~j �Ĳ�ֵ ��ʾ�м���������ˣ� ����Ϊ���������Ϊn����
// 3. ��������Ϳ�����һ��ѭ�����Ӿ�����Ϊ2��ʼ��ÿһ�ζ���������ٵļ�������Ͷϵ�λ��
//*/
//
//const int n = 7;
//
//void MatrixChain(int *p, int m[n][n], int s[n][n])
//{
//    /*��ʼ���������*/
//    for(int i = 1; i<=n; i++) m[i][i] = 0;
//    for(int r = 2; r<=n; r++)
//    {
//        for(int i = 1; i<=n-r+1; r++) // �ñ�ʾ�ǵڼ��������Ӿ���
//        {
//            /*�ҵ�ÿһ�������Ӿ������β*/
//            int j = i+r-1;
//            /*��ʼ���ָ��ͼ������A[i][j] = A[i]*(A[i+1][j])*/
//            m[i][j] = 0x7ffff;
//            // ��ʼ�����ŵĶϵ�
//            /*Ȼ��ö���Ӿ����е�ÿһ���ָ�㣬ֱ���ҵ��Ǹ����ŵ�*/
//            for(int k = i; k<j; k++)
//            {
//                /*�ָ�Ϊa[i][k] + a[k+1][j]*/
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
//pΪ��������p[0],p[1]�����һ�������������������p[1],p[2]����ڶ������������������......lengthΪp�ĳ���
//�����������������length=7��mΪ�洢���Ž���Ķ�ά����sΪ�洢ѡ�����Ž��·�ߵ�
//��ά����
void MatrixChainOrder(int *p,int m[N][N],int s[N][N],int length)
{
    int n=length-1;
    int l,i,j,k,q=0;
    //m[i][i]ֻ��һ������������˴���Ϊ0����m[i][i]=0;
    for(i=1;i<length;i++)
    {
        m[i][i]=0;
    }
    //l��ʾ�������ĳ���
    // l=2ʱ������ m[i,i+1],i=1,2,...,n-1 (����l=2��������С����)
    for(l=2;l<=n;l++)
    {
        for(i=1;i<=n-l+1;i++)
        {
            j=i+l-1; //��iΪ��ʼλ�ã�jΪ����Ϊl������ĩλ��
            m[i][j]=0x7ffff;
            //k��i��j-1,��kΪλ�û���
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
