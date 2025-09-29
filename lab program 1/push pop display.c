#include <stdio.h>

#define STACK_SIZE 2

int top = -1;
int s[STACK_SIZE];
int item;
void push()
{
    if(top==STACK_SIZE-1)
    {
        printf("stack overflow\n");

    }
    else{
        printf("enter the element to be inserted:\n");
     scanf("%d",&item);
         top=top+1;
    s[top]=item;

    }

}
void pop()
{
    if(top==-1)
    {
        printf("stack underflow\n");

    }
    else
    {
        printf("the element deleted is:%d\n",s[top--]);
    }

}
void display()
{
    if(top==-1)
    {
        printf("stack is empty\n");

    }
    else
    {
         printf("content of the stack is:\n");
    for(int i=top;i>=0;i--)
    {
        printf("%d\n",s[i]);
    }
    }

}
int main()
{

    int a;
    while(a!=4)
    {
        printf("enter 1 for push,2 for pop,3 for display,4 for exit:");
        scanf("%d",&a);
        switch(a)
        {
            case 1:


                   push();
                   break;
            case 2:pop();
                   break;
            case 3:
                   display(top, s);
                   break;
            case 4:printf("exited the code");
                   break;
            default:printf("invalid input");
        }
    }
    return 1 ;
}


