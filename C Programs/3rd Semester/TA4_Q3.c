//Write C program to find the middle of a given Linked List. 
//Given a singly linked list, find middle of the linked list. 
//For example, if given linked list is 1→2→3→4→5 then output should be 3. 
//If there are even nodes, then there would be two middle nodes, print second middle element. 
//For example, if given linked list is 1→2→3→4→5→6 then output should be 4.

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* create(struct node *, int);
struct node* insertEnd(struct node *, int);
int length(struct node**);
int middle(struct node*);

int main()
{
    int n, mid;
    struct node* head = 0;

    printf("How many nodes do you want?\n");
    scanf("%d", &n);

    head = create(head, n);

    mid = middle(head);

    printf("The middle element of your linked list is %d", mid);
    
    return 0;
}

struct node* create(struct node* head, int n)
{
    struct node *newNode, *temp;
    head = 0;
    int choice = 1;

    for(int i=0; i<n; i++)
    {
        newNode = (struct node*) malloc (sizeof(struct node));

        printf("Enter Data:\n");
        scanf("%d", &newNode -> data);
        newNode -> next = 0;

        if(head == 0)
        {
            head = temp = newNode;
        }
        else
        {
            temp -> next = newNode;
            temp = newNode;
        }

    }

    return head;
}

int length(struct node **head)
{
    struct node *newNode, *temp;
    int count=0;

    temp = *head;

     if(*head == 0)
    {
        printf("The linked list is empty.\n");
    }
    else
    {
            while(temp != 0)
        {
            count++;
            temp = temp -> next;
        }

    }

    return count;
}

int middle(struct node* head)
{
    if(head == 0)
    {
        printf("Your Linked List is empty.\n");
    }

    int index = 0;
    int l = length(&head);

    while(index != (l/2))
    {
        head = head -> next;
        index++;
    }

    return head -> data;
}