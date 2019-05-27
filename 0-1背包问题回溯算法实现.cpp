#include <bits/stdc++.h>
using namespace std;

template<class Typew, class Typep>
class Knap{
    friend Typep Knapsack(Typep*, Typew*, Typew, int);
private:
    Typep Bound();
    void Backtrack();
    Typep cp;   /// 当前价值
    Typew cw;   /// 当前重量
    Typep *p;   /// 价值序列
    Typew *w;   /// 重量序列
    Typep bestp;   /// 最优解
    int n;      /// 物品数量
    Typew c;    /// 背包容量
};

/// 右子树的上界函数
template<class Typew, class Typep>
Typep Knap<Typw, Typep>::Bound(int i)
{
    Typew cleft = c-cw; /// (进入右子树时剩余的背包容量)背包容量-当前重量
    Typep b = cp;
    /// 剩余的物品以单位重量递减装入
    while(i <= n && w[i] <= cleft ){
        cleft -= w[i];   /// 每循环一次，背包容量就要减少
        b+=p[i];   /// 上界都要加上当前物品的价值
        i++
    }
    /// 最后一个物品装入部分
    if(i<=n)
        b+=p[i]/w[i]*cleft;
    return b;
}

template<class Typew, class Typep>
void Knap<Typew, Typep>::Backtrack(int i)
{
    /// 回溯结束，当前的价值就是最优价值
    if(i>=n)
    {
        bestp = cp;
        return;
    }
    /// 搜索左子树
    if(cw+w[i] <= w)
    {
        x[i] = 1; /// 表示装入
        cw += w[i];
        cp += p[i];
        /// 进行下一轮回溯
        Backtrack(i+1);
        /// 为了进入右子树做准备；
        cw -= w[i];
        cp -= p[i];
    }
    /// 搜索右子树
    if(bound(i+1) > bestp){
        x[i] = 0;
        Backtrack(i+1);
    }
}


/// 解空间树的结构，
class Object{
    friend int Knapsack(int*, int*, int, int);
public:
    /// 用于后面的sort排序
    int operator<=(Object a) const {return (d >= a.d); }
private:
    int ID;   /// 每一个物品的下标
    float d; /// 单位价值
};



template<class Typew, class Typep>
Typep Knapsack(Typep p[], Typew w[], Typew c, int n)
{
    Typew W = 0;
    Typep P = 0;
    Object *Q = new Object[n];
    for(int i = 1; i<=n; i++)
    {
        Q[i-1].ID = i;
        Q[i-1].d = 1.0*p[i]/w[i];
        p += p[i];
        w += w[i];
    }
     /// 如果背包的总容量大于物品总重量，可全部装入，最优解为所有价值之和
    if(w<=c)
        return P;
    /// 按照单位价值对物品进行排序
    sort(Q, Q+n);
    /// 新建一个实例K
    Knap<Typew, Typep> K;
    K.p = new Typep [n+1];
    K.w = new Typew [n+1];
    for(int i = 1; i<=n; i++)
    {
        K.p[i] = p[Q[i-1].ID];
        K.w[i] = w[Q[i-1].ID];
    }
    K.cp = 0;
    K.cw = 0;
    K.c = c;
    K.n = n;
    K.bestp = 0;
    K.Backtrack(1);
    delete[] Q;
    delete[] K.w;
    delete[] K.p;
    return K.bestp;
}

int main()
{


}
