#include <stdio.h>
#include <stdlib.h>

int square(int);

int main()
{
    int num;

    printf("Enter a number:\n");
    scanf("%d", &num);

    printf("The square of the entered number is %d.", square(num));

    return 0;
}

int square(int num)
{
    return num * num;
}
