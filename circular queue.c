    #include<stdio.h>
    #define N 3
    int f=-1;
    int r=-1;
    int cqueue[N];
    int deque()
    {
        //empty case
        if(f==-1)
        {
            return -1;
        }
        //single element case
        else if(f==r)
        {
            int ele=cqueue[f];
            f=r=-1;
            return ele;
        }
        //partially full case
        else{
            int ele= cqueue[f];
            f=(f+1)%N;
            return ele;
        }
    }
    void enque(int item)
    {
        //empty case
        if(f==-1)
        {
            f=r=0;
            cqueue[r]=item;
        }
        else if(f==(r+1)%N)
        {
            printf("queue overflow\n");
        }
        else{
            r=(r+1)%N;
            cqueue[r]=item;
        }
    }
    void display()
    {
        if(f==-1)
        {
            printf("queue is empty\n");
        }
        else{
            for(int i=f;i!=r;i=(i+1)%N)
            {
                printf("%d\t",cqueue[i]);

            }
            printf("%d\n",cqueue[r]);
        }
    }

    void main()
    {
        int  choice=0;
        while(1)
        {
            printf("enter 1 for enque,2 for deque,3 for display,4 for exit:\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                    printf("enter the integer to be inserted:\n");
                    int item;
                    scanf("%d",&item);
                    enque(item);
                    break;
                case 2:
                    {


                    int DelElement=deque();
                    if(DelElement==-1)
                    {
                    printf("queue is empty\n");
                    }
                    else{
                    printf("element deleted:%d\n",DelElement);
                    }
                    break;
                    }
                case 3:
                    display();
                    break;
                case 4:
                    exit(0);
                default:
                    printf("invalid input");
            }
        }
    }
