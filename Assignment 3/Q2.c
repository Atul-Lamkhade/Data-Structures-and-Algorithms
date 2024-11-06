/*Write a program to print the elements in a link list. */

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

void insertEnd(int value)   //function for inserting
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

void printList()      //function for printing the linked list
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

int main() {
    struct node* head =NULL;  
    insertEnd(10);
    insertEnd(20);       //passing the values and calling inserting function
    insertEnd(30);
    insertEnd(40);

    printList(head);     //function for printing list

    return 0;
}