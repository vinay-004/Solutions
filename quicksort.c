#include<stdio.h>
#include<stdbool.h>

void printArray(int arr[], int lo,int hi);
void quickSort(int arr[],int lo,int hi);
int partition(int arr[],int lo ,int hi); // return partition index


int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5,17, 18, 19, 11, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array:  \n");
    printArray(arr,0,n-1);
    return 0;
}

void printArray(int arr[],int l,int r)
{
    int i =l;
    for(i = l;i<=r;i++)
    {
        printf("%d ",arr[i]);
    }
        printf("\n\n");

}

void swap(int *a,int *b)
{
    int t = *a;
     *a = *b;
     *b = t;
}

void quickSort(int arr[] ,int lo ,int hi)
{
    if(lo >= hi) return;
    printArray(arr,lo,hi);
    int j = partition(arr,lo,hi);

    quickSort(arr,lo,j -1);
    quickSort(arr,j +1,hi);

    return;
}

int partition(int a[] ,int lo ,int hi)
{
    int i = lo;
    int j = hi + 1;

    while(true)
    {
        while(a[++i] < a[lo])
            if(i == hi) break;
        while(a[--j] > a[lo])
            if(j == lo) break;

        if(i >= j) break;

        swap(&a[i],&a[j]);

    }

    swap(&a[j],&a[lo]);

    return j;
}
