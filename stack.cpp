#include<cstdio>
#include<cstdlib>
#include<string>

#define MAX 100

class stack
{
public:
	stack()
	{
		 top = -1;
	}

	void push(int data)
	{
		if(top >= MAX)
		{
			printf("Stack Limit Reached\n");
			return;
		}
		stackarr[++top] = data;
	}
	void pop()
	{
		if(isEmpty())
		{
			printf("Stack Empty\n");
			return;
		}
		printf("%d\n",stackarr[top]);
		--top;
		return; 
	}
	bool isEmpty()
	{
		return (top < 0);
	}

	int top;
	int stackarr[MAX];
};


int main(int argc, char const *argv[])
{
	stack s;
	printf("First\n");
	s.push(5);
	printf("Second\n");
	s.push(7);
	printf("Third\n");
	s.push(6);
	printf("Fourth\n");
	s.pop();
	printf("Fifth\n");
	return 0;
}