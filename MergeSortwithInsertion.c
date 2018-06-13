#include<stdio.h>

#define CUTOFF 7

void printArray(int arr[],int l,int r);
void MergeSortInsert(int arr[],int l,int r);
void Merger(int arr[],int l,int m,int r);
void InsertionSort(int arr[],int l,int r);

int main()
{
     int a[] = {12, 11, 13, 5, 6, 7, 111, 113, 15, 16, 37};
     int n = sizeof(a)/sizeof(a[00]);
     printArray(a,0,n-1);

     MergeSortInsert(a,0,n-1);
    printArray(a,0,n-1);
    return 0;
}
/*******************************************************/

void printArray(int arr[],int l,int r)
{
    int i =l;
    for(i = l;i<=r;i++)
    {
        printf("%d ",arr[i]);
    }
        printf("\n\n");

}

/*******************************************************/

void MergeSortInsert(int arr[],int l,int r)
{
    if( l < r)                  // optimized step
    {
        if(r - l <= CUTOFF - 1)
        {
            InsertionSort(arr,l,r);
            return;
        }

        int i;
        int m = l + (r-l)/2;

        printArray(arr,l,r);
        printf("****************** l to m\n");
        printArray(arr,l,m);
        printf("****************** m+1 to r\n");
        printArray(arr,m+1,r);
        MergeSortInsert( arr, l, m);
        MergeSortInsert( arr, m+1, r);

        if(arr[m] < arr[m+1])   // optimized step
            return;

        Merger( arr, l, m, r);


        printf("****************** l to m\n");
        printArray(arr,l,m);
        printf("****************** m+1 to r\n");
        printArray(arr,m+1,r);
        printf("****************** l to r\n");
        printArray(arr,l,r);


    }
}

/*******************************************************/

void Merger(int arr[],int l,int m,int r)
{
    int k = l;
    int n = r - l + 1;
    int aux[n];
    for(k = l;k<=r;k++)
    {
        aux[k] = arr[k];
    }

    int i = l;
    int j = m + 1;

     for(k = l;k<=r;k++)
    {
        if(i > m) arr[k] = aux[j++];
        else if(j > r) arr[k] = aux[i++];
        else if( i <= m && j <= r)
        {
            if(aux[i] < aux[j])
            {
                arr[k] = aux[i++];
            }
            else
            {
                arr[k] = aux[j++];
            }
        }
    }

}

/*******************************************************/

void InsertionSort(int arr[],int l,int r)
{

    int k;
    for(k = l+1;k<=r;k++)
    {

        int key = arr[k];
        int j= k-1;
        for(j = k-1;j >= l && arr[j] > key; j--)
        {

            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }
}

