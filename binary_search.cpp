#include<cstdio>
#include<cstdlib>

int binary(int *arr,int key,int size)
{
	int lo = 0;
	int hi =  size - 1;
	int midi;
	for (int i = 0;lo <= hi; ++i)
	{
		midi = lo + (hi-lo)/2;
		printf("%d\n",midi);
		if(key < arr[midi]) hi = midi-1;
		if(key > arr[midi]) lo = midi+1;
		else return midi;
	}

return -1;
}

int binary(float *arr,float key,int size)
{
	int lo = 0;
	int hi =  size - 1;
	int midi;
	for (int i = 0;lo <= hi; ++i)
	{
		midi = lo + (hi-lo)/2;
		printf("%d\n",midi);
		if(key < arr[midi]) hi = midi-1;
		if(key > arr[midi]) lo = midi+1;
		else return midi;
	}

return -1;
}

int main(int argc, char const *argv[])
{
	int n = 0;
	scanf("%d",&n);
	float *arr = (float*)malloc(n*sizeof(float));

	for (int i = 0; i < n; ++i)
	{
		scanf("%f",&arr[i]);
	}

	float key = -1.0;
	scanf("%f",&key);

	int indx = binary(arr,key,n);

	if (indx == -1) printf("No suck key\n");
	else printf("The index of key is %d\n",indx);

	return 0;
}