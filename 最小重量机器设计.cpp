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
//    cout << "���벿����(n)�͹�Ӧ����(m)��" << endl;
//    cin >> n >> m;
//    //int d;
//    cout << "�����޶��۸�(d)�� " << endl;
//    cin >> d;
//    //int **c;
//    //int **w;
//
//    //x[n] = {0};
//    cout << "���뻨�ѣ�" << endl;
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
//    cout << "����������" <<endl;
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
int w[100][100];//w[i][j]Ϊ��i������ڵ�j����Ӧ�̵�����
int c[100][100];//c[i][j]Ϊ��i������ڵ�j����Ӧ�̵ļ۸�
int bestx[100];//bestx[i]��ʾһ���������׺�����Ž⣬������ŵ�i������Ĺ�Ӧ�̣�
int x[100];//x[i]��ʱ��ŵ�i������Ĺ�Ӧ��
int cw=0,cc=0,bestw=0xffff;
int cost;//�޶��۸�
int n;//������
int m;//��Ӧ����
void Backtrack(int t)
{
    int j;
    if(t>n)//������Ҷ�ӽ�㣬һ��������������������Ѿ�����
    {
        bestw=cw;//��ǰ��С����
        cout<<"ÿ�������Ĺ�Ӧ�̣�"<<endl;
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
    cout<<"�����벿������"<<endl;
    cin>>n;
    cout<<"�����빩Ӧ������"<<endl;
    cin>>m;
    cout<<"�������޶��۸�"<<endl;
    cin>>cost;
    cout<<"��������������ڲ�ͬ��Ӧ�̵�������"<<endl;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            cin>>w[i][j];
    cout<<"��������������ڲ�ͬ��Ӧ�̵ļ۸�"<<endl;
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

