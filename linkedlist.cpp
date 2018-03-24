#include <cstdio>
#include <cstdlib>

struct Node{
	int data;
	struct Node* next;
};

struct Node* MakenewNode(int data)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->next = NULL;

	return newnode;
}

void InsertB(struct Node** headref,int data)
{
	struct Node* newNode = MakenewNode(data);

	newNode->next = *headref;
	*headref = newNode;
return;
}

void InsertL(struct Node** headref,int data)
{
	struct Node* newNode = MakenewNode(data);
	struct Node* p = *headref;

	while(p->next != NULL)
	{
		p = p->next;
	}

	p->next = newNode;

return;
}

void deleteNode(struct Node** headref, int data)
{
	struct Node* p = *headref;

	// beginning delete
	if(p->data == data)
	{
		*headref = p->next;
		p->next = NULL;
		free(p);
		return;
	}
	else
	{
		int i =0;
		while(p->next != NULL && p->next->data != data)
		{
			p = p->next;	
		}
		if(p->next != NULL)
		{
			struct Node* x = p->next;
			p->next = p->next->next;
			free(x);
		}
		else
		{
			printf("No Such Value\n");
			return;
		}
		
		return;
	}
}


void swap(struct Node** headref,int data1 , int data2)
{
	struct Node* prev1 = NULL;
	struct Node* prev2 = NULL;

	struct Node* curr = *headref;

	if(data1 == data2){
		printf("NO need to swap\n");
	}

	while(curr->next != NULL)
	{
		if (curr->next->data == data1)
		{
			prev1 = curr;
		}
		if (curr->next->data == data2)
		{
			prev2 = curr;
		}
		curr = curr->next;
	}
	printf("%d, %d\n",prev1->data,prev2->data );
	if (prev1 == NULL || prev2 == NULL)
	{
		printf("There are no keys matching either data1 or data2 or both\n");
		return;
	}

	struct Node* temp = prev1->next;
	

	free(temp);

}


void printList(struct Node** headref)
{
	struct Node* p  = *headref;

	while(p != NULL)
	{
		printf("-> %d",p->data);
		p = p->next;
	}

}


int main(int argc, char const *argv[])
{
	struct Node* head = NULL;
	InsertB(&head,4);
	InsertB(&head,3);
	InsertL(&head,13);
	InsertB(&head,54);
	InsertB(&head,34);
	InsertL(&head,1443);
	InsertL(&head,1445);
	InsertB(&head,4232);
	InsertB(&head,323);
	InsertL(&head,1212);
	deleteNode(&head,4);
	deleteNode(&head,323);
	InsertL(&head,14123);
	InsertB(&head,421321);
	InsertB(&head,31243);
	InsertL(&head,131234);
	InsertL(&head,14124);
	
	swap(&head,14123,1443);
	printList(&head);
	

	return 0;
}