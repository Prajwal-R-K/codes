#include<stdio.h>

int cost[10][10],n,dist[10],source;
int indegre[10],removal[10]={0};

void cal()
{
    for(int i=0;i<n;i++)
    {
        indegre[i]=0;
        for(int k=0;k<n;k++)
        {
            indegre[i]+=cost[k][i];
        }
    }
}

void sourcere()
{
    for(int i=0;i<n;i++)
    {
        cal();
        int j;
        for(j=0;j<n;j++)
        {
            if(indegre[j]==0 && removal[j]==0)
                break;
        }
        printf("%d  ",j);
        removal[j]=1;
        for(int k=0;k<n;k++)
        {
            cost[j][k]=0;
        }
    }


}
void main()
{
    printf("N:");scanf("%d",&n);
    printf("\nCost matrix\n");
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&cost[i][j]);
    sourcere();
}