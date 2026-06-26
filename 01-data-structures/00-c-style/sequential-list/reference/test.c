#define _CRT_SECURE_NO_WARNINGS 1

#include "seq.h"

void sltest01()
{
	SL sl;
	slinit(&sl);

	pushb(&sl, 5);
	pushb(&sl, 6);

	

	printsl(sl);
	


	sldestory(&sl);
}


int main()
{
	sltest01();
	return 0;
}