#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};


struct node* create(struct node*,int);
void traversal(struct node**);
struct node* insertBeginning(struct node*, int);
struct node* insertEnd(struct node*, int);
struct node* insertPosition(struct node*, int, int);
int length(struct node**);
struct node* insertOrder(struct node*, int);
struct node* concatenate(struct node*, struct node*);
struct node* deleteBeginning(struct node*);
struct node* deleteEnd(struct node*);
struct node* deletePosition(struct node*, int);
struct node* copy(struct node*);
struct node* reverse(struct node*);
void search(struct node*, int);
struct node* sort(struct node*);


int main()
{
    int sortChoice, check=1, inputChoice, count, num, pos, n;
    struct node *head=0, *b=0, *copyHead=0;

    while(1)
    {
            printf("Which operation do you want to perform?\n");
            printf("Enter 1 for Creation.\n");
            printf("Enter 2 for Insertion. \n");
            printf("Enter 3 for Traversal. \n");
            printf("Enter 4 for Length.\n");
            printf("Enter 5 for Concatenation.\n");
            printf("Enter 6 for Deletion.\n");
            printf("Enter 7 for Copy.\n");
            printf("Enter 8 for Reverse.\n");
            printf("Enter 9 for Sorting.\n");
            printf("Enter 10 for Searching.\n");
            printf("Enter 11 for Stack Operations.\n");
            printf("Enter 12 for Queue Operations.\n");
            printf("Enter 13 for Exit.\n");
            scanf("%d", &sortChoice);
            switch(sortChoice)
            {
                case 1:
                printf("Creation:\n");
                //struct node *head;
                printf("How many nodes do you want?\n");
                scanf("%d", &n);
                head = create(head, n);
                break;

                case 2:
                while(check == 1)
                {
                    printf("Insertion:\n");
                    printf("Where do you want to insert?\n");
                    printf("Enter 1 for insertion at the beginning.\n");
                    printf("Enter 2 for insertion at the end.\n");
                    printf("Enter 3 for insertion at a specific position.\n");
                    printf("Enter 4 for insertion in an ordered linked list.\n");
                    printf("Enter 5 for displaying the linked list.\n");
                    printf("Enter 6 for Exit.\n");
                    scanf("%d", &inputChoice);

                    switch(inputChoice)
                    {
                        case 1:
                        printf("Insertion at beginning:\n");
                        //insertBeginning(&head);
                        printf("Enter number you want to insert:\n");
                        scanf("%d", &num);
                        head = insertBeginning(head, num);
                        break;

                        case 2:
                        printf("Insertion at end:\n");
                        printf("Enter the number you want to insert:\n");
                        scanf("%d", &num);
                        head = insertEnd(head, num);
                        break;

                        case 3:
                        printf("Insertion at a specific position:\n");
                        count = length(&head);
                        printf("Enter the position:\n");
                        scanf("%d", &pos);
                        if(pos > count)
                        {
                            printf("Invalid Position!\n");
                            break;
                        }
                        else
                        {
                            printf("Enter the number you want to insert:\n");
                            scanf("%d", &num);
                            head = insertPosition(head, pos, num);
                            break;
                        }

                        case 4:
                        printf("Insertion in an ordered linked list:\n");
                        printf("Enter the number you want to insert:\n");
                        scanf("%d", &num);
                        head = insertOrder(head, num);
                        break;

                        case 5:
                        printf("Traversal\n");
                        traversal(&head);
                        break;

                        case 6:
                        check = 0;
                        break;

                        default:
                        printf("Invalid Input:\n");
                        break;

                    }
                }
                check = 1;
                break;

                case 3:
                printf("Traversal\n");
                traversal(&head);
                break;

                case 4:
                printf("Length:\n");
                count = length(&head);
                printf("The length of the list is %d.\n", count);
                break;

                case 5:
                printf("Concatenation:\n");
                printf("Enter details for the other linked list.\n");
                printf("How many nodes do you want?\n");
                scanf("%d", &n);
                b=create(head, n);
                head = concatenate(head, b);
                break;

                case 6:
                check = 1;
                while(check == 1)
                {
                    printf("Deletion:\n");
                    printf("Enter 1 for deletion at the beginning.\n");
                    printf("Enter 2 for deletion at the end.\n");
                    printf("Enter 3 for deletion of a specific position.\n");
                    printf("Enter 4 for displaying the linked list.\n");
                    printf("Enter 5 for Exit.\n");
                    scanf("%d", &inputChoice);

                    switch(inputChoice)
                    {
                        case 1:
                        printf("Deletion at beginning:\n");
                        head = deleteBeginning(head);
                        break;

                        case 2:
                        printf("Deletion at end:\n");
                        head = deleteEnd(head);
                        break;

                        case 3:
                        printf("Deletion at a specific position:\n");
                        count = length(&head);
                        printf("Enter the position:\n");
                        scanf("%d", &pos);
                        if(pos > count)
                        {
                            printf("Invalid Position!\n");
                            break;
                        }
                        else
                        {
                            head = deletePosition(head, pos);
                            break;
                        }

                        case 4:
                        printf("Traversal\n");
                        traversal(&head);
                        break;

                        case 5:
                        check = 0;
                        break;

                        default:
                        printf("Invalid Input:\n");
                        break;

                    }
                }
                check = 1;
                break;

                case 7:
                printf("Copy:\n");
                copyHead = copy(head);
                traversal(&copyHead);
                break;

                case 8:
                printf("Reverse:\n");
                head = reverse(head);
                traversal(&head);
                break;

                case 9:
                printf("Sorting:\n");;
                head = sort(head);
                traversal(&head);
                break;

                case 10:
                printf("Searching:\n");
                printf("Enter the number you want to search for:\n");
                scanf("%d", &num);
                search(head, num);
                break;

                case 11:
                check = 1;
                head = 0;
                while(check == 1)
                {
                    printf("Stack Operations:\n");
                    printf("Enter 1 for Push.\n");
                    printf("Enter 2 for Pop.\n");
                    printf("Enter 3 for Top Value.\n");
                    printf("Enter 4 for Display.\n");
                    printf("Enter 5 for Exit.\n");
                    scanf("%d", &inputChoice);

                    switch(inputChoice)
                    {
                        case 1:
                        printf("Push:\n");
                        printf("Enter number you want to insert:\n");
                        scanf("%d", &num);
                        head = insertBeginning(head, num);
                        break;

                        case 2:
                        printf("Pop:\n");
                        head = deleteBeginning(head);
                        break;

                        case 3:
                        printf("Top Value:\n");
                        if(head == 0)
                        {
                            printf("The stack is empty!\n");
                        }
                        else
                        {
                            printf("The top value is, %d\n", head -> data);
                        }
                        break;
                       
                        case 4:
                        printf("Traversal:\n");
                        traversal(&head);
                        break;

                        case 5:
                        check = 0;
                        break;

                        default:
                        printf("Invalid Input:\n");
                        break;

                    }
                }
                check = 1;
                break;

                case 12:
                check = 1;
                head = 0;
                while(check == 1)
                {
                    printf("Queue Operations:\n");
                    printf("Enter 1 for Insertion.\n");
                    printf("Enter 2 for Deletion.\n");
                    printf("Enter 3 for Display.\n");
                    printf("Enter 4 for Exit.\n");
                    scanf("%d", &inputChoice);

                    switch(inputChoice)
                    {
                        case 1:
                        printf("Insertion:\n");
                        printf("Enter number you want to insert:\n");
                        scanf("%d", &num);
                        head = insertEnd(head, num);
                        break;

                        case 2:
                        printf("Deletion:\n");
                        head = deleteBeginning(head);
                        break;
                       
                        case 3:
                        printf("Traversal:\n");
                        traversal(&head);
                        break;

                        case 4:
                        check = 0;
                        break;

                        default:
                        printf("Invalid Input:\n");
                        break;

                    }
                }
                check = 1;
                break;


                case 13:
                exit(0);
                break;

                default:
                printf("Invalid Input:\n");
                break;
            }

    }

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
            printf("%d | %ld -> ", temp -> data, temp -> next);
            temp = temp -> next;
        }

        printf("\n");

    }
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


