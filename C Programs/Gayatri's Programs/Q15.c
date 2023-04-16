#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);

    int array[n];

    for(int i=0; i<n; i++)
    {
        printf("Enter a nummber: \n");
        scanf("%d", &array[i]);
    }

    printf("The array is as follows: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");

    printf("The array displayed in reverse order is as follows: \n");
    for(int i=(n-1); i>=0 ; i--)
    {
        printf("%d\t", array[i]);
    }

    return 0;
}