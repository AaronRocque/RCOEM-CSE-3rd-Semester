#include <stdio.h>
#include <stdlib.h>

int digitCounter(int);

int main()
{
    int num, count = 0;

    printf("Enter a number: \n");
    scanf("%d", &num);

    printf("The number of digits in the entered number is %d.\n", digitCounter(num));

    return 0;
}

int digitCounter(int num)
{
    if(num != 0)
    {    
       return 1 + digitCounter(num/10);
    }
}