#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct calender{
    char *day,*disc;
    int date;
};
typedef struct calender cal;
cal* create()
{
    return (cal*)malloc(7*sizeof(cal));
}
void read(cal *d)
{
    int i,flag;
    
    char temp[50];
    for(i=0;i<7;i++)
    {
        d[i].day=NULL;
        d[i].date=-1;
        d[i].disc=NULL;
    }
    do{
        printf("\nEnter day number:");
        scanf("%d",&i);
        if(i<1||i>7)
            printf("Invalid Date");
        else
        {
            d[i].date=i;
            printf("\nEnter the day");
            scanf("%s",temp);
            d[i].day=strdup(temp);      //strdup is used to duplicate the content of the temp array
            //It dynamically allocates memory for a new string and copies the content of temp into that newly allocated memory.
            printf("\nEnter the discription");
            scanf(" %[^\n]",temp);//Give Space before %
            //strdup Usage: strdup duplicates a string and returns a pointer to the duplicated string
            d[i].disc=strdup(temp); 
        }
        printf("\nEnter 1 for more activies else 0:");
        scanf("%d",&flag);
    
    }while(flag!=0);
}
void display(cal *d)
{
    printf("\nDay name\tDay number\tDescription");
    for(int i=1;i<8;i++)
    {
        if(d[i].date!=-1)
            printf("\n%s\t%d\t%s",d[i].day,d[i].date,d[i].disc);
    }
}
void deallocate(cal *d)     
{
    for(int i=1;i<8;i++)
    {
        free(d[i].day);
        free(d[i].disc);

    }
    free(d);
    // free Function: The free function is used to release the memory allocated by malloc.
    // In this case, it is used in a loop to free the memory for each day's day and disc strings, 
    //and then it frees the memory for the array of cal structures.
}
void main()
{
    cal* d=create();
    read(d);
    display(d);
    deallocate(d);
}