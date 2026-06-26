#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a = 0, b = 0, c = 0;
	scanf("%d%d%d", &a, &b, &c);
	int  p= 0;
	p = a * 0.2 + b * 0.3 + c * 0.5;
	printf("%d", p);
	return 0;



}