struct node* insertBeginning(struct node *head, int num)
{
    struct node *newNode;

    newNode = (struct node*) malloc (sizeof(struct node));

    newNode-> data = num;

    if(head == 0)
    {
        newNode -> next = 0;
        head = newNode;
    }
    else
    {
        newNode -> next = head;
        head = newNode;
    }

    return head;
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

struct node* insertPosition(struct node *head, int pos, int num)
{
    struct node *newNode, *temp;
    int i=0;

        temp = head;
        
        while(i<pos-1)
        {
            temp = temp -> next;
            i++;
        }

        newNode = (struct node*) malloc (sizeof (struct node));
        newNode-> data = num;

        newNode -> next = temp -> next;
        temp -> next = newNode;

        return head;
    
}

struct node* insertOrder(struct node *head, int num)
{
     struct node *newNode, *temp;

    newNode = (struct node*) malloc (sizeof(struct node));

    newNode-> data = num;

    if(head == 0)
    {
        newNode -> next = 0;
        head = newNode;
        return head;
    }

    if((head -> data) >= (newNode -> data))
    {
        newNode -> next = head;
        return newNode;
    }

    temp = head;

    while(((temp -> next) != 0) && ((temp -> next -> data) <= (newNode -> data)))
    {
        temp = temp -> next;
    }

