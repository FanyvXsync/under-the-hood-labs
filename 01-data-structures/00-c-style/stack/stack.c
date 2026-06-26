#define _CRT_SECURE_NO_WARNINGS 1

#include "stack.h"

void Stack_Init(pstack ps)
{
	assert(ps);
	
	ps->a = NULL;
	ps->top = 0;
	ps->cap = 0;

}

void Stack_Push(pstack ps, stdatatype x)
{
	assert(ps);

	
	int newcap = 0;

	if (ps->cap == ps->top)
	{
		newcap = ps->cap == 0 ? 4 : ps->cap * 2;
		stdatatype * tmp = (stdatatype*)realloc(ps->a, sizeof(stdatatype) * newcap);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps->a = tmp;
	}

	ps->a[ps->top] = x;
	ps->cap = newcap;
	ps->top++;

}

void Stack_Pop(pstack ps)
{
	assert(ps && ps->top);

	ps->top--;
}

stdatatype Stack_Top(pstack ps)
{
	assert(ps && ps->top);

	return ps->a[ps->top - 1];


}

bool Stack_Empty(pstack ps)
{
	assert(ps);

	return ps->top;
}

int Stack_Size(pstack ps)
{
	assert(ps);

	return ps->top;
}

void Stack_Destory(pstack ps)
{
	free(ps->a);
	ps->a = NULL;
	

	ps->cap = 0;
	ps->top = 0;
}

void Stack_Show(pstack ps)
{
	while (ps->top--)
	{
		printf("%d", ps->a[ps->top]);
	}
}