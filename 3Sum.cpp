#include<cstdio>
#include<cstdlib>
#include<algorithm>

bool binary(int *arr,int key,int size)
{
	int lo = 0;
	int hi =  size - 1;
	int midi;
	for (int i = 0;lo <= hi; ++i)
	{
		midi = lo + (hi-lo)/2;
		if(key < arr[midi]) hi = midi-1;
		if(key > arr[midi]) lo = midi+1;
		else return true;
	}

return false;
}

void Sum3(int *arr,int size)
{
	std::sort(arr,arr+size);
	int k = 0;
	for (int i = 0; i < size; ++i)
	{
		
		for (int j = 0; j < size; ++j)
		{
			
			k = -(arr[i] + arr[j]);
			
			if ((arr[i] < arr[j]) && (arr[j] < k) && (binary(arr,k,size)))
			{
				printf("%d %d %d\n",arr[i],arr[j],k);
			}

		}
	}
	
return;
}

int main(int argc, char const *argv[])
{
	int n = 0;
	scanf("%d",&n);
	int *arr = (int*)malloc(n*sizeof(int));

	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}

	Sum3(arr,n);

	return 0;
}