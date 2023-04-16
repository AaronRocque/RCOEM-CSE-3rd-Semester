#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inputMenu(int* , int, int);
void bestCase(int* , int);
void countBestCase(int*, int);
void worstCase(int* , int);
void countWorstCase(int*, int);
void almostSortedCase(int*, int);
void averageCase(int* , int);
void countAverageCase(int*, int);
void selectionSort(int*, int);
void insertionSort(int*, int);
void bubbleSort(int*, int);
void shellSort(int*, int);
void countSort(int*, int);

int main()
{
    int sortChoice, inputChoice, n;
    double cpu_time_used;

    printf("Enter the number of elements of the array: \n");
    scanf("%d", &n);

    int *arr;
    arr = (int *)calloc(n, sizeof(int));
    

    while(1)
    {
        printf("Which of the following sorting methods would you like to execute?\n");
        printf("Enter 1 for Selection Sort.\n");
        printf("Enter 2 for Insertion Sort,\n");
        printf("Enter 3 for Bubble Sort. \n");
        printf("Enter 4 for Shell Sort. \n");
        printf("Enter 5 for Count Sort. \n");
        printf("Enter 6 for Exit. \n");
        scanf("%d", &sortChoice);
        
        switch(sortChoice)
        {
        case 1:
        printf("Selection Sort:\n");
        inputMenu(arr,n, sortChoice);
        break;

        case 2:
        printf("Insertion Sort:\n");
        inputMenu(arr, n, sortChoice);
        break;

        case 3:
        printf("Bubble Sort:\n");
        inputMenu(arr, n, sortChoice);
        break;

        case 4:
        printf("Shell Sort:\n");
        inputMenu(arr, n, sortChoice);
        break;

        case 5:
        printf("Counting Sort:\n");
        inputMenu(arr, n, sortChoice);
        break;

        case 6:
        exit(0);
        break;

        default:
        printf("Invalid Input! Try Again!\n");
        break;

        }
        
    }
    
    return 0;
}

void inputMenu(int a[],int n, int sortChoice)
{
    int inputChoice, check=1;
    double cpu_time_used;

    while(check == 1)
    {
        printf("In which of the following ways would you like to input the values?\n");
        printf("Enter 1 for Best Case.\n");
        printf("Enter 2 for Worst Case. \n");
        printf("Enter 3 for Average Case. \n");
        printf("Enter 4 for Almost Sorted Case.\n");
        printf("Enter 5 for Exit.\n");
        scanf("%d", &inputChoice);
        switch(inputChoice)
        {
            case 1:
            printf("Best Case:\n");
             if(sortChoice != 5)
            {
                bestCase(a,n);
            }
            if (sortChoice == 1)
            {
                selectionSort(a,n);
            }
            else if (sortChoice == 2)
            {
                insertionSort(a,n);
            }
            else if (sortChoice == 3)
            {
                bubbleSort(a,n);
            }
            else if (sortChoice == 4)
            {
                shellSort(a,n);
            }
            else if (sortChoice == 5)
            {
                countBestCase(a,n);
                countSort(a,n);
            }
            break;

            case 2:
            printf("Worst Case:\n");
            if(sortChoice != 5)
            {
                worstCase(a,n);
            }
            if (sortChoice == 1)
            {
                selectionSort(a,n);
            }
            else if (sortChoice == 2)
            {
                insertionSort(a,n);
            }
            else if (sortChoice == 3)
            {
                bubbleSort(a,n);
            }
            else if (sortChoice == 4)
            {
                shellSort(a,n);
            }
            else if (sortChoice == 5)
            {
                countWorstCase(a,n);
                countSort(a,n);
            }
            break;

            case 3:
            printf("Average Case:\n");
            if(sortChoice != 5)
            {
                averageCase(a,n);
            }
            if (sortChoice == 1)
            {
                selectionSort(a,n);
            }
            else if (sortChoice == 2)
            {
                insertionSort(a,n);
            }
            else if (sortChoice == 3)
            {
                bubbleSort(a,n);
            }
            else if (sortChoice == 4)
            {
                shellSort(a,n);
            }
            else if (sortChoice == 5)
            {
                bestCase(a,n);
                countSort(a,n);
            }
            break;

              case 4:
            printf("Almost Sorted Case:\n");
            almostSortedCase(a,n);
            if (sortChoice == 1)
            {
                selectionSort(a,n);
            }
            else if (sortChoice == 2)
            {
                insertionSort(a,n);
            }
            else if (sortChoice == 3)
            {
                bubbleSort(a,n);
            }
            else if (sortChoice == 4)
            {
                shellSort(a,n);
            }
            else if (sortChoice == 5)
            {
                countSort(a,n);
            }
            break;

            case 5:
            check = 0;
            break;

            default:
            printf("Invalid Input! Try Again!\n");
            break;
        }
    }      
}

