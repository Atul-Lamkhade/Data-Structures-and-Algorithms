/*Implement stack using arrays */


#include<stdio.h>
#define MAX_SIZE 10    //defining max size to 10

int stack[MAX_SIZE];
int top = -1;           //initializing top=-1
int x;

void push()    //function for inserting in stack
{
    if(top == MAX_SIZE-1)
    {
        printf("Stack is full\n");
    }
    else{
        
        printf("Enter the element to push in stack :");
        scanf("%d",&x);
        stack[++top]=x;     //pushing value to stack
    }
}

void pop()       //function for deleting from stack
{
    if(top == -1)
    {
        printf("There is no element to pop.\n");
    }
    else{
        printf("%d popped from the stack.\n", stack[top]);
    top--;
    }
}

void Top()     //function for finding top most means lastly inserted element
{
  if(top==-1)
    {
        printf("Stack is empty.\n");
    }
   else{
    printf("Top most element of stack is %d.\n",stack[top]);
   }  
}

int IsEmpty()       //function for checking stack is empty or not
{
    return top==-1;
    
}

void print()       //function for printing the stack
{
    if(top==-1)
    {
        printf("Stack is empty.\n");
    }else{

    printf("Stack :");
    for(int i=0;i<=top;i++)
    {                                //loop for printing element
        printf("%d ",stack[i]);
    }
   printf("\n") ;
    }
}


int main()    //main function
{
    int choice;

    do {
        printf("-------Menu------\n");                //menu driven choices
        printf("1 : Push element in stack\n");
        printf("2 : pop element from stack\n");
        printf("3 : Top element in stack\n");
        printf("4 : check stack is empty\n");
        printf("5 : Print elements of stack\n");
        printf("6 : Exit\n");

        printf("Enter your choice: ");  //ask user to inter choice
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
             push();   //function for inserting in stack
              
             break;

            case 2:
             pop() ;   //function for deleting from stack
             break;

            case 3:
            Top();      //function for finding top most means lastly inserted element
            break;

            case 4:
              if (IsEmpty())       //function for checking stack is empty or not
              {
                    printf("Stack is empty.\n");
              }
              else
              {
                    printf("Stack is not empty.\n"); 
              }
              break;

            case 5:
            print();    //function for printing the stack
            break;

            case 6:
            printf("Exiting the program...\n");
            break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);   //function will stop executing again and again after user gives 6
                             //comes out of the function


return 0;
}