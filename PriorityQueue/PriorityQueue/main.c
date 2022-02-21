#include "priorityListFunc.h"
#include <stdio.h>

void PrintListIntData(PriorityQueue* queue); // Print elements int data, returns -1 if queue doesn't exist, returns -2 if queue is empty

int main()
{
	PriorityQueue *queue1, *queue2, *queue3;

	CreateEmptyQueue(&queue1);
	CreateEmptyQueue(&queue2);

	PrintListIntData(queue1);

	Insert(&queue1, 3, 2);
	Insert(&queue1, 1, 1);
	Insert(&queue1, 4, 2);
	Insert(&queue1, 7, 3);
	
	Insert(&queue2, 5, 2);
	Insert(&queue2, 2, 1);
	Insert(&queue2, 6, 2);
	Insert(&queue2, 8, 3);

	PrintListIntData(queue1);
	PrintListIntData(queue2);

	queue3 = Join(queue1, queue2);

	PrintListIntData(queue3);

	Remove(&queue3);

	DeleteQueue(&queue1);

	PrintListIntData(queue1);

	return 0;
}

void PrintListIntData(PriorityQueue* queue)
{
	if (queue == NULL)
	{
		printf("Queue doesn't exist\n");
		return -1;
	}
	else if (IsEmpty(queue))
	{
		printf("Queue is empty\n");
		return -2;
	}
	else
	{
		Node* temp = queue->head;

		for (int i = 0; i < queue->count; ++i)
		{
			printf("%d ", (int)temp->data);
			temp = temp->next;
		}
	}

	printf("\n");
}