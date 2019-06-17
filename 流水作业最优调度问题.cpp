#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn = 100;

struct node
{
    int time; //ִ��ʱ��
    int index; //��ҵ���
    bool group; //1�����һ��������0����ڶ�������
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
        //n����ҵ�У�ÿ����ҵ����С�ӹ�ʱ��
        c[i].time=min(a[i], b[i]);
        c[i].index=i;
        c[i].group=a[i]<=b[i];
    }

    sort(c,c+n,cmp);

    j=0,k=n-1;
    for(i=0; i<n; i++)
        if(c[i].group) best[j++]=c[i].index; //��һ�飬��i=0��ʼ���뵽best[]
        else best[k--]=c[i].index;

    j=a[best[0]]; //���ŵ��������µ�������ʱ��
    k=j+b[best[0]];

    for(i=1; i<n; i++)
    {
        j+=a[best[i]];
        k=j<k?(k+b[best[i]]):j+b[best[i]];
        //������ʱ������ֵ
    }

    printf("����ʱ�䣺%d\n",k);
    printf("���ŵ������У�");
    for(i=0; i<n; i++) printf("%d ",best[i]+1);
    printf("\n");
}
