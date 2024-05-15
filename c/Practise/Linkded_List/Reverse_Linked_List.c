#include<stdio.h>
#include<stdlib.h>
struct sllist{
    int data;
    struct sllist *link;
};
typedef struct sllist node;
int count=1;
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
        count++;
        return;
    }
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=t;
     count++;
    
}
void insertBEG()
{
    node *temp=start,*t;
    t=getnode();
    if(start==NULL)
    {
        start=t;
        return;
        count++;
    }
    t->link=start;
    start=t; 
    count++;

    
}
void insertPOS()
{
    node *t,*temp=start;
    t=getnode();
    int pos,count1=1;
    printf("Enter the pos:");
    scanf("%d",&pos);
    if(pos>count)
    {
        printf("Wrong POSITION");
        return;
    }
    
    while(count1!=pos-1)
    {
        temp=temp->link;
        count1++;
    }
   t->link=temp->link;
   temp->link=t;
    count++;
}
void deletEND()
{
    node *temp=start,*prev;
    if(count==1)
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
    count--;
    free(temp);
}
void deleteBEG()
{
    node *temp=start;
    if(count==1)
    {
        printf("EMPTY");
        return;
    }
    printf("\nDeleted ele is:%d\n",temp->data);
    start=temp->link;
    count--;
    free(temp);
}
void deletePOS()
{
    node *temp=start,*prev;
    int count1=1,pos;
    if(count==1)
    {
        printf("\nNO ELEMENT TO DELETE");
        return;
    }
    printf("\nEnter the POS:");
    scanf("%d",&pos);
    
    if(pos>count)
    {
        printf("\nWRONG POSITION");
        return;
    }
    while(count1!=pos)
    {   prev=temp;
        temp=temp->link;
        count1--;
    }
    printf("\nDeleted ele is:%d\n",temp->data);
    prev->link=temp->link;
    count--;
    free(temp);
}

void reverse() {
    node *prev = NULL;
    node *current = start;
    node *next = NULL;
    
    while (current != NULL) {
        next = current->link; // Store the next node
        current->link = prev; // Reverse the link
        prev = current;       // Move pointers one position ahead
        current = next;
    }
    start = prev; // Update start to point to the new first node
}

void Dispaly()
{
    node *temp=start;
    int count1=1;
    while(count1!=count)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
        count1++;
    }
}
void main()
{   int n;
    while(1)
    {
        printf("\n1-insert at End\n2-Insert at Begin\n3-Insert at position\n4-Delete at End\n5-Delete at Begin\n6-Delete at position\n7-Dispaly\n8-Reverse\n9-Exit\n");
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
            case 7:Dispaly();
                    break;
            case 8:reverse();
                    break;
            case 9:exit(0);
            default:printf("Wrong Entry");
                    
        }
    }
}