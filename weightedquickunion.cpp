#include <cstdio>
#include <cstdlib>

void MakeUnion(int*a,int*size,int p ,int q);
int Root(int*a,int p);
bool checkConnection(int*a,int p ,int q);



int main(int argc, char const *argv[])
{
	int n = 0;
	int p,q;
	printf("Enter no of elements\n");
	scanf("%d",&n);	
	int *a = (int*)malloc(n*sizeof(int));
	int *size = (int*)malloc(n*sizeof(int));

	for (int i = 0; i < n; ++i)
	{
		a[i] = i;
		size[i] = 1;
	}

	int option;
	printf("Enter p and q\n");
	scanf("%d %d %d",&option,&p,&q);
	while(p != -1 || q != -1)
	{
		if (option == 1)
		{
			MakeUnion(a,size,p,q);	
		}
		for (int i = 0; i < n; ++i)
		{	
			printf("a[%d] = %d \t size[%d] = %d \n",i,a[i],i,size[Root(a,a[i])]);
		}
		printf("\n");
		if(option == 2)
		{
			if(!checkConnection(a,p,q)) printf("There is no connection\n");
			else printf("There is connection\n");
		}
		scanf("%d %d %d",&option,&p,&q);
	}

	return 0;
}


void MakeUnion(int*a,int*size,int p ,int q)
{
	int rootp = Root(a,p);
	int rootq = Root(a,q);
	if(p == q || rootq == rootp){
		return;
	}
	if(size[rootp] >= size[rootq])
	{
		a[q] = p;
		size[rootp] += size[rootq];
	}
	else
	{
		a[p] = q;
		size[rootq] += size[rootp];	
	}
	
return;
}

int Root(int*a,int p)
{
	int i = p;
	while(i != a[i])
	{
		i = a[i];
	}
return i;
}


bool checkConnection(int*a,int p ,int q)
{
	if (Root(a,p) != Root(a,q)) return false;

	return true;
}
