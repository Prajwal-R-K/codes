#include<stdio.h>
#include<stdlib.h>

int *stack,top=-1,max;
void push(int ele)
{
     if(top==max-1)
    {
        printf("\nSTACK OVERFLOW");
        return;
    }

    //int n;
    //scanf("%d",&n);
    //stack[++top]=n;

    stack[++top]=ele;
}
int pop()
{
    if(top==-1)
    {
        printf("\nSTACK UNDERFLOW");
        return -1;
    }
    return(stack[top--]);
}
void display()
{   
    if(top==-1)
    {
        printf("\nSTACK UNDERFLOW");
        return ;
    }
    printf("\nThe elements are\n");
    for(int i=top;i>=0;i--)
    {
       printf("%d\t",stack[i]);
    }
    return;
}
void palindrome()
{   top=-1;
    int n,num,copy;
    printf("\nENter the number:");
    scanf("%d",&num);
    copy=num;
    while(copy!=0)
    {
        push(copy%10);
        copy=copy/10;
    }
    while(num!=0)
    {
        if(num%10!=pop())
        {
            printf("\nNOT PALINDROME\n");
            top=-1;
            return;
        }
        num=num/10;
    }
    printf("\nPALINDROME");

}
void main()
{   printf("\nEnter the size");
    scanf("%d",&max);
    stack=(int*)malloc(max*sizeof(int));
    int n,ele;
    while(1)
    {   
        printf("\n1-push 2-pop 3-display 4-palindrome 5-exit");
        scanf("%d",&n);
        switch(n){
            case 1:printf("\nEnter the element:");
                   scanf("%d",&ele);
                   push(ele);
                    break;
            case 2:ele=pop();
                    if(ele!=-1)
                    {                    
                    printf("\npoped element is %d",ele);
                    }   
                   break;
            case 3:display();break;
            case 4:palindrome();break;
            case 5:exit(0);
            default:printf("\nINVALID");

        }
    }
}