#include <stdio.h>
#include <stdlib.h>

int main() 
{
   int i, j, rows; 

   printf("Enter the number of rows: "); // rows = 6
   scanf("%d", &rows);

   for (i = 1; i <= rows; i++) 
   {
      for (j = 1; j <= i; j++) 
      {
         printf("* ");
      }
      printf("\n");
   }

   return 0;

}