#include<cstdio>
#include<stdlib.h>
#include<list>
#include<algorithm>
#include<iterator>

using namespace std;

struct memory
{
	int request_ID;
	int status;
	int amount;
};


int main() 
{

	list<memory> Memory;
	list<memory> WorstMemory;
	memory free_memory;
	int free_amount = -1;
	int request_id = 0;

	printf("Enter Free Amount\n");
	scanf(" %d", &free_amount);

	free_memory.request_ID = 0;
	free_memory.amount = free_amount;
	free_memory.status = 0;

	Memory.push_front(free_memory);
	WorstMemory.push_front(free_memory);

	while (request_id != -1) 
	{
		printf("Enter Request_ID\n");
		scanf(" %d",&request_id);
		int i = -1;
		list <memory> ::iterator it;
		// request_id does not exist so allocate it
		for (it = Memory.begin(); it != Memory.end(); ++it)
		{
			if (it->request_ID == request_id)
			{
				i = 1;
				break;
			}
			else {
				i = 0;
			}
		}

		if(i == 0)		
		{
			printf("Enter Amount\n");
			scanf(" %d",&free_amount);

			// for best fit find min free and allocate
			int min_memory = 999;
			list <memory> ::iterator toMin;
			for (list <memory> ::iterator it = Memory.begin(); it != Memory.end(); ++it)
			{
				if (it->amount <= min_memory && it->status == 0)
				{
					min_memory = it->amount;
					toMin = it;
					printf("Min ::%d %d %d\t", toMin->status, toMin->amount, toMin->request_ID);
				}
			}
			//printf("%d %d %d\t", toMin->status, toMin->amount, toMin->request_ID);
			
			//change value and add link list
			if (free_amount < toMin->amount)
			{
				free_memory.amount = toMin->amount - free_amount;
				free_memory.request_ID = 0;
				free_memory.status = 0;
				Memory.insert(toMin, free_memory);

			}
			toMin->amount = free_amount;
			toMin->request_ID = request_id;
			toMin->status = 1;

			int max_memory = -1;
			list <memory> ::iterator toMax;
			for (list <memory> ::iterator it = WorstMemory.begin(); it != WorstMemory.end(); ++it)
			{
				if (it->amount >= min_memory && it->status == 0)
				{
					min_memory = it->amount;
					toMax = it;
					printf("Max ::%d %d %d\t", toMax->status, toMax->amount, toMax->request_ID);
				}
			}
			//printf("%d %d %d\t", toMin->status, toMin->amount, toMin->request_ID);

			//change value and add link list
			if (free_amount < toMax->amount)
			{
				free_memory.amount = toMax->amount - free_amount;
				free_memory.request_ID = 0;
				free_memory.status = 0;
				WorstMemory.insert(toMax, free_memory);

			}
			toMax->amount = free_amount;
			toMax->request_ID = request_id;
			toMax->status = 1;

		}
		if (i == 1) 
		{
			printf("Free Memory\n");

			list<memory> ::iterator nextNode;
			list<memory> ::iterator previousNode;

			printf("%d %d\n",it->amount,it->request_ID);

			// free memory
			it->status = 0;
			it->request_ID = 0;
			/*nextNode = it++;
			previousNode = it--;
			if (nextNode->amount == 0)
			{
				it->amount = it->amount + nextNode->amount;
				Memory.erase(nextNode);
			}
			if (previousNode->amount == 0)
			{
				it->amount = it->amount + previousNode->amount;
				Memory.erase(previousNode);
			}*/
		}
			
		it = Memory.begin();
		for (int i = 0;i < Memory.size();i++)
		{
			printf("%d %d %d\t", it->status, it->amount, it->request_ID);
			it++;
		}

		it = WorstMemory.begin();
		for (int i = 0; i < WorstMemory.size(); i++)
		{
			printf("%d %d %d\t", it->status, it->amount, it->request_ID);
			it++;
		}
		printf("\n");

		
	}

	
}