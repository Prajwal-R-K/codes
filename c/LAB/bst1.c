#include<stdio.h>
#include<stdlib.h>
typedef struct BST
{
    int data;
    struct BST *left,*right;
}node;
node* insert(node *root,int key)
{
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->data=key;
        root->left=root->right=NULL;
    }
    else if(key<root->data)
    root->left=insert(root->left,key);
    else if(key>root->data)
    root->right=insert(root->right,key);
    return root;
}
void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
void preorder(node *root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}
void search(node *root,int key)
{
    if(root==NULL)
     printf("key not found");
    else if(key==root->data)
    printf("key found");
    else if(key<root->data)
    search(root->left,key);
    else
    search(root->right,key);   
}
int main()
{
    int n,i,key,choice;
    node *root=NULL,*temp;
    printf("entr the no of nodes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the element\n");
        scanf("%d",&key);
        root=insert(root,key);
    }
    while(1)
    {
        printf("enter 1 inorder\n 2 preorder\n 3 postorder \n 4 search\n 5 exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("\n inorder is\n");
            inorder(root);break;
            case 2:printf("\n preorder is\n");
            preorder(root);break;
            case 3:printf("\n postorder is\n");
            postorder(root);break;
            case 4:printf("\n enetr the key to be searched\n");
            scanf("%d",&key);
            search(root,key);break;
            case 5:exit(0);
            default:printf("invalid");
            break;
        }
    }
    return 0;
}