#include<stdio.h>

void printArray(int arr[],int l,int r);
void MergeSort(int arr[],int l,int r);
void Merger(int arr[],int l,int m,int r);

int main()
{
     int a[] = {12, 11, 13, 5, 6, 7,19,9};
     int n = sizeof(a)/sizeof(a[00]);
     printArray(a,0,n-1);

     MergeSort(a,0,n-1);
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

void MergeSort(int arr[],int l,int r)
{
    if( l < r)
    {
        int i;
        int m = l + (r-l)/2;

        printArray(arr,l,r);
        printf("****************** l to m\n");
        printArray(arr,l,m);
        printf("****************** m+1 to r\n");
        printArray(arr,m+1,r);
        MergeSort( arr, l, m);
        MergeSort( arr, m+1, r);

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

    for(k = l;k<=r;k++)
    {
        printf("aaaaa :: %d  ",aux[k]);
    }

    int i = l;
    int j = m + 1;

     for(k = l;k<=r;k++)
    {
        if(i > m) arr[k] = aux[j++];
        else if(j > r) arr[k] = aux[i++];
        else if( i <= m && j <= r)
        {

            if(aux[i] > aux[j])
            {
                arr[k] = aux[j++];
            }
            else
            {
                arr[k] = aux[i++];
            }
        }
    }

}
