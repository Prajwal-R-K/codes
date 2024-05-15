#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct poly
{
    int c,expo1,expo2,expo3,flag;
    struct poly *next;
};
typedef struct poly node;
void insert(node* h,int c,int e1,int e2,int e3)
{
    node *temp;
    node* newnode=(node*)malloc(sizeof(node));
    newnode->c=c;
    newnode->expo1=e1;
    newnode->expo2=e2;
    newnode->expo3=e3;
    newnode->flag=0;
    newnode->next=NULL;
    temp=h->next;
    while(temp->next!=h)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=h;
}

void read(node *h)
{
    int n,c,e1,e2,e3;
    printf("\nEnter the number of terms:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the Coefficient,expo1,expo2,expo3\n");
        scanf("%d%d%d%d",&c,&e1,&e2,&e3);
        insert(h,c,e1,e2,e3);
    }
}

void printp(node* h)
{
    node *p1=h->next;
    printf("\n");
    while(p1->next!=h)
    {
        printf("%dx^%dy^%dz^%d+",p1->c,p1->expo1,p1->expo2,p1->expo3);
        p1=p1->next;
    }
     printf("%dx^%dy^%dz^%d",p1->c,p1->expo1,p1->expo2,p1->expo3);
}
void evaluate(node *h)
{
    node *p1=h->next;
    int sum=0,x,y,z;
    printf("\nEnter the value of x,y,z:");scanf("%d%d%d",&x,&y,&z);
    while(p1!=h)
    {
        sum=sum+p1->c*(pow(x,p1->expo1))*(pow(y,p1->expo2))*(pow(z,p1->expo3));p1=p1->next;
    }
    printf("\nEvaluated:%d",sum);
}
void add(node *h1,node *h2,node *h3)
{
    
    node *p1,*p2;
    int c;
    p1=h1->next;
    while(p1!=h1)
    {
        p2=h2->next;
        while(p2!=h2)
        {
            if(p1->expo1==p2->expo1&&p1->expo2==p2->expo2&&p1->expo3==p2->expo3)
                {
                    c=p1->c+p2->c;
                    insert(h3,c,p1->expo1,p1->expo2,p1->expo3);
                    p1->flag=1;
                    p2->flag=1;
                }
            p2=p2->next;
        }
        p1=p1->next;
    }
    p1=h1->next;
    p2=h2->next;
    while(p1!=h1)
    {
        if(p1->flag==0)
        {
            insert(h3,p1->c,p1->expo1,p1->expo2,p1->expo3);
            
        }
        p1=p1->next;
    }
    
    while(p2!=h2)
    {
        
       
        if(p2->flag==0)
        {
            insert(h3,p2->c,p2->expo1,p2->expo2,p2->expo3);
        }
        p2=p2->next;
    }
}
void main()
{
    node *h1=(node*)malloc(sizeof(node));
    h1->next=h1;
    node *h2=(node*)malloc(sizeof(node));
    h2->next=h2;
    node *h3=(node*)malloc(sizeof(node));
    h3->next=h3;
    printf("\nEnter the 1st polpynomial:");
    read(h1);
    printf("\nEnter the 2st polpynomial:");
    read(h2);

    printf("\nDisplay\n");
    printp(h1);
    printp(h2);
    add(h1,h2,h3);
    printf("\nResultant poly:");
    printp(h3);
    evaluate(h3);


}
