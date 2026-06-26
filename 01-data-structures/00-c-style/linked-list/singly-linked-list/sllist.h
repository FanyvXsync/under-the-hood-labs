#pragma once


#include <stdio.h>
#include <stdlib.h>

#include <assert.h>


typedef int SLDtype;


typedef struct SlistNode
{

	int data;
	struct	SlistNode* next;

}node;

void slt_print(node* pn);

//Î²²å

void PushBack(node** pphead, SLDtype x);


void PushFront(node** pphead, SLDtype x);

void del_back(node** phead);

void del_front(node** phead);