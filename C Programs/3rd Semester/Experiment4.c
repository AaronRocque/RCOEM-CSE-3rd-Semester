#include <stdio.h>
#include <stdlib.h>
 
void inputMenu(int* , int, int);
void push(int*, int, int*);
void pop(int*, int, int*);
void isEmpty(int*);
void isFull(int*, int);
void topValue(int*, int*);
void display(int*, int*);
void insert(int*, int, int*, int*);
void delete(int*, int, int*, int*);
void frontValue(int*, int*, int*);
void rearValue(int*, int*, int*);
void isEmptyQueue(int*, int*);
void isFullQueue(int*, int);
void displayQueue(int*, int*, int*);
void insertCircular(int*, int, int*, int*);
void deleteCircular(int*, int, int*, int*);
void rearValueCircular(int*, int*, int*, int);
void isFullCircularQueue(int*, int*, int);
void displayCircularQueue(int*, int*, int*, int);
 
 
int main()
{
    int sortChoice, inputChoice, n;
    int item;
 
    while(1)
    {
        printf("Which of the following sorting methods would you like to execute?\n");
        printf("Enter 1 for Stack.\n");
        printf("Enter 2 for Queue.\n");
        printf("Enter 3 for Circular Queue.\n");
        printf("Enter 4 for Exit. \n");
        scanf("%d", &sortChoice);
       
        switch(sortChoice)
        {
        case 1:
        printf("Stack:\n");
        printf("Enter the size of the stack:\n");
        scanf("%d", &n);
        int *stack;
        stack = (int *)calloc(n, sizeof(int));
        inputMenu(stack, n, sortChoice);
        break;
 
        case 2:
        printf("Queue:\n");
        printf("Enter the size of the Queue:\n");
        scanf("%d", &n);
        int *queue;
        queue = (int *)calloc(n, sizeof(int));
        inputMenu(queue, n, sortChoice);
        break;
 
        case 3:
        printf("Circular Queue:\n");
        printf("Enter the size of the Circular Queue:\n");
        scanf("%d", &n);
        int *circular;
        circular = (int *)calloc(n, sizeof(int));
        inputMenu(circular, n, sortChoice);
        break;
 
        case 4:
        exit(0);
        break;
 
        default:
        printf("Invalid Input! Try Again!\n");
        break;
 
        }
       
    }
   
    return 0;
}
 
