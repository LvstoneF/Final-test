
#include <bits/stdc++.h>
using namespace std;


template<class type>
class Traveling{
    friend void main(void);
public:
    type BBTSP(int v[]);
private:
    int n;             /// ������
    type **a,         /// �ڽӾ���
         NoEdge,      /// ���ޱ߱��
         cc,          /// ��ǰ����
         bestc;       /// ��ǰ���ٷ���
} ;

template<class type>
class MinHeapNode{
    friend Traveling<type>;
public:
    operator type () const {return lcost; }
private:


    type lcost,   /// ���������½�
         cc,      /// ��ǰ����
         rcost;   /// x[s:n-1]�ж������С���߷���
    int s,        /// ���ڵ㵽��ǰ�ڵ��·��x[0:s-1]
        *x;       /// ��Ҫ��һ�������Ľڵ�x[s+1:n-1]
};


template<class type>
type Traveling<type>::BBSTP(int v[])
{
    MinHeap<MinHeapNode<type> > H(1000);
    type *MinOut = new type[n+1];
    /// ����Minout[i] ����С���߷���
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
        // ��ʼ��
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
        // ����������
        while(E.s < n-1){
            if(E.s == n-2){
                // �ټ��������߹��ɻ�·�������ɵĻ�·�Ƿ������ڵ�ǰ���Ž�
                if(a[E.x[n-2]][E.x[n-1] != NoEdge && a[E.x[n0-1]][1]!= NoEdge
                   && (E.cc + a[E.x[n-2]][E.x[n-1] + a[E.x[n0-1]][1] < bestc ||
                       bestc == NoEdge) ){
                        // ���ø�С�Ļ�·
                        bestc = E.cc + a[E.x[n0-1]][1] + a[E.x[n-2]][E.x[n-1];
                        E.cc = bestc;
                        E.lcost = bestc;
                        E.s++;
                        H.Insert(E);
                       }
                       else
                        delete[] E.x;
            }
            // ������ǰ��չ�ڵ�Ķ��ӽڵ�
            else
            {
                for(int i = E.s+1; i<n; i++)
                {
                    if(a[E.x[E.s][E.x[i]] != NoEdge){

                        type cc = E.cc + a[E.x[E.s][E.x[i]]; // ���ж��ӽڵ�
                        type rcost = E.rcost - MinOut[E.x[E.s]];   // �������ܰ������Ž⣬�������ȶ�����
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
