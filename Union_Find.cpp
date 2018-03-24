#include<cstdio>
#include<cstdlib>


void swap(int *p,int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}

int main()
{

	int n = 0;
	printf("Enter no of Nodes\n");
	scanf("%d",&n);

	int* a = (int*)malloc(n*sizeof(int));
	for (int i = 0; i < n;++i)
	{
		a[i] = i;
	}

	//connect
	int t = 0;
	int p=0,q=0;
	printf("There No of Connection Conditions\n");
	scanf("%d",&t);
	while(t>0)
	{
		
		scanf("%d %d",&p,&q);
		if (p > q) swap(&p,&q);
		for (int i = 0; i < n; ++i)
		{
			if(a[i] == a[q]) a[i] = a[p];
		}
		t--;
	}

	//disconnect

	//quikfind whether it exist a path
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", a[i]);
	}
	printf("Enter P and Q\n");
	scanf("%d %d",&p,&q);
	if(a[p] == a[q]) printf("There exist a path\n");
	else printf("There is no path between %d and %d\n",p,q);


	return 0;
}