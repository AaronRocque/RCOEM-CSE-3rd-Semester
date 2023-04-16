#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inputMenu(int* , int, int);
void bestCase(int* , int);
void worstCase(int* , int);
void almostSortedCase(int*, int);
void averageCase(int* , int);
void quickSortWorst(int*, int, int);
int partitionWorst(int*, int , int);
void quickSortBest(int*, int, int);
int partitionBest(int*, int , int);
void mergeSort(int*, int, int, int);
void merge(int*, int, int, int, int);
//void heapSort(int*, int);


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
        printf("Enter 1 for Quick Sort.\n");
        printf("Enter 2 for Merge Sort.\n");
        printf("Enter 3 for Heap Sort.\n");
        printf("Enter 4 for Exit. \n");
        scanf("%d", &sortChoice);
        
        switch(sortChoice)
        {
        case 1:
        printf("Quick Sort:\n");
        inputMenu(arr,n, sortChoice);
        break;

        case 2:
        printf("Merge Sort:\n");
        inputMenu(arr, n, sortChoice);
        break;

        case 3:
        printf("Heap Sort:\n");
        inputMenu(arr, n, sortChoice);
        break;

        case 4:
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
            bestCase(a,n);
            if (sortChoice == 1)
            {
                //worstCase(a,n);

                clock_t t1, t2;
                double cpu_time_used;

                t1 = clock();

                quickSortBest(a, 0, n-1);

                t2 = clock();

                cpu_time_used = (double)(t2-t1)/CLOCKS_PER_SEC;

                printf("The time required to perform Quick Sort sort is %lf\n", cpu_time_used);
            }
            else if (sortChoice == 2)
            {
                clock_t t1, t2;
                double cpu_time_used;

                t1 = clock();

                mergeSort(a, 0, n-1, n);

                t2 = clock();

                cpu_time_used = (double)(t2-t1)/CLOCKS_PER_SEC;

                printf("The time required to perform Merge Sort sort is %lf\n", cpu_time_used);
            }
            else if (sortChoice == 3)
            {
                //heapSort(a,n);
            }
            break;

            case 2:
            printf("Worst Case:\n");
            worstCase(a,n);
            //bestCase(a,n);
            if (sortChoice == 1)
            {
                clock_t t1, t2;
                double cpu_time_used;

                t1 = clock();

                quickSortWorst(a, 0, n-1);

                t2 = clock();

                cpu_time_used = (double)(t2-t1)/CLOCKS_PER_SEC;

                printf("The time required to perform Quick Sort sort is %lf\n", cpu_time_used);
            }
            else if (sortChoice == 2)
            {
                clock_t t1, t2;
                double cpu_time_used;

                t1 = clock();

                mergeSort(a, 0, n-1, n);

                t2 = clock();

                cpu_time_used = (double)(t2-t1)/CLOCKS_PER_SEC;

                printf("The time required to perform Merge Sort sort is %lf\n", cpu_time_used);
            }
            else if (sortChoice == 3)
            {
                //heapSort(a,n);
            }
            break;

            case 3:
            printf("Average Case:\n");
            averageCase(a,n);
            if (sortChoice == 1)
            {
                //quickSort(a,n);
            }
            else if (sortChoice == 2)
            {
                clock_t t1, t2;
                double cpu_time_used;

                t1 = clock();

                mergeSort(a, 0, n-1, n);

                t2 = clock();

                cpu_time_used = (double)(t2-t1)/CLOCKS_PER_SEC;

                printf("The time required to perform Merge Sort sort is %lf\n", cpu_time_used);
            }
            else if (sortChoice == 3)
            {
                //heapSort(a,n);
            }
            break;

              case 4:
            printf("Almost Sorted Case:\n");
            almostSortedCase(a,n);
            if (sortChoice == 1)
            {
                //quickSort(a,n);
            }
            else if (sortChoice == 2)
            {
                mergeSort(a, 0, n-1, n);
            }
            else if (sortChoice == 3)
            {
                //heapSort(a,n);
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



void averageCase(int a[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        a[i] = rand()%10000;
        //printf("%d  ", a[i]);
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

void mergeSort(int A[], int lb, int ub, int n)
{
    int mid;

    if (lb < ub)
    {
        mid = (lb + ub)/2;
        mergeSort(A, lb, mid, n);
        mergeSort(A, mid+1, ub, n);
        merge(A, lb, mid, ub, n);
    }
}

void merge(int a[], int lb, int mid, int ub, int n)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;

    int *b;
    b = (int *)calloc(n, sizeof(int));


    while(i <= mid && j <= ub)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    if (i > mid)
    {
        while(j <= ub)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i <= mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }

    for (k = lb; k <= ub; k++)
    {
        a[k] = b[k];
    }
}

void quickSortWorst(int A[], int lb, int ub)
{
    int loc;

    if (lb < ub)
    {
        loc = partitionWorst(A, lb, ub);
        quickSortWorst(A, lb, loc-1);
        quickSortWorst(A, loc+1, ub);
    }
}

int partitionWorst(int a[], int lb, int ub)
{
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    int temp;

    while (start < end)
    {
        while (a[start] <= pivot)
        {
            start++;
        }
        
        while (a[end] > pivot)
        {
            end--;
        }

        if(start < end)
        {
            temp = a[start];
            a[start] = a[end];
            a[end] = temp;   
        }
    }

    temp = a[lb];
    a[lb] = a[end];
    a[end] = temp;

    return end;
}

void quickSortBest(int A[], int lb, int ub)
{
    int loc;

    if (lb < ub)
    {
        loc = partitionBest(A, lb, ub);
        quickSortBest(A, lb, loc-1);
        quickSortBest(A, loc+1, ub);
    }
}

int partitionBest(int a[], int lb, int ub)
{
    int mid = (lb+ub)/2;
    int pivot = a[mid];
    int start = lb;
    int end = ub;
    int temp;

    while (start < end)
    {
        while (a[start] <= pivot)
        {
            start++;
        }
        
        while (a[end] > pivot)
        {
            end--;
        }

        if(start < end)
        {
            temp = a[start];
            a[start] = a[end];
            a[end] = temp;   
        }
    }

    temp = a[mid];
    a[mid] = a[end];
    a[end] = temp; 

    return mid;
}