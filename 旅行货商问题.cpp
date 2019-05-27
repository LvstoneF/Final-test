
#include <bits/stdc++.h>
using namespace std;


template<class type>
class Traveling{
    friend void main(void);
public:
    type BBTSP(int v[]);
private:
    int n;             /// 顶点数
    type **a,         /// 邻接矩阵
         NoEdge,      /// 有无边标记
         cc,          /// 当前费用
         bestc;       /// 当前有少费用
} ;

template<class type>
class MinHeapNode{
    friend Traveling<type>;
public:
    operator type () const {return lcost; }
private:


    type lcost,   /// 子树费用下界
         cc,      /// 当前费用
         rcost;   /// x[s:n-1]中顶点的最小出边费用
    int s,        /// 根节点到当前节点的路径x[0:s-1]
        *x;       /// 需要进一步搜索的节点x[s+1:n-1]
};


template<class type>
type Traveling<type>::BBSTP(int v[])
{
    MinHeap<MinHeapNode<type> > H(1000);
    type *MinOut = new type[n+1];
    /// 计算Minout[i] 的最小出边费用
    type MinSum = 0;
    for(int i = 0; i<= n; i++)
    {
        type Min = NoEdge;
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j] != NoEdge && (a[i][j] < Min || Min == NoEdge))
                Min = a[i][j];
            if(Min == NoEdge)
                return NoEdge;
            MinOut[i] = Min;
            Minsum += Min;
        }
        // 初始化
        MinHeapNode<type> E;
        E.x = new int[n];
        for(int i = 0; i<n; i++)
        {
            E.x[i] = i+1;
        }
        E.s = 0;
        E.cc = 0;
        E.rcost = Minsum;
        type bestc = NoEdge;
        // 搜索排列树
        while(E.s < n-1){
            if(E.s == n-2){
                // 再加上两条边构成回路，所构成的回路是否是优于当前最优解
                if(a[E.x[n-2]][E.x[n-1] != NoEdge && a[E.x[n0-1]][1]!= NoEdge
                   && (E.cc + a[E.x[n-2]][E.x[n-1] + a[E.x[n0-1]][1] < bestc ||
                       bestc == NoEdge) ){
                        // 费用更小的回路
                        bestc = E.cc + a[E.x[n0-1]][1] + a[E.x[n-2]][E.x[n-1];
                        E.cc = bestc;
                        E.lcost = bestc;
                        E.s++;
                        H.Insert(E);
                       }
                       else
                        delete[] E.x;
            }
            // 产生当前扩展节点的儿子节点
            else
            {
                for(int i = E.s+1; i<n; i++)
                {
                    if(a[E.x[E.s][E.x[i]] != NoEdge){

                        type cc = E.cc + a[E.x[E.s][E.x[i]]; // 可行儿子节点
                        type rcost = E.rcost - MinOut[E.x[E.s]];   // 子树可能包含最优解，加入优先队列中
                        type b = cc + rcost;
                        if(b < bestc || bestc == NoEdge)
                        {
                            MinHeapNode<type> N;
                            N.x = new int[n];
                            for(int j = 0; j<n; j++)
                                N.x[j] = E.x[j];
                            N.x[E.s+1] = E.x[i];
                            N.x[i] = E.x[E.s[i];
                            N.cc = cc;
                            N.s = E.s+1;
                            N.lcost = b;
                            N.rcost = rcost;
                            H.Insert(N);

                        }


                    }
                }
                delete[] E.x;
            }

        }
    }
}
