#include<cstdio>
#include<cstdlib>
#include<stack>

using namespace std;

void SortedInsert(stack<int> &Stack,int temp)
{
	if(Stack.empty() || temp > Stack.top())
		{
			Stack.push(temp);
			return;
		}
	//printf("%d\n",Stack.top());
	int temp2 = Stack.top();
	Stack.pop();
	SortedInsert(Stack,temp);
	Stack.push(temp2);
return;
}

void SortStack(stack<int> &Stack)
{
	if(!Stack.empty())
		return;

	int temp = Stack.top();
	//printf("%d\n",Stack.top());
	Stack.pop();
	SortStack(Stack);
	SortedInsert(Stack,temp);	
	
	

return;
}

int main(int argc, char const *argv[])
{
	stack<int> Stack;
	Stack.push(9);
	Stack.push(4);
	Stack.push(15);
	Stack.push(12);
	Stack.push(30);

	SortStack(Stack);

	while(!Stack.empty())
	{
		printf("%d\n",Stack.top());
		Stack.pop();
	}

	return 0;
}