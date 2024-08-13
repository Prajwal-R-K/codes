#include<stdio.h>

int cost[10][10],n;
void kruskal()
{
    int par[10];
    for(int i=0;i<n;i++)
    {
        par[i]=-1;
    }
    int min,a,b,u,v,mincost=0;
    int count=0;
    while(count<n-1)
    {
        min=999;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=i;
                    b=j;
                }
            }
        }
        u=a;
        v=b;
        while(par[u]!=-1)
            u=par[u];
        while(par[v]!=-1)
            v=par[v];
        if(u!=v)
        {
            printf("%d  %d  %d\n",a,b,min);
            par[v]=u;
            mincost+=min;
            count++;

        }
        cost[a][b]=cost[b][a]=999;
    }
}

void main()
{
    printf("N:");scanf("%d",&n);
    printf("\nCost matrix\n");
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&cost[i][j]);
    kruskal();
}