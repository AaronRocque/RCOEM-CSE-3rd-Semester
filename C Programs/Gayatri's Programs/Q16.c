#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, sum = 0;

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

    for(int i=0; i<n; i++)
    {
        sum = sum + array[i];
    }

    printf("The sum of the elements of the array is %d.\n", sum);

    return 0;
}