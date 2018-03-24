#include <cstdio>
#include <cstdlib>

void MakeUnion(int*a,int p ,int q)
{
	a[q] = p;
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


int main(int argc, char const *argv[])
{
	int n = 0;
	int p,q;
	scanf("%d",&n);	
	int *a = (int*)malloc(n*sizeof(int));

	for (int i = 0; i < n; ++i)
	{
		a[i] = i;
	}

	int option;
	scanf("%d %d %d",&option,&p,&q);
	while(p != -1 || q != -1)
	{
		if (option == 1)
		{
			MakeUnion(a,p,q);	
		}
		for (int i = 0; i < n; ++i)
		{	
			printf("%d",a[i]);
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