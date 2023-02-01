#include<stdio.h>

struct note
{
    int x;//横坐标
    int y;//纵坐标
    int s;//步数
};
int main()
{
    struct note que[2501];
    //表示扩展
    int a[51][51]={0};//地图
    int book[51][51]={0};//标记

    int next[4][2]=//四个含有两个元素的一维数组
    {
      //右    下     左     上
      {0,1},{1,0},{0,-1},{-1,0}
    };

    int head,tail;//队列，队尾

    int n,m;
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
    int p,q;
    scanf("%d %d %d %d",&start_x,&start_y,&p,&q);

    //队列初始化
    head=1;
    tail=1;
    //插入迷宫A的坐标
    que[tail].x=start_x;
    que[tail].y=start_y;
    que[tail].s=0;//现在一步还没走呢
    tail++;//tail指向2
    book[start_x][start_y]=1;//做标记

    int flag=0;//用来标记是否到达目的地

    int tx,ty;
    //当队列不为空
    while (head<tail)
    {
        //枚举四个方向
        for (int k = 0; k <= 3; k++)
        {
            //计算下一个点的坐标
            tx=que[head].x+next[k][0];
            ty=que[head].y+next[k][1];

            //是否越界
            if(tx<1||tx>n||ty<1||ty>m)
             continue;

            //不是障碍物并且没有标记过
            if(a[tx][ty]==0&&book[tx][ty]==0)
            {
              book[tx][ty]=1;//标记
              //将新的插入队列的末尾
              que[tail].x=tx;
              que[tail].y=ty;
              que[tail].s=que[head].s+1;//步数+1
              tail++;//tail向后
            }

            //如果到目的地了
            if (tx==p&&ty==q)
            {
                flag=1;
                goto end_while;//跳出所有循环
            }
        }
        head++;
    }
    //输出步数
    end_while:
    printf("%d",que[tail-1].s);
    return 0;
}