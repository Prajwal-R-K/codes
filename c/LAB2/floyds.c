#include<stdio.h>

int cost[10][10],n;

int min(int a,int b)
{
    return(a<b?a:b);
}


void floyds()
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<n;j++)
            {
                printf("%d  ",cost[i][j]);
            }       
            printf("\n");
    }   
}

void main()
{
    printf("N:");scanf("%d",&n);
    printf("\nCost matrix\n");
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&cost[i][j]);
   floyds();
}