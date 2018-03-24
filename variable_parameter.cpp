#include<cstdio>
#include <list>
#include<iterator>
#include<stdlib.h>

using namespace std;

struct MemoryNode
{
	int requestID;
	int status;
	int amount;
};

int main()
{
	list<MemoryNode> BestFit;
	list<MemoryNode> WorstFit;

	int requestID = 0;
	int AmountRequest = 0;
	MemoryNode BestFitNode;
	MemoryNode WorstFitNode;

	BestFitNode.requestID = 0;								// free => 0
	BestFitNode.status = 0;
	BestFitNode.amount = 0;

	WorstFitNode.requestID = 0;								// free => 0
	WorstFitNode.status = 0;
	WorstFitNode.amount = 0;

	list<int>::iterator bestIt;
	list<int>::iterator worstIt;

	printf("Enter Free Amount");
	scanf("%d",&(BestFitNode.amount));
	WorstFitNode.amount = BestFitNode.amount;
	
	BestFit.push_front(BestFitNode);
	WorstFit.push_front(WorstFitNode);

	while(requestID != -1 && AmountRequest != -1)
	{
		printf("Enter RequestId and Free Memory Amount");
		scanf("%d %d",&requestID,&AmountRequest);
		if(AmountRequest > 0)
		{
			BestFitNode.requestID = requestID;
			BestFitNode.amount = AmountRequest;
			BestFitNode.status = 1;

			
			int min = 999;
			list<int>::iterator bestmin = BestFit.begin();

			for ( bestIt = BestFit.begin();bestIt != BestFit.end(); ++bestIt)
			{
				if(AmountRequest <= bestIt->amount && bestIt->status == 0)
				{	
					if(bestIt->amount <= min)
					{
						bestmin = bestIt;
						min = bestIt->amount;
					}
				}
			}
			bestmin->amount = bestmin->amount - AmountRequest;
			BestFit.insert(bestmin,BestFitNode);

			WorstFitNode.requestID = requestID;
			WorstFitNode.amount = AmountRequest;
			WorstFitNode.status = 1;

			int max = -999;
			list<int>::iterator worstmax = WorstFit.begin();

			for ( worstIt = BestFit.begin();worstIt != BestFit.end(); ++worstIt)
			{
				if(AmountRequest <= bestIt->amount && bestIt->status == 0)
				{	
					if(worstIt->amount >= max)
					{
						worstmax = worstIt;
						max = worstIt->amount;
					}
				}
			}
			worstmax->amount = worstmax->amount - AmountRequest;
			WorstFit.insert(worstmax,WorstFitNode);

		}
		if(AmountRequest == 0)
		{

		}
	}

}