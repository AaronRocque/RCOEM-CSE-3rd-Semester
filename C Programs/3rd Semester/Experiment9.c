#include <stdio.h>
#include <stdlib.h>


void bfs(int n, int G[][n], int visited[], int x);
void dfs(int n, int G[][n], int visited[], int x);


int main()
{
    int node, i, j, n, sortChoice;

    printf("Enter the number of nodes:\n");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter the Adjacency Matrix: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\n");

    /*int node, n=7, sortChoice;
 
    int matrix[7][7] = {
        {0,1,0,0,0,0,0},
        {1,0,1,0,0,0,0},
        {0,1,0,1,0,0,0},
        {0,0,1,0,1,1,0},
        {0,0,0,1,0,0,0},
        {0,0,0,1,0,0,1}, 
        {0,0,0,0,0,0,1} 
    };*/

    printf("The Adjancency Matrix is:\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    while(1)
    {
        int *visited, x;
        visited = (int *)calloc(n, sizeof(int));

        printf("Which of the following do you want to execute?\n");
        printf("Enter 1 for BFS.\n");
        printf("Enter 2 for DFS.\n");
        printf("Enter 3 for EXIT.\n");
        scanf("%d", &sortChoice);

        switch(sortChoice)
        {
            case 1:
            printf("BFS\n");
            printf("Enter the number you want to start the traversal with:\n");
            scanf("%d", &x);
            bfs(n, matrix, visited, x);
            break;

            case 2:
            printf("DFS\n");
            printf("Enter the number you want to start the traversal with:\n");
            scanf("%d", &x);
            dfs(n, matrix, visited, x);
            break;

            case 3:
            printf("EXIT\n");
            exit(0);
            break;

            default:
            printf("INVALID INPUT!\n");
            break;

        }
    }

    return 0;
}

void bfs(int n, int G[][n], int visited[], int x)
{
    int front = -1, rear = -1, q[100], vcount=0;

    printf("%d\t", x);

    visited[x] = 1;
    front += 1;
    rear += 1;
    q[rear] = x;
    q[front] = x;

    while(front <= rear)
    {
        x = q[front];
        front += 1;
        vcount = 0; 

        while(vcount < n)
        {
            if(G[x][vcount] && visited[vcount]!=1)
            {
                visited[vcount] = 1;
                printf("%d\t", vcount);
                rear += 1;
                q[rear] = vcount;
            }

            vcount += 1;
        } 

    }

    printf("\n");
}

void dfs(int n, int G[][n], int visited[], int x)
{
    printf("%d\t", x);

    visited[x] = 1;
    
    for(int vcount = 0; vcount < n; vcount++)
    {
        if(G[x][vcount]==1 && visited[vcount] != 1)
        {
            dfs(n, G, visited, vcount);
        }
    }
}