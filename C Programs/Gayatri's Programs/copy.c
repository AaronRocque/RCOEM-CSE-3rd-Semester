#include<stdio.h>

int noOfDigits(int n1, int c);
int main()
{
  int n1,ctr, c=0;
    printf("\n\n count the digits of a given number :\n");
	printf("-----------------------------------------\n");
    printf(" Input  a number : ");
    scanf("%d",&n1);

    ctr = noOfDigits(n1,c);

    printf(" The number of digits in the number is :  %d \n\n",ctr);
    return 0;
}

int noOfDigits(int n1, int c)
{
    //static int ctr=0;

     if(n1!=0)
     {
          c++;
         noOfDigits(n1/10, c);
    }

    return c;
}
