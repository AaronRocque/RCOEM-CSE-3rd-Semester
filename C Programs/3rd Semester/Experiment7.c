#include <stdio.h>
#include <stdlib.h>

struct btnode
{
struct btnode* left; 
int data;
struct btnode* right;
};
typedef struct btnode Tree;

void Inorder_traversal(Tree *root);
void preorder_traversal(Tree *root);
void postorder_traversal(Tree *root);
void levelorder_traversal(Tree *root);
void nodes_level(Tree* root,int level);
int height(Tree *root);
int total_nodes(Tree *root);
int leaf_nodes(Tree *root);
int half_nodes(Tree *root);
int non_leaf_nodes(Tree *root);
void creation(Tree *root, int a[] , int n );
Tree* insert(Tree *root, int val);
Tree* create(int val);
void search(Tree *root, int val);
Tree* delete(Tree *root, int val);
Tree* largest_element(Tree *root);
Tree* smallest_element(Tree *root);

int main()
{
    int sortChoice, data, n;
    Tree* root = 0; 

    while(1)
    {
        printf("Which operation do you want to perform?\n");
        printf("Enter 1 for Insert operation.\n");
        printf("Enter 2 for Delete operation.\n");  
        printf("Enter 3 for Height.\n");
        printf("Enter 4 for Traversal operation.\n");
        printf("Enter 5 for Search operation.\n");
        printf("Enter 6 for Counting of nodes.\n");
        printf("Enter 7 for EXIT.\n");
        scanf("%d", &sortChoice);
        switch(sortChoice)
        {
            case 1:
            printf("Insertion:\n");
            printf("Enter the data you want to insert\n");
            scanf("%d",&data);
            root = insert(root, data);
            break;

            case 2:
            printf("Deletetion:\n");  
            printf("Enter the data you want to delete\n");
            scanf("%d",&data);
            root = delete(root, data);
            break;

            case 3:
            printf("Height:\n");
            int ht  = height(root);
            printf("The height of the tree is %d.\n", ht);
            break;

            case 4:
            printf("Traversal:\n");
            int choice2, check = 1;
            while(check == 1)
            {
                printf("\nHow do you want to traverse?\n");
                printf("Enter 1 to Inorder traversal.\n");
                printf("Enter 2 to Preorder traversal .\n");
                printf("Enter 3 to Postorder traversal.\n");
                printf("Enter 4 to Level order traversal.\n");
                printf("Enter 5 to Exit.\n");
                scanf("%d",&choice2);
                switch (choice2)
                {
                case 1:
                printf("Inorder traversal:\n "); 
                Inorder_traversal(root); 
                break;
                
                case 2:
                printf("Preorder traversal:\n ");
                preorder_traversal(root);
                break;

                case 3:
                printf("Postorder traversal:\n "); 
                postorder_traversal(root);
                break;

                case 4:
                printf("Level order traversal:\n ");
                levelorder_traversal(root);
                break;

                case 5:
                //printf("EXIT\n");
                check = 0;
                break;

                default:
                printf("Invalid Input\n");
                break;
                }
            }
            check = 1;
            break;

            case 5:
            printf("Search:\n");
            int val;
            if(root == NULL)
            {
                printf("The tree is empty.\n");
                break;
            }
            printf("Which node do you want to search for?\n");
            scanf("%d",&val);
            search(root,val);
            break;

            case 6:
            printf("Counting of nodes:\n");
            int choice3 ,check1 = 1;
            while(check1 == 1)
            {
            printf("Which nodes do you want to count?\n");
            printf("Enter 1 to Leaf nodes.\n");
            printf("Enter 2 to Parent nodes.\n");
            //printf("Enter 3 to Parent nodes.\n");
            printf("Enter 3 to All nodes.\n");
            printf("Enter 4 to Exit.\n");
            scanf("%d",&choice3);
            switch (choice3)
            {
            case 1:
            printf("Total number of Leaf nodes : %d\n",leaf_nodes(root));
            break;

            case 2:
            printf("Total number of Parent nodes : %d\n",non_leaf_nodes(root));
            break;

            /*case 3:
            printf("Parent nodes\n");
            break;*/

            case 3:
            printf("All nodes\n");
            printf("Total number of nodes : %d\n",total_nodes(root));
            break;

            case 4:
            printf("EXIT\n");
            check1 = 0;
            break;
            
            default:
            printf("Invalid Input\n");
            break;
            }
            } 
            check1 = 1;
            break;

            case 7:
            printf("EXIT!\n");
            exit(0);
            break;

            default:
            printf("Invalid Input:\n");
            break;
        }

    }

    

    return 0; 
}

Tree* insert(Tree* root, int val)
{
    if(root == NULL)
    {
        root = create(val);
        root -> data = val;
        root -> left = root -> right = NULL;
        return root;
    }
    else
    {
        if(val < root -> data)
        {
            root -> left = insert(root -> left, val);
        }
        else
        {
            root -> right = insert(root -> right, val);
        }   
    }

    return root;
}

Tree* create(int val)
{
    Tree* temp;

    temp = (Tree *)malloc(sizeof(Tree));

    if(temp == NULL)
    {
        printf("Node not created!\n");
        return NULL;
    }
    else
    {
        printf("Node Created!\n");
        temp->left = NULL;
        return temp;
    }
}

