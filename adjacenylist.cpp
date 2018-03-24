#include<cstdio>
#include<cstdlib>

struct AdjNode
{
	int dest;
	struct AdjNode *next;
};

struct AdjList
{
	struct AdjNode* head;
};

struct Graph
{
	int V;
	struct AdjList *list;
};

struct AdjNode* newAdjNode(int dest)
{
	struct AdjNode* newNode = (struct AdjNode*)malloc(sizeof(struct AdjNode));

	newNode->dest = dest;
	newNode->next = NULL;

	return newNode;
}

struct Graph* createGraph(int V)
{
	struct Graph* newGraph = (struct Graph*)malloc(sizeof(struct Graph));

	struct AdjList* newList = (struct AdjList*)malloc(V * sizeof(struct AdjList));

	newGraph->V = V;
	newGraph->list = newList;

	for (size_t i = 0; i < newGraph->V; i++)
	{
		newGraph->list[i].head = NULL;
	}

	return newGraph;
}

void AddEdge(struct Graph* Graph,int src,int dest)
{
	struct AdjNode* newNode = newAdjNode(dest);
	newNode->next = Graph->list[src].head;
	Graph->list[src].head = newNode;

	newNode = newAdjNode(src);
	newNode->next = Graph->list[dest].head;
	Graph->list[dest].head = newNode;
}

void printGraph(struct Graph* Graph)
{
	struct AdjNode* head;
	for (size_t i = 0; i < Graph->V; i++)
	{
		printf("%d : ", Graph->V);
		head = Graph->list[i].head;
		while (head)
		{
			printf("%d\t", head->dest);
			head = head->next;
		}
		printf("\n");
		
	}
}


int main()
{
	int V = 5;
	struct Graph* graph = createGraph(V);
	AddEdge(graph, 0, 1);
	AddEdge(graph, 0, 4);
	AddEdge(graph, 1, 2);
	AddEdge(graph, 1, 3);
	AddEdge(graph, 1, 4);
	AddEdge(graph, 2, 3);
	AddEdge(graph, 3, 4);

	printGraph(graph);

	return 0;
}