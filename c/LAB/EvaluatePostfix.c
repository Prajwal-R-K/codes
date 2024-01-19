#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
float stack[20];
int top=-1;
void push(float ele)
{
    stack[++top]=ele;
}
float pop()
{
    return(stack[top--]);
}
void Evaluate(char postfix[20])
{
    int i;
    char sym;
    float op1,op2,result;
    for(i=0;i<strlen(postfix);i++)
    {
        sym=postfix[i];
        if(isdigit(sym))
            push(sym-'0');
        else{
            op1=pop();
            op2=pop();
            switch(sym)
            {
            case '+':push(op2+op1);
                break;
            case '-':push(op2-op1);
                break;
            case '*':push(op2*op1);
                break;
            case '^':push(pow(op2,op1));
                break;
            case '/':push(op2/op1);
                break;
            case '%':push((int)op2%(int)op1);
                break;
            default:printf("\nInvalid POstfix Expression");
                exit(0);
            }
        }

    }
result=pop();
printf("result= %f",result);
}
void main()
{
    char postfix[20];
    printf("\nEnter the postfix expression:");gets(postfix);
    Evaluate(postfix);
}