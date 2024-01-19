#include<stdio.h>
#include<string.h>
char stack[20];
int top=-1;
void push(char s)
{
    stack[++top]=s;
}
char pop()
{
    return(stack[top--]);
}
int prec(char s)
{
    switch (s)
    {
    case '^':return 4;
    case '*':
    case '/':return 3;
    case '+':
    case '-':return 2;
    case '(':
    case ')':
    case '#':return 1;
    }
    return 0;
}
void convert(char in[20],char postfix[20])
{
    int i,j=0;
    char sym;
    push('#');
    for(i=0;i<strlen(in);i++)
    {
        sym=in[i];
        switch(sym)
        {
            case '(':push(sym);break;
            case ')':while(stack[top]!='(')
                        postfix[j++]=pop();
                    pop();                     
                            break;
            case '^':
            case '*':
            case '/':
            case '+':
            case '-':while(prec(sym)<=prec(stack[top]))
                        postfix[j++]=pop();
                    push(sym);
                    break;
            default:postfix[j++]=sym;

        }
    }
        while(stack[top]!='#')
            postfix[j++]=pop();
        postfix[j]='\0';
        
    
}
void main()
{
    char infix[20];char postfix[20];
    printf("\nEnter infix expression:");
    gets(infix);
    convert(infix,postfix);
    printf("\nPostfix expression is : %s",postfix);

}