/*Write a program to insert a new node after nth node*/


#include<stdio.h>
#include<stdlib.h>


// Define the structure of a node
struct node
{
    int data;
    struct node *next;
};
struct node *start=0;

struct node *createNode(int value)
{
  struct node*newNode;
  newNode= (struct node*)malloc(sizeof(struct node));  //memory allocation
  newNode->data=value;
  newNode->next=NULL;
  return newNode;
}

void insertEnd(int value)
{
 struct node *temp,*last;
 temp=createNode(value);            // Create a new node with the input value

 if (start==0)
 {
    start=temp;
 }
 else{
    last=start;
    while(last->next != 0)
    {
        last=last->next;
    }
    last->next=temp;
 }
}

void insertAfterNnode(int n,int value)  //function for inserting node after nth node
{

   struct node* temp=start;
   struct node*newnode;

   for(int i=1;i<n &&temp!=NULL;i++)
   {
    temp=temp->next;
   }
   if(temp==NULL)
   {
    printf("The list has fewer than %d nodes.\n",n);
   }
   else{
    newnode=createNode(value);
    newnode->next=temp->next;
    temp->next=newnode;
    printf("node inserted after node %d \n",n);

   }
}

void printList()    //function for printing 
{
    struct node*temp;
    if(start==0)
    {
        printf("List is empty.");
    }
    else{
        temp=start;
        printf("Linked list :");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

int main()    //main function
{
    int number,value,position;

    printf("Enter the number of elements :");
    scanf("%d",&number);

    for(int i=0;i<number;i++)
    {
        printf("Enter data for node %d:",i+1);
        scanf("%d",&value);

        insertEnd(value);
    }
    printList();          //calling printlist function

    
    printf("\nEnter position after which you want to insert :");
    scanf("%d",&position);
    printf("Enter data to new node :");
    scanf("%d",&value);

    insertAfterNnode(position,value);     // Insert the new node after the nth node


    printList();   //function for printing

return 0;
}

