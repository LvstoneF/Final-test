#include <bits/stdc++.h>
using namespace std;

template<class Typew, class Typep>
class Knap{
    friend Typep Knapsack(Typep*, Typew*, Typew, int);
private:
    Typep Bound();
    void Backtrack();
    Typep cp;   /// ��ǰ��ֵ
    Typew cw;   /// ��ǰ����
    Typep *p;   /// ��ֵ����
    Typew *w;   /// ��������
    Typep bestp;   /// ���Ž�
    int n;      /// ��Ʒ����
    Typew c;    /// ��������
};

/// ���������Ͻ纯��
template<class Typew, class Typep>
Typep Knap<Typw, Typep>::Bound(int i)
{
    Typew cleft = c-cw; /// (����������ʱʣ��ı�������)��������-��ǰ����
    Typep b = cp;
    /// ʣ�����Ʒ�Ե�λ�����ݼ�װ��
    while(i <= n && w[i] <= cleft ){
        cleft -= w[i];   /// ÿѭ��һ�Σ�����������Ҫ����
        b+=p[i];   /// �Ͻ綼Ҫ���ϵ�ǰ��Ʒ�ļ�ֵ
        i++
    }
    /// ���һ����Ʒװ�벿��
    if(i<=n)
        b+=p[i]/w[i]*cleft;
    return b;
}

template<class Typew, class Typep>
void Knap<Typew, Typep>::Backtrack(int i)
{
    /// ���ݽ�������ǰ�ļ�ֵ�������ż�ֵ
    if(i>=n)
    {
        bestp = cp;
        return;
    }
    /// ����������
    if(cw+w[i] <= w)
    {
        x[i] = 1; /// ��ʾװ��
        cw += w[i];
        cp += p[i];
        /// ������һ�ֻ���
        Backtrack(i+1);
        /// Ϊ�˽�����������׼����
        cw -= w[i];
        cp -= p[i];
    }
    /// ����������
    if(bound(i+1) > bestp){
        x[i] = 0;
        Backtrack(i+1);
    }
}


/// ��ռ����Ľṹ��
class Object{
    friend int Knapsack(int*, int*, int, int);
public:
    /// ���ں����sort����
    int operator<=(Object a) const {return (d >= a.d); }
private:
    int ID;   /// ÿһ����Ʒ���±�
    float d; /// ��λ��ֵ
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
     /// ���������������������Ʒ����������ȫ��װ�룬���Ž�Ϊ���м�ֵ֮��
    if(w<=c)
        return P;
    /// ���յ�λ��ֵ����Ʒ��������
    sort(Q, Q+n);
    /// �½�һ��ʵ��K
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