void bestCase(int a[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        a[i] = i + 1;
        //printf("%d  ", a[i]);
    }
}

void countBestCase(int a[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        a[i] = 5;
        //printf("%d  ", a[i]);
    }
}

void worstCase(int a[], int n)
{
    int i;
    int size = n;

    for(i=0; i < size; i++, n-- )
    {
        a[i] = n;
        //printf("%d  ", a[i]);
    }
}

void countWorstCase(int a[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if (i == n-1)
        {
            a[n-1] = 99;
        }
        else
        {
            a[i] = i;
        }
        //printf("%d  ", a[i]);
        
    }    

}

void averageCase(int a[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        a[i] = rand()%10000;
        //printf("%d  ", a[i]);
    }
}

void countAverageCase(int a[], int n)
{
    int i, count=0; 

    for(i = 0; i < n; i++)
    {

    }
}

void almostSortedCase(int a[], int n)
{
    int i,j=99999;

    for(i = 0; i < n; i++)
    {
        if(i%5==0)
        {
            a[i]=j;
            //printf("%d  ", a[i]);
            j--;
        }
        else
        {
            a[i] = i + 1;
           // printf("%d  ", a[i]);
        }
       
    }

}

void selectionSort(int arr[], int n)
{
  double cpu_time_used;
  clock_t t1,t2;

  t1 = clock();

  int i, j, position, swap;

  for(i=0; i<(n-1); i++)
  {
    position = i;

    for(j=(i+1); j<n; j++ )
    {
      if (arr[position]>arr[j])
      position=j;
    }

    if(position != i)
    {
      swap=arr[i];
      arr[i]=arr[position];
      arr[position]=swap;
    }
  }

  /*for(i=0; i<n; i++)
  {
      printf("%d    ", arr[i]);
  }*/

  t2 = clock();

  cpu_time_used = (double)(t2-t1)/CLOCKS_PER_SEC;

  printf("The time required to perform selection sort is %lf\n", cpu_time_used);
}

void insertionSort(int a[], int n)
{
    double cpu_time_used;
    clock_t t1,t2;

    t1 = clock();

    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while(j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j = j-1;
        }

        a[j+1] = key;

    }

    /*for(i=0; i<n; i++)
    {
        printf("%d    ", a[i]);
    }*/

    t2 = clock();

    cpu_time_used = (double)(t2-t1)/CLOCKS_PER_SEC;

    printf("The time required to perform insertion sort is %lf\n", cpu_time_used);

}

void bubbleSort(int a[], int n)
{
     double cpu_time_used;
     clock_t t1,t2;

     t1 = clock();

     int c,d,t;

  for(c=0; c<(n-1); c++)
  {
    for(d=0; d<(n-c-1); d++)
    {
      if (a[d] > a[d+1])
      {
        t = a[d];
        a[d] = a[d+1];
        a[d+1] = t;
      }
    }

  }

  t2 = clock();

    cpu_time_used = (double)(t2-t1)/CLOCKS_PER_SEC;

    printf("The time required to perform Bubble sort is %lf\n", cpu_time_used);

}

void shellSort(int a[], int n)
{
    clock_t t1, t2;
    double cpu_time_used;

    t1 = clock();

   int gap, i, j, temp;

  for (gap = n/2; gap > 0;gap = gap/2)
  {
      for (j = gap; j < n; j++)
      {
          for (i = j-gap; i>=0;i = i-gap)
          {
              if (a[i+gap] >= a[i])
              {
                  break;
              }
              else
              {
                  temp = a[i];
                  a[i] = a[i+gap];
                  a[i+gap] = temp;
              }
          }
      }
  }

  t2 = clock();

    cpu_time_used = (double)(t2-t1)/CLOCKS_PER_SEC;

    printf("The time required to perform Shell Sort sort is %lf\n", cpu_time_used);

}

void countSort(int a[], int n)
{

    clock_t t1, t2;
    double cpu_time_used;

    t1 = clock();

    int i, k = a[0];

    for(i = 0; i < n; i++)
    {
        if (a[i] > k)
        {
            k = a[i];
        }
    }

    int *count;
    count = (int *)calloc(k+1, sizeof(int));

    int *b;
    b = (int *)calloc(n, sizeof(int));

    for(int i=0 ;i<k+1 ;i++) 
    {
      count[i]=0;
    }

    for (i = 0; i < n; i++)
    {
        count[a[i]]++;
    }

    for(i = 1; i <= k; i++)
    {
        count[i] = count[i] + count[i-1];
    }

    for(i = n-1; i >= 0; i--)
    {
        b[--count[a[i]]] = a[i];
    }

    for(i = 0; i < n; i++)
    {
        a[i] = b[i];
    }

     t2 = clock();

    cpu_time_used = (double)(t2-t1)/CLOCKS_PER_SEC;

    printf("The time required to perform Count Sort sort is %lf\n", cpu_time_used);

}