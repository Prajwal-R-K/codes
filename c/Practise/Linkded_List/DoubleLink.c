#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *right,*left;

};
typedef struct  node n;
n *head=NULL;
n* getnode()
{
    n *q;
    q=(n*)malloc(sizeof(n));
    printf("Enter the data");
    scanf("%d",&q->data);
    q->right=NULL;
    q->left=NULL;
    return q;

}
void insertEnd()
{
    n *t,*temp;
    temp=head;
    t=getnode();
    if(head==NULL)
    {
        head=t;
        return;
    }
    else
    {
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        t->left=temp;
        temp->right=t;
        
    }
}
void main()
{
    insertEnd();
    insertEnd();

}
