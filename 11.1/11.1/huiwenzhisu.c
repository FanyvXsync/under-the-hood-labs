#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int i = 0, j = 0, m = 0, p = 0, k = 0;
	for (i = a; i <= b; i++)
	{
		m = 0;
		for (j = 2; j <= i; j++)
		{
			if (i % j == 0)
			{
				m++;
				
			}
			if (m == 0)
			{
				p = (char)m;
				
				for (k = 1; k <= strlen(p); k++)
				{

				}

			}
		}
	}
	
		

	return 0;
}