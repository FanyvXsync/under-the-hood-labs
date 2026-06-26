#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	double s = 0;
	int c = 0;
	double e = 2;
	double x = 0;
	scanf("%lf", &s);
	while (x < s)
	{
		x = x + e;
		e = e * 0.98;
		c++;
	}
	printf("%d", c);


	return 0;
}