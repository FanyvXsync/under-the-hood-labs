#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"


ltnode* lt_buynode(listtype x)
{
	ltnode* node = (ltnode*)malloc(sizeof(ltnode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(1);
	}

	node->data = x;
	node->next = node->prev = node;
	return node;

}




void lt_init(ltnode ** pphead)
{
	ltnode* headnode = lt_buynode(-1);
	*pphead = headnode;
}