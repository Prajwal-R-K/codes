//#include<stdio.h>
#include<stdbool.h>
//void main(){
/*
    int a=printf("Hello");//Value of a will be no. of characters in string
    printf("\n %d",a);
    
    int (*p)[5];//Creates an array p of pointers.
    *p[0]=1;
    printf("\n%d\n",*p[0]);

    printf(5+"Test_Quiz");//print  the string after 5 characters of given String.

    char b[20]="gyug";
    printf("\n%d",sizeof(b));
    
int i=1;
for( ; ; )
{
    printf("\n%d ",i++);
    if(i>10);
    break;
}
bool aa=true;
printf("\n%d",aa);          */

/*
char greetings[] = "Hello World!";
printf("%c", greetings[0]);

}*/
#include<stdio.h>
#include<stdlib.h>
struct sllist{
    int data;
    struct sllist *link;
};
typedef struct sllist node;
node *start=NULL;
node* getnode()
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\nEnter the data");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    return newnode;
}
void insertEND()
{
    node *temp=start;
    node *t;
    t=getnode();
    if(start==NULL)
    {
        start=t;
        return;
    }
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=t;
    
}
void insertBEG()
{
    node *temp=start,*t;
    t=getnode();
    if(start==NULL)
    {
        start=t;
        return;
    }
    t->link=start;
    start=t;
    
}
void insertPOS()
{
    node *t,*temp=start;
    t=getnode();
    int pos,count=1;
    printf("Enter the pos:");
    scanf("%d",&pos);
    
    while(count!=pos)
    {
        temp=temp->link;
        count++;
    }
    t->link=temp->link;
    temp->link=t;
}
void deletEND()
{
    node *temp=start,*prev;
    if(start==NULL)
    {
        printf("EMPTY");
        return;
    }
    while(temp->link!=NULL)
    {   prev=temp;
        temp=temp->link;
    }
    printf("\nDeleted ele is:%d\n",temp->data);
    prev->link=NULL;
    free(temp);
}
void deleteBEG()
{
    node *temp=start;
    if(start==NULL)
    {
        printf("EMPTY");
        return;
    }
    printf("\nDeleted ele is:%d\n",temp->data);
    start=temp->link;
    free(temp);
}
void deletePOS()
{
    node *temp=start,*prev;
    int count=1,pos;
    printf("\nEnter the POS:");
    scanf("%d",&pos);
    while(count!=pos)
    {   prev=temp;
        temp=temp->link;
        count++;
    }
    printf("\nDeleted ele is:%d\n",temp->data);
    prev->link=temp->link;
    free(temp);
}
void main()
{   int n;
    while(1)
    {
        printf("\n1-insert at End\n2-Insert at Begin\n3-Insert at position\n4-Delete at End\n5-Delete at Begin\n6-Delete at position\n7-Dispaly\n8-Exit");
        scanf("%d",&n);
        switch(n)
        {
            case 1:insertEND();
                    break;
            case 2:insertBEG();
                    break;
            case 3:insertPOS();
                    break;
            case 4:deletEND();
                    break;
            case 5:deleteBEG();
                    break;
            case 6:deletePOS();
                    break;
            
        }
    }
}