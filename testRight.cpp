#include <stdio.h>
#include <math.h>
#define n 3
#define m 3 //颜色数

int a[n+1][n+1]={
    {0,1,1},
    {1,0,1},
    {1,1,0},

};
int count=0;//方案数
int color[n+1]={0};//涂颜色数组

bool ok(int x){
    for(int i=1; i<=n; i++){
        if(a[x][i]==1 && color[x]==color[i]){//不能为1，不重复
            return false;
        }
    }
    return true;
}

void dfs(int t){
    if(t>n){//有n个顶点的图的着色树是有n+1层
        count++;
    }else{
        for(int i=1; i<=m; i++){//涂个色 1~m
            color[t]=i;
            if(ok(t)){
                dfs(t+1);
            }
            color[t]=0;
        }
    }
}

int main(){
    dfs(1);//从1开始
    printf("%d\n",count);
    return 0;
}

