//Write C Program to implement Priority Queue using linked list.
//Modify base structure of Linked List by considering priority as a member. 
//Carry out insertion in ordered manner based on priority.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int priority;
    struct node* next;
};

struct node* insert(struct node*, int, int);
void traversal(struct node**);
struct node* delete(struct node*);


int main()
{
    int sortChoice, data, priority;
    struct node* head=0;

    while(1)
    {
        printf("Enter 1 for Insertion.\n");
        printf("Enter 2 for Deletion.\n");
        printf("Enter 3 for Traversal.\n");
        printf("Enter 4 for EXIT.\n");
        scanf("%d", &sortChoice);

        switch(sortChoice)
        {
            case 1:
            printf("Insertion:\n");
            printf("Enter the data:\n");
            scanf("%d", &data);
            printf("Enter its priority:\n");
            scanf("%d", &priority);
            head = insert(head, data, priority);
            break;

            case 2:
            printf("Deletion:\n");
            head = delete(head);
            break;

            case 3:
            printf("Traversal:\n");
            traversal(&head);
            break;

            case 4:
            printf("EXIT\n");
            exit(0);
            break;

            default:
            printf("Invalid Input! Try Again!\n");
            break;
        }
    }

    return 0;
}


struct node* insert(struct node* head, int num, int priority)
{   
    struct node *newNode, *temp;

    newNode = (struct node*) malloc (sizeof(struct node));

    newNode -> data = num; 
    newNode -> priority = priority; 

    if(head == 0 || priority < (head -> priority))
    {
        newNode -> next = head;
        head = newNode;
        return head;
    }
    else  
    {  
        temp = head; 

        while( temp -> next != 0 && temp -> next -> priority <= priority)
        {
            temp = temp -> next; 
        }  

        newNode -> next = temp -> next;  
        temp -> next = newNode;  
    }  

    return head;

}

void traversal(struct node **head)
{
    struct node *newNode, *temp;

    temp = *head;

    if(*head == 0)
    {
        printf("The linked list is empty.\n");
    }
    else
    {
            while(temp != 0)
        {
            printf("%d | %d -> ", temp -> data, temp -> priority);
            temp = temp -> next;
        }

        printf("\n");

    }
}

struct node* delete(struct node* head)
{
    struct node* temp;

    if(head == 0)
    {
        printf("Underflow!\nThe Queue is Empty.\n");
    }
    else
    {
        temp = head;
        head = head -> next;
        printf("The deleted elements is %d.\n", temp -> data);
        free(temp);
    }

    return head; 
}