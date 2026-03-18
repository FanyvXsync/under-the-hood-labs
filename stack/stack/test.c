#define _CRT_SECURE_NO_WARNINGS 1

#include "stack.h"


void test1()
{
	pstack ps = (pstack)malloc(sizeof(stack));

	Stack_Init(ps);

	Stack_Push(ps, 1);
	Stack_Push(ps, 2);
	Stack_Push(ps, 3);
	Stack_Push(ps, 4);

	Stack_Show(ps);

}




int main()
{
	test1();
	return 0;
}