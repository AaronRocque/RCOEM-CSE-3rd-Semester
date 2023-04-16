#include <stdio.h>
#include <stdlib.h>
#define MAX 8

void create(int *, int);
void print(int *, int);
void bubbleSort(int arr[], int n);
void bubbleSort2(int arr[], int n);
void selectionSort(int arr[], int n);
void binarySearch(int arr[], int element, int n);
void linearSearch(int arr[], int element, int n);
void insert(int *arr, int n, int val, int p);
int length(int*);
int isEmpty(int*);
int isFull(int*);
void deletion(int, int*);
void traverse(int*, int);
void copy(int* , int, int*);
void merge(int*, int);

int main()
{
  int choice,switchChoice, searchChoice;
  int *arr,n,i;
  int element, val, y, pos, posd;
  int g;
  int *copied;
  copied = (int *)calloc(MAX, sizeof(int));
  
  while(1)
  {
  printf("Which of the following tasks do you want to execute?\n");
  printf("Enter 1 for Creation.\n");
  printf("Enter 2 for Insertion.\n");
  printf("Enter 3 for Deletion.\n");
  printf("Enter 4 for Copy.\n");
  printf("Enter 5 for Sorting.\n");
  printf("Enter 6 for Searching.\n");
  printf("Enter 7 for Length of the Array.\n");
  printf("Enter 8 for IsEmpty.\n");
  printf("Enter 9 for IsFull.\n");
  printf("Enter 10 for Traversal.\n");
  printf("Enter 11 for Merging.\n");
  printf("Enter 12 for Exit.\n");

  scanf("%d", &choice);
  
  switch (choice)
  {
    
    case 1:
    arr=(int *)calloc(MAX, sizeof(int));
    printf("Enter the number of elements of the array: ");
    scanf("%d", &n);
    arr[0]=-99;
    create(arr, n);
    break;

    case 2:
    printf("Enter the value you want to insert: \n");
    scanf("%d", &val);
    printf("Enter the position at which you want to enter the above mentioned value: \n");
    scanf("%d", &y);
    if (y > length(arr) || isFull(arr) == 0) 
    {
        printf("INVALID POSITION\n");
    }
    else
    {
      pos=y-1;
      insert(arr, length(arr), val, y);
    }
    break;

    case 3:
    printf("Deletion\n");
    if(isEmpty(arr)==1)
    {
      printf("Array is empty! Deletion is not possible.");
    }
    else
    {
      print(arr,length(arr));
      printf("Enter the position of the element you want to delete: \n");
      scanf("%d", &posd);
      deletion((posd-1), arr);
    }
    break;

    case 4:
    printf("Copy\n");
    copy(arr, length(arr), copied);
    break;

    case 5:
    printf("Which of the following sorting methods would you like to execute?\n");
    printf("Enter 1 for Bubble Sort.\n");
    printf("Enter 2 for Selection Sort.\n");
    scanf("%d", &switchChoice);
    switch (switchChoice)
    {
      case 1:
      printf("Bubble Sort: \n");
      copy(arr, length(arr), copied);
      bubbleSort(copied, length(copied));
      print(copied,length(copied));
      printf("Bubble Sort Complete!\n");
      break;

      case 2:
      printf("Selection Sort: \n");
      copy(arr, length(arr), copied);
      selectionSort(copied, length(copied));
      print(copied,length(copied));
      printf("Selection Sort Complete!\n");
      break;
    }
    break;

    case 6:
    printf("Which of the following searching methods would you like to execute?\n");
    printf("Enter 1 for Linear Search.\n");
    printf("Enter 2 for Binary Search.\n");
    scanf("%d", &searchChoice);
    switch (searchChoice)
    {
      case 1:
      printf("Linear Search: \n");
      printf("Which number do you want to search for? \n");
      scanf("%d", &element);
      linearSearch(arr, element, n);
      //printf("Linear Search Complete!");
      break;

      case 2:
      printf("Binary Search: \n");
      printf("Which number do you want to search for? \n");
      scanf("%d", &element);
      binarySearch(arr, element, n);
      //printf("Binary Search Complete!");
      break;
    }
    break;

    case 7:
    printf("The length of the array is: %d\n", length(arr));
    break;

    case 8:
    isEmpty(arr);
    if(isEmpty(arr)==1)
    {
      printf("Empty\n");
    }
    else
    {
      printf("Not Empty\n");
    }
    break;

    case 9:
    isFull(arr);
    if(isFull(arr)==1)
    {
      printf("Not Full\n");
    }
    else
    {
      printf("Full");
    }
    break;

    case 10:
    printf("Transversal\n");
    print(arr, n);
    break;

    case 11:
    printf("Merging\n");
    copy(arr, length(arr), copied);
    merge(copied, length(copied));
    break;

    case 12:
    exit(0);
    break;

    default:
    printf("Invalid Input! Try Again!\n");
    break;
  }
  } 

  return 0;

}


