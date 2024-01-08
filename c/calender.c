#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Calender 
{
    char *name,*description;
    int date;
};

typedef struct Calender cal;

cal *create()
{
    return ((cal*)malloc(7*sizeof(cal)));
} 

void read(cal*d)
{
    int i ,flag;
    char temp[20];
    for(i=0;i<7;i++)
    {
        d[i].name = NULL;
        d[i].date = -1;
        d[i].description = NULL;  
    }do
    {
        printf("Enter the date");
        scanf("%d",&i);
        if(i<0 || i>6 )
        {
            printf("Invalid input");
        }
        else
        {
            d[i].date = i;
            printf("Enter the name");
            scanf("%s",temp);
            d[i].name = strdup(temp);
            printf("Enter the description");
            scanf("%s",temp);
            d[i].description = strdup(temp);
        }
        printf("Enter 1 to continue or 0 to stop");
        scanf("%d",&flag); 
    } while(flag==1);
}

void display(cal *d)
{
    int i;
    for(i=0;i<7;i++)
    {
        if(d[i].date != -1)
        {
            printf("%d\t %s\t %s\t\n",d[i].date,d[i].name,d[i].description);
        }
    }
} 

void deallocate(cal*d)
{
    int i;
    for(i=0;i<7;i++)
    {
        free(d[i].name);
        free(d[i].description);
    }
    free(d);
}

int main()
{
    cal *d = create();
    read(d);
    display(d);
    deallocate(d);
    return 0;
}