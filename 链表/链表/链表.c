#define _CRT_SECURE_NO_WARNINGS 1

#include "sllist.h"



void slt_print(node* phead)
{
	node* pcur = phead;
	
	
	while (pcur)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;

	}
	printf("NULL\n");

}


node* SLDbroad_sp(SLDtype x)
{
	
	node* newnode = (node*)malloc(sizeof(node));
	if (newnode == NULL)
	{
		perror("malloc,wrong");
		exit(1);
	}

	newnode->data = x;
	newnode->next = NULL;


	return newnode;


}








void PushBack(node**pphead, SLDtype x)
{
	//урн╡
	assert(*pphead);

	node* newnode=SLDbroad_sp(x);

	


	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		node* ptail =*pphead;

		while (ptail->next)
		{
			ptail = ptail->next;

		}

		ptail->next = newnode;


	}


	


}


void PushFront(node** pphead, SLDtype x)
{
	assert(pphead);

	node* newnode = SLDbroad_sp(x);
	
	newnode->next = *pphead;
	
	*pphead = newnode;



}



void del_back(node** pphead)
{
	assert(pphead && *pphead);
	
	
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}

	else
	{
		node* ptail = *pphead;

		node* prev = *pphead;

		while (ptail->next)
		{

			prev = ptail;
			ptail = ptail->next;

		}

		free(ptail);
		ptail = NULL;
		prev->next = NULL;
	}


}


void del_front(node** pphead)
{

	assert(pphead && *pphead);

	node* two = *pphead;

	two = two->next;

	free(*pphead);

	*pphead = NULL;


}