void Inorder_traversal(Tree* root)
{
    if(root == NULL)
    {
        printf("The tree is EMPTY!\n");
        return;
    }
    else
    {
        if(root -> left != NULL)
        {
            Inorder_traversal(root -> left);
        }
        printf(" %d |", root -> data);
        if(root -> right != NULL)
        {
            Inorder_traversal(root -> right);
        }
    }
}
void preorder_traversal(Tree *root)
{
    if(root == NULL)
    {
        printf("The tree is empty!\n");
        return;
    }
    else
    {
        printf(" %d |", root -> data);
        if(root->left!= NULL)
            preorder_traversal(root->left); 
        if(root->right!= NULL)
            preorder_traversal(root->right);
    }
}

void postorder_traversal(Tree *root)
{
    if(root == NULL)
    {
        printf("The tree is empty!\n");
        return;
    }
    else
    {
        if(root -> left != NULL)
        {
            postorder_traversal(root->left);
        }
        if(root -> right != NULL)
        {
            postorder_traversal(root->right); 
        }
        printf(" %d |", root -> data);
    }
}

void levelorder_traversal(Tree *root)
{
    int level = 0;
    int h = height(root);

    if(root == NULL)
    {
        printf("The tree is empty.\n");
        return;
    }
    else
    {
        while(level <= h)
        {
            nodes_level(root, level);
            level = level + 1;
        }
    }
}

int height(Tree *root)
{
    if(root == NULL)
    {
        return -1;
    }

    if(root -> left == NULL && root -> right == NULL)
    {
        return 0;
    }
    else
    {
        int leftht = height(root -> left);
        int rightht = height(root -> right);

        if(leftht > rightht)
        {
            return leftht+1;
        }
        else
        {
            return rightht+1;
        }
    }
}


void search(Tree *root, int val)
{
    Tree* temp = root; 
    if(root == NULL)
    {
        printf("NOT FOUND!\n");
        return;
    }
    if(temp -> data == val)
    {
        printf("FOUND!\n");
        return;
    }
    else
    {
        if(val < temp -> data)
        {
            return search(temp -> left, val);
        }
        else
        {
            return search(temp -> right, val);
        }

    }
}

void nodes_level(Tree *root, int level)
{
    if(root != NULL)
    {
        if(level == 0)
        {
            printf(" %d |", root -> data);
        }
        else
        {
            nodes_level(root->left,level-1);
            nodes_level(root->right,level-1);
        }
    }
}

int total_nodes(Tree *root)
{
    if(root == NULL)
    {
        return 0;
    }
    
    return 1+total_nodes(root->left)+total_nodes(root->right); 
}

int leaf_nodes(Tree *root)
{
    if(root == NULL)
    {
        return 0;
    }
    
    if(root -> left == NULL && root -> right == NULL)
    {
        return 1;
    }
    else
    {
        return leaf_nodes(root->left)+leaf_nodes(root->right);
    }
}

int half_nodes(Tree *root)
{
    int temp=0;

    if((root->left==NULL && root->right!=NULL)||(root -> left!=NULL && root->right==NULL))
    {
        temp = 1;
    }

    int l=0, r=0;

    if(root -> left != NULL)
    {
        l = half_nodes(root -> left);
    }

    if(root -> right != NULL)
    {
         r = half_nodes(root -> right);
    }

    return temp + l + r;
}

int non_leaf_nodes(Tree *root)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root -> left == NULL && root -> right == NULL)
    {
        return 0;
    }
    else
    {
        return non_leaf_nodes(root->left)+non_leaf_nodes(root->right)+1;
    }
}

/*Tree* delete(Tree *root, int val)
{
    if(root == NULL)
    {
        printf("Deletion not possible! The tree is empty.\n");
        return root;
    }
    else if(val < root->data)
    {
        root->left = delete(root->left, val);
    }
    else if(val < root->data)
    {
        root->right = delete(root->right, val);
    }
    else
    {
        if(root->left && root->right)
        {
        Tree *temp = largest_element(root->left);
        root->data = temp->data;
        root->left = delete(root->left,temp->data);
        }
        else
        {
        Tree *temp = root;
        if(root->left == NULL && root->right == NULL)
        {
            root = NULL;
        }
        else if(root->left == NULL)
            root= root->right;
        else if(root->right == NULL)
            root= root->left;
        free(temp);
        }
    }
    return root;
}*/

Tree* delete(Tree *root, int val)
{
    if(root == NULL)
    {
        printf("Deletion not possible! The tree is empty.\n");
        return root;
    }
    
    if(val < root->data)
    {
        root->left = delete(root->left, val);
    }
    else if(val > root->data)
    {
        root->right = delete(root->right, val);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        
        else if(root->left == NULL)
        {
            Tree* temp = root->right;
            free(root);
            return temp;
        }
        
        else if (root->right == NULL) 
        {
            Tree* temp = root->left;
            free(root);
            return temp;
        }

        Tree* temp = smallest_element(root->right);

        root->data = temp->data;

        root->right = delete(root->right, temp->data);
    }
    return root;
}

Tree* largest_element(Tree *root)
{
  if(root == NULL || root->right == NULL)
  {
    return root;
  }
  else
  {
    return largest_element(root->right);
  }
}

Tree* smallest_element(Tree *root)
{
  if(root == NULL || root->left == NULL)
  {
    return root;
  }
  else
  {
    return smallest_element(root->left);
  }
}
