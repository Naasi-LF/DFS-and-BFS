#include<stdio.h>
#include<stdlib.h>

#define USED 1
#define UNUSED 0

/*
a[],盒子
book[],给用过的扑克牌上标记
n个数全排列
*/

int a[10]={0},book[10]={0};//初始化

void dfs(int step,int n)
{
    if (step==n+1)//说明已经放完了
    {
        //输出
        for(int i=1;i<=n;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");

        return;//结束这个函数的使命
    }
    
    //从第step个盒子开始
    for (int i = 1; i <= n; i++)//按照1，2，3的优先级
    {
        if (book[i]==UNUSED)//如果没有标记过，说明没有使用
        {
            a[step]=i;//将扑克牌放入盒子里
            book[i]=USED;//放入盒子的牌进行标记，说明不在手里了
            dfs(step+1,n);//到第二个盒子
            book[i]=0;//把标记清零
        } 
        else continue;//标记过了看下一个i
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    dfs(1,n);
    return 0;
}