void inputMenu(int a[],int n, int sortChoice)
{
    int inputChoice, check=1;
 
    int top = -1;
    int front = -1;
    int rear = -1;
 
    while(check == 1)
    {
        if(sortChoice == 1)
        {
            printf("Which operation do you want to perform?\n");
            printf("Enter 1 for Push.\n");
            printf("Enter 2 for Pop. \n");
            printf("Enter 3 for Top Value. \n");
            printf("Enter 4 for Is Empty.\n");
            printf("Enter 5 for Is Full.\n");
            printf("Enter 6 for Display.\n");
            printf("Enter 7 for Exit.\n");
            scanf("%d", &inputChoice);
            switch(inputChoice)
            {
                case 1:
                printf("Push:\n");
                push(a, n, &top);
                break;
 
                case 2:
                printf("Pop:\n");
                pop(a, n, &top);
                break;
 
                case 3:
                printf("Top Value:\n");
                topValue(a, &top);
                break;
 
                case 4:
                printf("Is Empty:\n");
                isEmpty(&top);
                break;
 
                case 5:
                printf("Is Full:\n");
                isFull(&top, n);
                break;
 
                case 6:
                printf("Display:\n");
                display(a, &top);
                break;
 
                case 7:
                check = 0;
                break;
 
                default:
                printf("Invalid Input:\n");
                break;
            }
        }
 
        else if(sortChoice == 2)
        {
            printf("Which operation do you want to perform?\n");
            printf("Enter 1 for Insert.\n");
            printf("Enter 2 for Delete. \n");
            printf("Enter 3 for Front Value. \n");
            printf("Enter 4 for Rear Value.\n");
            printf("Enter 5 for Is Empty.\n");
            printf("Enter 6 for Is Full.\n");
            printf("Enter 7 for Display.\n");
            printf("Enter 8 for Exit.\n");
            scanf("%d", &inputChoice);
            switch(inputChoice)
            {
                case 1:
                printf("Insert:\n");
                insert(a, n, &front, &rear);
                break;
 
                case 2:
                printf("Delete:\n");
                delete(a, n, &front, &rear);
                break;
 
                case 3:
                printf("Front Value:\n");
                frontValue(a, &front, &rear);
                break;
 
                case 4:
                printf("Rear Value:\n");
                rearValue(a, &front, &rear);
                break;
 
                case 5:
                printf("Is Empty:\n");
                isEmptyQueue(&front, &rear);
                break;
 
                case 6:
                printf("Is Full:\n");
                isFullQueue(&rear, n);
                break;
 
                case 7:
                printf("Display:\n");
                displayQueue(a, &front, &rear);
                break;
 
                case 8:
                check = 0;
                break;
 
                default:
                printf("Invalid Input:\n");
                break;
            }
 
        }
 
        else if(sortChoice == 3)
        {
            printf("Which operation do you want to perform?\n");
            printf("Enter 1 for Insert.\n");
            printf("Enter 2 for Delete. \n");
            printf("Enter 3 for Front Value. \n");
            printf("Enter 4 for Rear Value.\n");
            printf("Enter 5 for Is Empty.\n");
            printf("Enter 6 for Is Full.\n");
            printf("Enter 7 for Display.\n");
            printf("Enter 8 for Exit.\n");
            scanf("%d", &inputChoice);
            switch(inputChoice)
            {
                case 1:
                printf("Insert:\n");
                insertCircular(a, n, &front, &rear);
                break;
 
                case 2:
                printf("Delete:\n");
                deleteCircular(a, n, &front, &rear);
                break;
 
                case 3:
                printf("Front Value:\n");
                frontValue(a, &front, &rear);
                break;
 
                case 4:
                printf("Rear Value:\n");
                rearValueCircular(a, &front, &rear, n);
                break;
 
                case 5:
                printf("Is Empty:\n");
                isEmptyQueue(&front, &rear);
                break;
 
                case 6:
                printf("Is Full:\n");
                isFullCircularQueue(&front, &rear, n);
                break;
 
                case 7:
                printf("Display:\n");
                displayCircularQueue(a, &front, &rear, n);
                break;
 
                case 8:
                check = 0;
                break;
 
                default:
                printf("Invalid Input:\n");
                break;
            }
 
        }
    }  
}
 
void push(int stack[], int n, int *top)
{
    int item;
   
 
   printf("What element do you want to insert?\n");
   scanf("%d", &item);
 
    if(*top == n-1)
    {
        printf("Overflow!\nThe Stack is Full.\n");
    }
    else
    {
        *top = *top + 1;
        stack[*top] = item;
    }
 
}
 
void pop(int stack[], int n, int *top)
{
    int item;
 
    if(*top == -1)
    {
        printf("Underflow!\nThe Stack is Empty.\n");
    }
    else
    {
        item = stack[*top];
        *top-=1;
        printf("The popped elements is %d.\n", item);
    }
 
}
 
void isEmpty(int *top)
{
    if(*top == -1)
    {
        printf("Underflow!\nThe Stack is Empty.\n");
    }
    else
    {
        printf("The Stack is not Empty.\n");
    }
}
 
void isFull(int *top, int n)
{
    if(*top == n-1)
    {
        printf("Overflow!\nThe Stack is Full.\n");
    }
    else
    {
        printf("The Stack is not Full.\n");
    }
 
}
 
void topValue(int stack[], int *top)
{
    if(*top == -1)
    {
        printf("Underflow!\nThe Stack is Empty.\n");
    }
    else
    {
        printf("The value of top is %d.\n", stack[*top]);
    }
}
 
void display(int stack[], int *top)
{
    int i;
   
     if(*top == -1)
    {
        printf("Underflow!\nThe Stack is Empty.\n");
    }
    else
    {
        printf("The stack is as follows:\n");
        for(i=*top; i>=0; i--)
        {
            printf("%d", stack[i]);
            printf("\n");
        }
    }
}
 
