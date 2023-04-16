#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};


struct node* create(struct node*,int);
void traversal(struct node*);
struct node* insertEnd(struct node*, int);


int main()
{
    int n;
    struct node *head=0, *oddhead=0, *evenhead=0;
    struct node  *temp1, *temp2, *temp;

    printf("Creation:\n");
    printf("How many nodes do you want?\n");
    scanf("%d", &n);
    head = create(head, n);

    printf("Traversal original linked list:\n");
    traversal(head);

    temp = head;
    temp1 = oddhead;
    temp2 = evenhead;


            while(temp != 0)
        {
            if(temp->data % 2 == 0)
            {
                evenhead = insertEnd(evenhead, temp->data);
            }
            else
            {
                oddhead = insertEnd(oddhead, temp->data);
            }
            temp = temp -> next;
        }

    printf("Traversal odd linked list:\n");
    traversal(oddhead);

    printf("Traversal even linked list:\n");
    traversal(evenhead);



    return 0;
}

struct node* create(struct node *head, int n)
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

void traversal(struct node *head)
{
    struct node *newNode, *temp;

    temp = head;

    if(head == 0)
    {
        printf("The linked list is empty.\n");
    }
    else
    {
            while(temp != 0)
        {
            printf("%d | %ld -> ", temp -> data, temp -> next);
            temp = temp -> next;
        }

        printf("\n");

    }
}


struct node* insertEnd(struct node *head, int num)
{
    struct node *newNode, *temp;
 
    newNode = (struct node*) malloc (sizeof(struct node));
 
    newNode-> data = num;
 
    if(head == 0)
    {
        head = newNode;
        newNode -> next = 0;
        return head;
    }
 
    newNode -> next = 0;
    temp = head;
 
    while(temp -> next != 0)
    {
        temp = temp -> next;    
    }
 
    temp -> next = newNode;
 
    return head;
 
}

