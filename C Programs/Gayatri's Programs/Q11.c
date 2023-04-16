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

    int largest = array[0];

    for(int i=1; i<n; i++)
    {
        if(largest < array[i])
        {
            largest = array[i];
        }
    }

    printf("The largest element of the array is %d.", largest);

    return 0;
}