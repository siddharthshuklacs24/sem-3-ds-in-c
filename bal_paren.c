#include<stdio.h>
#include <stdbool.h>
#define size 100
char stack[size];
int top=-1;
void push(char element)
{
    if(top==size-1)
    {
        
    }
    else
    {
        top++;
        stack[top]=element;
    }
}
char  pop()
{
    if(top==-1)
    {
       
        return -1;
    }
    else
    {
        char element=stack[top];
        top--;
        return element;
        
        
    }
}

void main() {
    bool isBalanced=true;
    char q[100];
    printf("enter the expression:");
    scanf("%s",q);
    //code for the opening parenthesis
    for(int i=0;q[i]!='\0';i++)
    {
        if(q[i]!='(' && q[i]!=')' && q[i]!='[' && q[i]!=']' && q[i]!='{' && q[i]!='}')
        {
            printf("invalid expression");
            return 0;
        }
        if(q[i]=='(' || q[i]=='[' || q[i]=='{')
        {
            push(q[i]);
        }
        if(q[i]==')' || q[i]==']' || q[i]=='}')
        {
            char paren=pop();
            if(q[i]==')' && paren!='(' || 
        q[i]=='}' && paren!='{' || 
        q[i]==']' && paren!='[' )
            {
                isBalanced=false;
                break;
            }
        }
    }
   
    if(isBalanced && top==-1)
    {
        printf("the expression is balanced");
    }
    else
    {
        printf("the expression is not balanced");
    }
}