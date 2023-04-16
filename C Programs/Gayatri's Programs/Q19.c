#include <stdio.h>
#include <stdlib.h>

void naturalNumbers(int);

int main()
{
    int num = 1;

    printf("The first 50 natural numbers are as follows:\n");
    naturalNumbers(num);

    return 0;
}

void naturalNumbers(int num)
{
    if(num <= 50)
    {
        printf("%d\t", num);
        naturalNumbers(num + 1);
    }
}