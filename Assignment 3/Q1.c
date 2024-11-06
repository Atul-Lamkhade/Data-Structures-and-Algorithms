/*Write a program to create a Linked list with n elements. */

#include<stdio.h>
#include<stdlib.h>
struct node          
{
    int data;                  
    struct node *next;
};
struct node *start=0;

struct node *createNode(int value)    //function for creating node
{
  struct node*newNode;
  newNode= (struct node*)malloc(sizeof(struct node));  //memory allocation
  newNode->data=value;
  newNode->next=NULL;
  return newNode;
}

void insertEnd(int value)      //function for inserting in end
{
 struct node *temp,*last;
 temp=createNode(value);
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

void printList()         //function for printing the list
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

int main()          //main function
{
    int number,value;

    printf("Enter the number of elements :");
    scanf("%d",&number);

    for(int i=0;i<number;i++)
    {
        printf("Enter data for node %d:",i+1);
        scanf("%d",&value);

        insertEnd(value);   //calling the inserting function
    }

    printList();
return 0;
}