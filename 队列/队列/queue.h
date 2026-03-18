#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int Qdatatype;

typedef struct Queuenode
{
	struct Queuenode* next;
	Qdatatype val;
}Qunode, * pQunode;


typedef struct Queue
{
	pQunode head;
	pQunode rear;
}Queue,* pQueue;

void QueueInit(Queue* q);

void QueuePush(Queue* q, Qdatatype data);

void QueuePop(Queue* q);

Qdatatype QueueFront(Queue* q);

Qdatatype QueueBack(Queue* q);

int QueueSize(Queue* q);

bool QueueEmpty(Queue* q);

void QueueDestroy(Queue* q);

