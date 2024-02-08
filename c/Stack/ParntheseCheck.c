#include<stdio.h>
char stack[10];
int top=-1;
void push(char c)
{
    stack[++top]=c;
}
char pop()
{
    if(top==-1) return '0';
    return(stack[top--]);
}
int check(char c)
{
    switch(c)
    {
        case '[':
        case ']':return 1;
        case '(':
        case ')':return 2;
        case '{':
        case '}':return 3;
    }
}
void main()
{
    int flag=0;
    char s[40];
    printf("\nEnter the string:");
    gets(s);
    for(int i=0;s[i]!='\0';i++)
    {
        char a=s[i];
        if(a=='['||a=='{'||a=='(')
        {
            push(a);
        }
        if(a==']'||a=='}'||a==')')
        {
            char b=pop();
            if(check(a)!=check(b))
            {
                printf("\n NOT MATCHED IS -- %c,%c",a,b);
                flag=1;
                break;
            }
        }
    }
    if(flag==0&&top==-1)
    printf("\nValid Expression");
    else
    printf("\nInvalid Expression");
}