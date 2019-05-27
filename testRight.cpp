#include <stdio.h>
#include <math.h>
#define n 3
#define m 3 //��ɫ��

int a[n+1][n+1]={
    {0,1,1},
    {1,0,1},
    {1,1,0},

};
int count=0;//������
int color[n+1]={0};//Ϳ��ɫ����

bool ok(int x){
    for(int i=1; i<=n; i++){
        if(a[x][i]==1 && color[x]==color[i]){//����Ϊ1�����ظ�
            return false;
        }
    }
    return true;
}

void dfs(int t){
    if(t>n){//��n�������ͼ����ɫ������n+1��
        count++;
    }else{
        for(int i=1; i<=m; i++){//Ϳ��ɫ 1~m
            color[t]=i;
            if(ok(t)){
                dfs(t+1);
            }
            color[t]=0;
        }
    }
}

int main(){
    dfs(1);//��1��ʼ
    printf("%d\n",count);
    return 0;
}

