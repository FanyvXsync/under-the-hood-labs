#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	float a, b;
	
	scanf("%d%d", &a, &b);
	float c;
	c = a / b;
	c = c + 10;
	double d;
	d = 24 * 60 - c;
	d = d / 60.00;
	double e, f;
	e = d / 100;
	f = d % 1;
	peintf("%d:%d", e, f);
	return 0;



	







}