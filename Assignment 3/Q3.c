/*Write a program to insert a new node at the end to the linked list.  */


#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
// Define the structure of a node
struct node *start =0; 
struct node * createNode()
{
   struct node *head;
   head =(struct node *)malloc(sizeof(struct node));    //memory allocation
   printf("Enter the Data :");
   scanf("%d",&head->data);

   head->next=0;

   return head;
}
void print()
{
    struct node *temp;
    
        temp=start;
        printf("Linked list :");
        while(temp!=0)
        {
            printf("%d",temp->data);
            temp=temp->next;
        }
    
}
int main()
{
    struct node *temp ,*last;
     temp=createNode();

     if(start=0)
     {
        start=temp;
     }
     else{
        last=start;
        while(last->next!=0)
        {
            last=last->next;
        }
        last->next=temp;
     }

     print(); 
 return 0;   
}