#include<stdio.h>
#define N 2
int queue[N];
int front=-1;
int rear=-1;
void enque()
{

    if(front==-1 && rear==-1)
    {
         printf("enter the element to be inserted\n");
         int x;
         scanf("%d",&x);
        front=0;
        rear=0;
        queue[rear]=x;

    }
    else if(rear==N-1)
    {
        printf("queue overflow\n");

    }
    else
    {
         printf("enter the element to be inserted\n");
        int x;
        scanf("%d",&x);
        queue[++rear]=x;
    }
}
void deque()
    {
        if(front==-1 && rear==-1)
        {
            printf("queue is empty\n");

        }
        else if(front==rear && front!=-1)
        {

            int element=queue[front];
            front=rear=-1;
            printf("element deleted is:%d\n",element);

        }
        else
        {
           printf("element deleted is:%d\n",queue[front++]);
        }
    }
void peek()
    {
         if(front==-1 && rear==-1)
        {
            printf("queue is empty");
        }
        else
        {
            printf("the element at the front of the queue is:\n");
            printf( "%d",queue[front]);
            printf("\n");
        }
    }
void display()
    {
        if(front==-1 && rear==-1)
        {
            printf("queue is empty\n");
        }
        else
        {
            printf("the elements of the queue are:\n");
            for(int i =front;i<=rear;i++)
            {
                printf("%d\t",queue[i]);
            }
            printf("\n");
        }
    }

    void main()
    {
        int choice=0;

        while(choice!=5)
        {
              printf("enter 1 for enque,2 for deque,3 for peek,4 for display and 5 for exiting:\n");
        scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                enque();


                break;
                case 2:
                deque();
                break;
                case 3:
                peek();
                break;

                case 4:

                display();
                break;
                case 5:
                printf("program exited..");
                default:
                printf("invalid input\n");
            }






            }
        }


