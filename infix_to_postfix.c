#include <stdio.h>
#include<ctype.h>
#include<string.h>
#define size 100
char stack[size];
int top=-1;
void push(char item)
{
    stack[++top]=item;
}
char pop()
{
    return stack[top--];
}
char peek()
{
    if(top==-1)
    {
        return -1;
    }
    return stack[top];
}
int precedence(char c)
{
    if(c=='+' || c=='-')
    {
        return 1;
    }
    if(c=='/' || c=='*')
    {
        return 2;
    }
    if(c=='^')
    {
        return 3;
    }
    return 0;
   
}

int main() {
    printf("enter the infix expression:");
    char infix[size];
    scanf("%s",infix); //taking the infix expression
    char c;
    int k=0;
    char postfix[size];
    for(int i=0;infix[i]!='\0';i++)
        {
            c=infix[i];//c is the incoming character of the infix expression
            if(isalnum(c))
                {
                    postfix[k++]=c; //printing the operand
                }
            else if(c=='(')
                {
                    push(c);
                }
            else if(c==')')
                {
                    while(top!=-1 && peek()!='(')
                    {
                        postfix[k++]=pop();//pops and prints uptil (
                    }
                    pop();//discards the (
                }
            else if (c=='+' || c=='-' || c=='/' || c=='*')
            {
                while(top!=-1 && precedence(peek())>=precedence(c))
                {
                    postfix[k++]=pop();
                }
               
                    push(c);
               
               
            }
            else if(c=='^')
            {
                 while(top!=-1 && precedence(peek())>precedence(c))
                {
                    postfix[k++]=pop();
                }
               
                    push(c);
               
            }
        };
         //character reaching end implies entire expression is scanned
               
                    while(top!=-1)
                    {
                        postfix[k++]=pop();
                    }
               
                postfix[k]='\0';
        printf("the postfix expression is : %s",postfix);
   
 

   
}