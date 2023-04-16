#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, temp, sum = 0, digit;

    printf("Enter a number: \n");
    scanf("%d", &num);

    temp = num;

    while(num > 0)
    {
        digit = num % 10;
        sum = sum + (digit * digit * digit);
        num = num / 10;
    }

    if(temp == sum)
    {
        printf("The entered number IS an Armstrong Number.\n");
    }
    else
    {
        printf("The entered number IS NOT an Armstrong Number.\n");
    }

    return 0;
}