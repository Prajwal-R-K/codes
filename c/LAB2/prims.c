#include<stdio.h>

int cost[10][10],n;
void prims()
{
    int vt[10]={0};
    int min,a,b,u,v,mincost=0;
    int count=0;
    vt[0]=1;
    while(count<n-1)
    {
        min=999;
        for(int i=0;i<n;i++)
        {
            if(vt[i]==1)
            for(int j=0;j<n;j++)
            {
                if(cost[i][j]<min && vt[j]==0)
                {
                    min=cost[i][j];
                    a=i;
                    b=j;
                }
            }
        }
            printf("%d  %d  %d\n",a,b,min);
            mincost+=min;
            count++;
            vt[b]=1;

        }
        cost[a][b]=cost[b][a]=999;
}

void main()
{
    printf("N:");scanf("%d",&n);
    printf("\nCost matrix\n");
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&cost[i][j]);
   prims();
}