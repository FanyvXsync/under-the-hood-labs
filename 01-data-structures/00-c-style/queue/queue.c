#define _CRT_SECURE_NO_WARNINGS 1

#include "queue.h"


void QueueInit(Queue* q)
{
	q->head = NULL;
	q->rear = NULL;

}

pQunode Queuebuynode(Qdatatype val)
{
	pQunode newnode = (pQunode)malloc(sizeof(Qunode));
	if (newnode == NULL)
	{
		perror("Buynode malloc fail::()");
		exit(1);
	}

	newnode->next = NULL;
	newnode->val = val;
	return newnode;
}




void QueuePush(Queue* q, Qdatatype data)
{
	pQunode newnode = Queuebuynode(data);

	if (q->head == NULL)
	{
		q->head = newnode;
		q->rear = newnode;
	}
	else
	{
		q->rear->next = newnode;
		q->rear = newnode;
	}


}

void QueuePop(Queue* q)
{
	assert(q && q->head);

	pQunode tmp = q->head;
	q->head = q->head->next;
	free(tmp);
	tmp = NULL;
	
}

Qdatatype QueueFront(Queue* q)
{
	assert(q && q->head);

	return q->head->val;

}

Qdatatype QueueBack(Queue* q)
{
	assert(q && q->rear);

	return q->rear->val;
}

int QueueSize(Queue* q)
{
	int cnt = 0;
	pQunode cur = q->head;
	while (cur)
	{
		cnt++;
		cur = cur->next;

	}

	return cnt;
}

bool QueueEmpty(Queue* q)
{
	assert(q);
	
	return q->head;
	
}

void QueueDestroy(Queue* q)
{
	assert(q);
	
	pQunode cur = q->head;
	while (cur)
	{
		pQunode tmp = cur;
		cur = cur->next;
		free(tmp);
		tmp = NULL;

	}

	free(q);
}