void create(int a[], int n)
{
  int i;

  printf("Enter %d number of elements: \n", n);

  for(i=0;i<n;i++)
  {
    a[i+1]=a[i];
    scanf("%d", &a[i]);
  }
}

void print(int a[], int n)
{
  int i=0;

  while(a[i] != -99)
  {
    printf("%d \t", a[i]);
    i++;
  }

  printf("\n");
}

void bubbleSort(int arr[], int n)
{
  int c,d,t;

  for(c=0; c<(n-1); c++)
  {
    for(d=0; d<(n-c-1); d++)
    {
      if (arr[d] > arr[d+1])
      {
        t = arr[d];
        arr[d] = arr[d+1];
        arr[d+1] = t;
      }
    }

  }

}

void selectionSort(int arr[], int n)
{
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
}

void binarySearch(int arr[], int element, int n)
{
    int f=0, r=n, mid;

    while (f <= r)
    {
        mid = (f+r)/2;

        if(arr[mid] ==  element)
        {
            printf("\nSearch Element  : %d  : Found :  Position : %d.\n", element, mid+1);
            break;
        }

        else if(arr[mid] < element)
        {
            f = mid + 1;
        }

        else
        {
            r = mid - 1;
        }
     }

     if (f > r)
      printf("\nSearch Element : %d  : Not Found \n", element);
}

void linearSearch(int arr[], int element, int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        if (arr[i] == element)
        {
          printf("Linear Search : %d is Found at array : %d.\n", element, i + 1);
          break;  
        }
    }

    if(i==n)
    {
         printf("\nSearch Element : %d  : Not Found \n", element);
    }
}

void insert(int *arr, int n, int val, int p)
{
   int x = n;

    {
        while (x != p)
        {
            arr[x] = arr[x - 1];
            x--;
        }

        arr[p] = val;
        arr[n+1] = -99;
    }

}

int length(int *p)
{
  int count=0;
  while(*p != -99)
  {
    count++;
    p++;
  }
  return count++;
}

int isEmpty(int a[])
{
  int check = length(a);
  if(check==0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int isFull(int a[])
{
  int check = length(a);
  if(check==MAX-1)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

void deletion(int pos, int a[])
{
  int l, back;

  l=length(a);

  if(pos>=(l-1))
  {
    printf("Deletion not possible!\n");
  }
  else
  {
    back = pos;
    while(back<=l)
    {
      a[back]=a[back+1];
      back++;
    }

    print(a,l-1);

  }

}

void copy(int a[], int l, int copied[])
{
  

  for(int i = 0; i < l; i++)
  {
    copied[i] = a[i];
  }

  copied[l] = -99;

  print(copied, l);
}

void merge(int a[], int n)
{
  int *b;
  int temp = n;


  bubbleSort(a, n);

    printf("Enter the size of second array: \n");
    int p,q=0;
    scanf("%d", &p);

    b = (int *)calloc(MAX, sizeof(int));

    int c = p + n;

    printf("Enter the elements of second array: \n");
    for (int i = 0; i < p; i++)
        scanf("%d", &b[i]);
    
    a = (int *)realloc(a, sizeof(int) * c);

    for (int i = 0; i < p; i++)
    {
        int flag = 1;
        for (int j = 0; j < temp; j++)
        {
            if (b[i] < a[j])
            {
                insert(a, c, b[i], j);
                flag = 0;
                temp++;
                break;
            }
        }
        if (flag == 1)
        {
            a[temp] = b[i];
            temp++;
        }
    }

    a[temp]=-99;


    printf("Elements of the array are: \n");

    for (int i = 0; i < c; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
  
}

// MERGE FUNCTION WITHOUT REALLOC
/*  void merging(int a[], int n)
{
  int temp = n;
  int l2,c;  
  printf("Enter the size of second array: \n"); 
  scanf("%d", &l2);
  c = l2 + n;
  if(c>MAX)
  {
    printf("Merging not possible!\n");
  }
  else
  {
    int *b;
  b = (int *)calloc(MAX, sizeof(int));
  b[0]=-99;
  create(b,l2);
  bubbleSort(a, n);
    for (int i = 0; i < l2; i++)
    {
      int check = 1;
        for (int j = 0; j < temp; j++)
        {
          if (b[i] < a[j])
            {
                insert(a, c, b[i], j);
                check = 0;
                temp++;
                break;
            }
        }
        if (check == 1)
        {
            a[temp] = b[i];
            temp++;
        }
    }
  
    a[temp]=-99; 
   printf("Elements of the array are: \n");
    for (int i = 0; i < c; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
  
 }
}

*/