#include<stdio.h>

void printArray(int arr[],int lo ,int hi);
void quickSort3Way(int arr[],int lo,int hi);
void partition(int arr[],int lo ,int hi, int *lt ,int *gt);
void swap(int *a ,int *b);

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 10, 7, 10,11,16};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort3Way(arr, 0, n-1);
    printf("Sorted array:  \n");
    printArray(arr,0,n-1);
    return 0;

}

void swap(int *a ,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[],int lo ,int hi)
{
    int i = 0;
    for(i = lo;i <= hi;i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\n\n");

}

void quickSort3Way(int arr[],int lo, int hi)
{
    if( lo >= hi) return;


    int lt = 0;
    int gt = 0;
    partition(arr,lo,hi,&lt,&gt);
    printf("lt :: %d gt :: %d \n",lt,gt);
    quickSort3Way(arr,lo,lt-1);
    quickSort3Way(arr,gt+1,hi);

    return;
}

void partition(int arr[] ,int lo ,int hi ,int *lT, int *gT)
{
    int lt = lo;
    int gt = hi;
    int i = lo;
    int v = arr[lo];
    while( i  <= gt)
    {
        if(arr[i] < v) swap(&arr[i++],&arr[lt++]);
        else if(arr[i] > v) swap(&arr[i], &arr[gt--]);
        else i++;
        printArray(arr,lo,hi);
    }

    *lT = lt;
    *gT = gt;

    return;
}
