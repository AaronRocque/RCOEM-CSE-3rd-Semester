#include <stdio.h>
#include <stdlib.h>

int main()
{
    int var = 7;
    int *ptr = &var;
    int **ptr1 = &ptr;
    printf("%d\n", var);
    printf("%d\n", &var);
    printf("%d\n", ptr);
    printf("%d\n", *ptr);
    printf("%d\n", **ptr1);

    return 0;
}


