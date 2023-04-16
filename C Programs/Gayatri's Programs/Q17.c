#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);

    int array[n];
    int copy[n];

    for(int i=0; i<n; i++)
    {
        printf("Enter a nummber: \n");
        scanf("%d", &array[i]);
    }

    printf("The original array is as follows: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");

    for(int i=0; i<n; i++)
    {
        copy[i] = array[i];
    }

    printf("The copied array is as follows: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d\t", copy[i]);
    }

    return 0;
}