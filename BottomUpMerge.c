#include<stdio.h>

void printArray(int arr[],int l,int r);
void MergeSort(int arr[],int l,int r);
void Merger(int arr[],int l,int m,int r);
int minMerge(int a , int b);

int main()
{
     int a[] = {12, 11, 13,8,9};
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
        int len = r -l + 1;
        int sz;
        for(sz = 1;sz < len;sz *= 2)
        {
            int lo;
            for(lo = l;lo < len - sz ;lo += 2*sz)
            {
                int mid = lo + sz - 1;
                printf("mid :: %d\n",mid);
                int ro  = minMerge(lo + 2*sz - 1,r);
                Merger(arr,lo,mid,ro);
                printArray(arr,lo,ro);
            }
        }
    }
}

void Merger(int arr[],int l,int m,int r)
{
   int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;


    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

int minMerge(int a , int b)
{
    return ((a < b)? a:b);
}
