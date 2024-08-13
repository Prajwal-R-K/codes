#include<stdio.h>

int cost[10][10],n,dist[10],source;

int minm(int a,int b)
{
    return(a<b?a:b);
}

void dijsktra()
{
    int vt[10]={0},min,w=0;
    for(int i=0;i<n;i++)
    {
        dist[i]=cost[source][i];
    }
    dist[source]=0;
    vt[source]=1;
    for(int i=0;i<n;i++)
    {
            min=999;
            for(int j=0;j<n;j++)
             if(vt[j]==0&&dist[j]<min)
             {
                min=dist[j];
                w=j;
             }
             vt[w]=1;
             for(int k=0;k<n;k++)
             {
                if(vt[k]==0&&cost[w][k]!=999)
                {
                    dist[k]=minm(dist[k],cost[w][k]+dist[w]);
                }
             }


    }   
     for(int j=0;j<n;j++)
            {
                printf("%d   %d   %d \n",source,j,dist[j]);
            }  
}

void main()
{
    printf("N:");scanf("%d",&n);
    printf("\nCost matrix\n");
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&cost[i][j]);
    printf("source:");scanf("%d",&source);
   dijsktra();
}