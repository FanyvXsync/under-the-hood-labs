#define _CRT_SECURE_NO_WARNINGS 1

#include "queue.h"

void test()
{
	pQueue q = (pQueue)malloc(sizeof(Queue));

	QueueInit(q);
	QueuePush(q, 1);
	QueuePush(q, 2);
	QueuePush(q, 3);
	QueuePush(q, 4);
	QueuePush(q, 5);
	QueuePop(q);

	int c = QueueSize(q);

	printf("%d", c);



}




int main()
{
	test();
	return 0;
}