void insert(int queue[], int n, int *front, int *rear)
{
    int item;
   
    printf("What element do you want to insert?\n");
    scanf("%d", &item);
 
    if(*rear == n-1)
    {
        printf("Overflow!\nThe Queue is Full.\n");
    }
    else if(*front == -1 && *rear == -1)
    {
        *front = 0;
        *rear = 0;
        queue[*rear] = item;
    }
    else
    {
        *rear+=1;
        queue[*rear] = item;
    }
}
 
void delete(int queue[], int n, int *front, int *rear)
{
    if(*front == -1 && *rear == -1)
    {
        printf("Underflow!\nThe Queue is Empty.\n");
    }
    else if(*front == *rear)
    {
        printf("The deleted elements is %d.\n", queue[*front]);
        *front = -1;
        *rear = -1;
    }
    else
    {
        printf("The deleted elements is %d.\n", queue[*front]);
        *front+=1;
    }
}
 
void frontValue(int queue[], int *front, int *rear)
{
    if(*front == -1 && *rear == -1)
    {
        printf("Underflow!\nThe Queue is Empty.\n");
    }
    else
    {
        printf("%d", queue[*front]);
    }
}
 
void rearValue(int queue[], int *front, int *rear)
{
    if(*front == -1 && *rear == -1)
    {
        printf("Underflow!\nThe Queue is Empty.\n");
    }
    else
    {
        printf("%d", queue[*rear]);
    }
}
 
void isEmptyQueue(int *front, int *rear)
{
   if(*front == -1 && *rear == -1)
   {
       printf("Underflow!\nThe Queue is Empty.\n");
   }
   else
   {
       printf("The Queue is not Empty.\n");
   }
}
 
void isFullQueue(int *rear, int n)
{
    if(*rear == n-1)
    {
        printf("Overflow!\nThe Queue is Full.\n");
    }
    else
    {
        printf("The Queue is not Full.\n");
    }
}
 
void displayQueue(int queue[], int *front, int *rear)
{
    if(*front == -1 && *rear == -1)
    {
        printf("Underflow!\nThe Queue is Empty.\n");
    }
    else
    {
        printf("The queue is as follows:\n");
        for(int i=*front; i<(*rear+1); i++)
        {
            printf("%d\t", queue[i]);
        }
        printf("\n");
 
    }
}
 
void insertCircular(int circular[], int n, int *front, int *rear)
{
    int item;
   
    printf("What element do you want to insert?\n");
    scanf("%d", &item);
 
    if(((*rear+1)%n) == *front)
    {
        printf("Overflow!\nThe Circular Queue is Full.\n");
    }
    else if(*front == -1 && *rear == -1)
    {
        *front = 0;
        *rear = 0;
        circular[*rear] = item;
    }
    else
    {
        *rear = ((*rear + 1) % n);
        circular[*rear] = item;
    }
}
 
void deleteCircular(int circular[], int n, int *front, int *rear)
{
    if(*front == -1 && *rear == -1)
    {
        printf("Underflow!\nThe Circular Queue is Empty.\n");
    }
    else if(*front == *rear)
    {
        printf("The deleted elements is %d.\n", circular[*front]);
        *front = -1;
        *rear = -1;
    }
    else
    {
        printf("The deleted elements is %d.\n", circular[*front]);
        *front = (*front + 1) % n;
    }
}
 
 
void rearValueCircular(int queue[], int *front, int *rear, int n)
{
    if(((*rear+1)%n) == *front)
    {
        printf("Overflow!\nThe Circular Queue is Full.\n");
    }
    else
    {
        printf("%d", queue[*rear]);
    }
}
 
 
void isFullCircularQueue(int *front, int *rear, int n)
{
    if(((*rear+1)%n) == *front)
    {
        printf("Overflow!\nThe Circular Queue is Full.\n");
    }
    else
    {
        printf("The Queue is not Full.\n");
    }
}
 
void displayCircularQueue(int circular[], int *front, int *rear, int n)
{
    int i = *front;
 
    if(*front == -1 && *rear == -1)
    {
        printf("Underflow!\nThe Circular Queue is Empty.\n");
    }
    else
    {
        printf("The queue is as follows:\n");
        while(i != *rear)
        {
            printf("%d\t", circular[i]);
            i = (i+1) % n;
        }
        printf("%d\n", circular[*rear]);
    }
}
