#include<stdio.h>
#include<stdlib.h>

int n,m,p,q,min=99999999;
int a[51][51];//用来定义迷宫大小
int book[51][51];//用来标记某个坐标

void dfs(int x,int y,int step)//横坐标,纵坐标,步数
{
    //判断是否到达位置
    if(x==p&&y==q)
    {
        if(step<min)//更新最小值
        {
            min=step;
        }
        return;//返回上一级递归
    }

    int next[4][2]=//四个含有两个元素的一维数组
    {
      //右
      {0,1},
      //下
      {1,0},
      //左
      {0,-1},
      //上
      {-1,0}
    };

    //枚举四种走法
    //获得下一个位置的坐标(tx,ty)
    int tx,ty;
    for(int k=0;k<=3;k++)
    {
    //计算下一个点的坐标
    tx=x+next[k][0];
    ty=y+next[k][1];
    //是否越界
    if(tx<1||tx>n||ty<1||ty>m)
        continue;
    //不是障碍物并且没有标记过
    if(a[tx][ty]==0&&book[tx][ty]==0)
    {
        book[tx][ty]=1;//标记
        dfs(tx,ty,step+1);//开始下一步
        book[tx][ty]=0;//取消标记
    }

    }
}
int main()

{
    scanf("%d %d",&n,&m);//定义一个n*m的矩阵
    //输入迷宫
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d",&a[i][j]);
        }    
    }
    //读入起始点，中止点
    int start_x,start_y;
    scanf("%d %d %d %d",&start_x,&start_y,&p,&q);
    //标记起始点
    book[start_x][start_y]=1;
    //调用函数
    dfs(start_x,start_y,0);

    //输出最短路径
    printf("%d",min);
    return 0;
}