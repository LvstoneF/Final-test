#include <bits/stdc++.h>
using namespace std;


/*1. �ڻ����㷨�У� ���ݵ�Ҷ�ӽڵ��ʱ�򣬾Ϳ��Եõ�һ����ɫ����
  2. ������ڽڵ㣬����Ҫ������ڵ���ɫ��
    1. ��ɫ����Ϊ���ȴӵ�һ����ɫ��ʼ����ÿһ����ɫ����һ�飬����ʲô��ɫ���ʺϵ�
    2. �������Ҫ�õ�Լ��������OK(t)����ǰ�ڵ�t����ɫ�Ƿ�����Լ������
    3. Լ���������ӵ�һ���ڵ�j��ʼ�������ڵ�j t �Ƿ����б������ģ�����б�����������������ɫһ�����ڵ�t�Ͳ����������ɫ���ڻ���һ����ɫ�ж�
*/

class Color {
    friend int mColoring(int, int, int**);// ʵ����
private:
    bool OK(int t);
    void BackTrack(int t);
    int n; // �ڵ㣻
    int m; // ɫ��
    int sum;
    int **a; // �ڽӾ���G(V,E);
    int *x;
};


void Color::BackTrack(int t)
{
    if(t>=n)
    {
        sum++;
        for(int i = 1; i<=n; i++)
            cout << x[i] << " ";
        cout << endl;
    }
    else
    {
        for(int j = 1; j<=m; j++)
        {
            x[t] = j;
            if(OK(t))
                BackTrack(t+1);
        }
    }
}



bool Color::OK(int t)
{
    for(int j = 1; j<=n; j++)
    {
        if(a[t][j] == 1 && x[t] == x[j])
            return false;
        return true;
    }
}


int mColoring(int n, int m, int **a)
{
    Color C;
    //��ʼ��x;
    C.n = n;
    C.m = m;
    C.a = a;
    C.sum = 0;
    int *p = new int[n+1];
    for(int i = 0; i<=n; i++)
    {
        p[i] = 0;
    }
    C.x = p;
    C.BackTrack(1);
    delete[] p;
    return C.sum;
}

int main()
{
    int n,m;
    cin >> n >> m;
    int **a;
    a = (int **)malloc(sizeof(int*)*n);
    for(int i = 0; i<n; i++)
        a[i] = (int*)malloc(sizeof(int)*n);
    for(int i= 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            cin >> a[i][j];
    }
    cout << mColoring(n, m, a);
}
