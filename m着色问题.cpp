#include <bits/stdc++.h>
using namespace std;


/*1. 在回溯算法中， 回溯到叶子节点的时候，就可以得到一中着色方法
  2. 如果是内节点，就需要给这个节点着色，
    1. 着色方法为：先从第一种颜色开始，把每一种颜色都试一遍，看看什么颜色是适合的
    2. 这里就需要用到约束函数（OK(t)）当前节点t的着色是否满足约束条件
    3. 约束条件，从第一个节点j开始，看看节点j t 是否是有边相连的，如果有边相连并且两个的颜色一样，节点t就不能用这个颜色，在换下一种颜色判断
*/

class Color {
    friend int mColoring(int, int, int**);// 实例化
private:
    bool OK(int t);
    void BackTrack(int t);
    int n; // 节点；
    int m; // 色数
    int sum;
    int **a; // 邻接矩阵G(V,E);
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
    //初始化x;
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
