#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int listtype;

typedef struct listnode
{
	listtype data;
	struct listnode* next;
	struct listnode* prev;

}ltnode;

ltnode* lt_buynode(listtype x);

void lt_init(ltnode **pphead);
