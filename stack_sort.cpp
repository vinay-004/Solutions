#include<cstdio>
#include<cstdlib>
#include<stack>

using namespace std;


int main(int argc, char const *argv[])
{
	stack<int> sortStack;
	stack<int> tempStack;

	int n;
	int input;
	scanf("%d",&n);
	scanf("%d",&input);
	sortStack.push(input);
	
	for (int i = 0; i < n-1; ++i)
	{
		scanf("%d",&input);	
		while(!sortStack.empty() && sortStack.top() < input)
		{
			tempStack.push(sortStack.top());
			printf("tempStack :: %d\n",tempStack.top());
			sortStack.pop();
		}
		sortStack.push(input);
		while(!tempStack.empty())
		{
			sortStack.push(tempStack.top());
			tempStack.pop();
		}
	}

	while(!sortStack.empty())
	{
		printf("%d ",sortStack.top());
		sortStack.pop();
	}


	return 0;
}