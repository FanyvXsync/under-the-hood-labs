#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


typedef int stdatatype;


typedef struct stack
{
	stdatatype* a;
	int top;//
	int cap;

}stack, * pstack;

void Stack_Init(pstack ps);

void Stack_Push(pstack ps, stdatatype x);

void Stack_Pop(pstack ps);

stdatatype Stack_Top(pstack ps);

bool Stack_Empty(pstack ps);

int Stack_Size(pstack ps);

void Stack_Destory(pstack ps);

void Stack_Show(pstack ps);
