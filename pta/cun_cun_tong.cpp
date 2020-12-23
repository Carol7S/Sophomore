#include<stdio.h>
#include<stdlib.h>

#define MAXVEX 1003
#define INFINITY  65535

int G[MAXVEX][MAXVEX],Nv,Ne;

void CreateGraph()
{
    //用邻接矩阵表示图
    int i,j;
    int v1,v2,w;

    for( i=1; i<=Nv; i++)
    {
        for( j=1; j<=Nv; j++)
        {
            G[i][j] = INFINITY;  //初始化
        }
    }

    for( i=0; i<Ne; i++)  //注意这里是读入边
    {
        scanf("%d %d %d",&v1,&v2,&w);
        G[v1][v2] = w;         //读入权值
        G[v2][v1]= G[v1][v2];  //无向图对称
    }
}


int  Prim()
{
    int min;
    int i,j,k;
    int lowcost[MAXVEX];
    int cost =0;


    lowcost[1] = 0;   //初始化第一个权值为0,即v0加入生成树

    for( i=2; i<=Nv; i++)
    {
        lowcost[i] = G[1][i];
    }

    for( i=2; i<=Nv; i++)
    {
        min = INFINITY;
        j = 1;
        k = 0;
        while( j<=Nv )
        {
            if( lowcost[j]!=0 && lowcost[j]<min)
            {
                min = lowcost[j];
                k = j;   //将当前最小值的下标存入k
            }
            j++;
        }

        if(k==0)
        {
            return -1;  //不连通
        }
        cost += min;
        lowcost[k] = 0;   //将当前顶点设置为0，表示此结点已经完成任务

        for( j=2; j<=Nv; j++)
        {
            if( lowcost[j]!=0 && G[k][j]<lowcost[j])
            {
                //若下标为k顶点各边权值小于此前这些顶点未被加入生成树的权值
                lowcost[j] = G[k][j];
            }
        }

    }

    return cost;
}


int main()
{
    int f = 0;
    scanf("%d %d",&Nv,&Ne);
    CreateGraph();
    f =Prim();
    printf("%d",f);
    system("pause");
    return 0;
}