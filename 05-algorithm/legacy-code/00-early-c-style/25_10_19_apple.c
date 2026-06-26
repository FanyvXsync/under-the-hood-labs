#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int m = 0, t = 0, s = 0;
	int eaten = 0;
	scanf("%d%d%d", &m, &t, &s);
	if (t ==0)
	{
		printf("%d", t);



	}
	if (s % t == 0)
	{
		eaten = s / t;
		if (eaten > m)
		{

			printf("0");
		}
		printf("%d", (m - eaten));


	}
	else
	{
		eaten = s / t + 1;
		if (eaten > m)
		{
			printf("0");
		}
		printf("%d", (m - eaten));
		

	}
	return 0;







}
