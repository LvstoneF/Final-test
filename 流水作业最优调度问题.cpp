#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn = 100;

struct node
{
    int time; //执行时间
    int index; //作业序号
    bool group; //1代表第一个机器，0代表第二个机器
};

bool cmp(node a,node b)
{
    return a.time<b.time;
}

int main()
{
    int i,j,k,n;
    int a[maxn]= {0},b[maxn]= {0};
    int best[maxn];
    node c[maxn];
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    for(int i=0; i<n; i++) scanf("%d",&b[i]);

    for(i=0; i<n; i++)
    {
        //n个作业中，每个作业的最小加工时间
        c[i].time=min(a[i], b[i]);
        c[i].index=i;
        c[i].group=a[i]<=b[i];
    }

    sort(c,c+n,cmp);

    j=0,k=n-1;
    for(i=0; i<n; i++)
        if(c[i].group) best[j++]=c[i].index; //第一组，从i=0开始放入到best[]
        else best[k--]=c[i].index;

    j=a[best[0]]; //最优调度序列下的消耗总时间
    k=j+b[best[0]];

    for(i=1; i<n; i++)
    {
        j+=a[best[i]];
        k=j<k?(k+b[best[i]]):j+b[best[i]];
        //消耗总时间的最大值
    }

    printf("最优时间：%d\n",k);
    printf("最优调度序列：");
    for(i=0; i<n; i++) printf("%d ",best[i]+1);
    printf("\n");
}