    newNode -> next = temp -> next;
    temp -> next = newNode;

    return head;
}

struct node* concatenate(struct node* a, struct node* b)
{
    if(a != 0 && b != 0)
    {
        if(a -> next == 0)
        {
            a -> next = b;
        }
        else
        {
            concatenate(a -> next, b);
        }

        return a;
    }
    else
    {
        printf("The linked list is empty!\n");
        return a;
    }  
}

struct node* deleteBeginning(struct node *head)
{
    struct node *temp;

    if(head == 0)
    {
        printf("The list is EMPTY! Deletion is not possible.\n");
        return head;
    }
    else
    {
        temp = head;
        head = head -> next;
        printf("The deleted node had the element %d.\n", temp -> data);
        free(temp);

        return head;

    }

    
}

struct node* deleteEnd(struct node* head)
{
    struct node *prevnode, *temp;

    if(head == 0)
    {
        printf("The list is EMPTY! Deletion is not possible.\n");
        return head;
    }
    else
    {
        temp = head;

    while(temp -> next != 0)
    {
        prevnode = temp;
        temp = temp -> next;
    }
    
    if(temp == head)
    {
        head = 0;
    }
    else
    {
        prevnode -> next = 0;
    }

    printf("The deleted node had the element %d.\n", temp -> data);

    free(temp);

    return head;
    }

    

}

struct node* deletePosition(struct node* head, int pos)
{
    struct node *temp, *nextnode;
    int i=1;

    if(head == 0)
    {
        printf("The list is EMPTY! Deletion is not possible.\n");
        return head;
    }
    else
    {
        temp = head;
    
    while(i < pos-1)
    {
        temp = temp -> next;
        i++;
    }
    nextnode = temp -> next;
    temp -> next = nextnode-> next;

    printf("The deleted node had the element %d.\n", nextnode -> data);

    free(nextnode);

    return head;
    }

    
}

struct node* copy(struct node* head)
{
    struct node* b = 0;

    while(head != 0)
    {
        b = insertEnd(b, head -> data);
        head = head -> next;
    }

    return b;
}

struct node* reverse(struct node *head)
{
    struct node *previousNode, *currentNode, *nextNode;
    
    previousNode = 0;
    currentNode = nextNode = head;

    while(nextNode != 0)
    {
        nextNode = nextNode -> next;
        currentNode -> next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }

    head = previousNode;

    return head;
}

void search(struct node* head, int num)
{
    struct node *temp = head;
    int pos = 0, check = 0;

    while(temp != 0)
    {
        if(temp -> data == num)
        {
            printf("Number is found at position %d.\n", pos+1);
            check = 1;
        }

        temp = temp -> next;
        pos++;
    }

    if(temp == 0 && check == 0)
    {
        printf("Number not found!\n");
    }
}

struct node* sort(struct node *head)
{
    struct node *a, *b;
    int temp;

    if(head == 0)
    {
        printf("The linked list is empty.\n");
        return head;
    }
    else
    {
        a  = head;

        while(a -> next != 0)
        {
            b = a -> next;

            while(b != 0)
            {
                if(a -> data > b -> data)
                {
                    temp = a -> data;
                    a -> data = b -> data;
                    b -> data = temp;
                }

                b = b -> next;
            }

            a = a -> next; 
        }


    }

    return head; 

}