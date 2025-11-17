
#include<stdio.h>
#include<stdlib.h>
//creation of node
//step 1:making the outline of the node
int nodeCount;
typedef struct node {
    int data; //data stream
    struct node* next; //address stream
}node;
node *head=NULL; //making a head pointer point to null

//step 2:making the node and assigning memory

node* createNode() {
    node *newNode=(node*)malloc(sizeof(node)); //assigning memory of node to the outline of node
     if (newNode == NULL) {                       // VERY important check
        printf("Memory allocation failed!\n");
        exit(1);
    }
    int data;
    printf("enter data:");
    scanf("%d",&data);      //getting data from the user
    newNode->data=data;     //assigning data to the data stream
    newNode->next=NULL;     //assigning nothing to the address stream
    return newNode;         //very important as this is what is making sure the assigned memory can be accessed and modified by the other functions (ex:delete and insert)
}

//insertion of a node(1 for beginning,-1 for end,any number for that position)

void insert(int pos) {
    node* newNode=createNode();

    //insert at beginnning
    if(pos==1)
    {
        if(head==NULL) //LL is initially empty
        {
            head=newNode;
        }
        else //normal case where LL is partially filled
        {
            newNode->next=head;
            head=newNode;
        }
        nodeCount++;
        printf("insertion successful!\n");
    }

    //insert at end
    else if(pos==-1)
    {
        if(head==NULL) //LL is initially empty
        {
            head=newNode;
        }
        else //normal case where LL is partially filled
        {
            node* temp=head; //creating a temp variable for traversal

            //while loop for making the temp go to the current last node(before adding the last node)
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=NULL;  //since this is the last node therefore it will not store the address of any further node for now
        }
        nodeCount++;
        printf("insertion successful!\n");
    }

    //insert at any pos
    else
    {

        //case of user entering a valid position
        if(nodeCount!=0 && pos<=nodeCount+1 && pos>1)
        {
            node* prev; //declaration of a previous pointer;
            prev=head;
            //while loop for making previous pointer reach the previous node to initiate the connecting
            for(int i=1;i<=pos-2;i++)
            {
                prev=prev->next;

            }
            newNode->next=prev->next;
            prev->next=newNode;
            printf("insertion successful!\n");
            nodeCount++;
        }
        else
        {
            printf("invalid position!\n");
            return;
        }
    }
}

//displaying the LL

void display()
{
    node *temp;
    temp=head;
    //list being empty
    if(temp==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d ->",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}



//main function
int main()
{
    int pos,posd;
    int choice;
    while(1)
    {
        printf("---------MENU---------\n");
        printf("1.insert\n");
        printf("2.display\n");
        printf("3.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {

            case 1:
                printf("enter insert position(1,-1 or any pos):");
                scanf("%d",&pos);
                insert(pos);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("program exited.\n");
                exit(0);

            default:printf("invalid choice!");
        }
    }
}

