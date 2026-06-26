#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int s1 = 0, s2 = 0, s3 = 0;
	scanf("%d%d%d", &s1, &s2, &s3);
	int arr[100] = { 0 };
	arr[0] = 100;
	int i = 0;
	int tmp = 0;
	int max = 100;
	for (i = 1; i <= s1; i++)
	{
		int j = 0;
		for (j = 1; j <= s2; j++)
		{
			int k = 0;
			for (k = 1; k <= s3; k++)
			{
				tmp = i + k + j;
				arr[tmp]++;
				
			}
		}

	}

	for (i = s1 + s2 + s3-1; i > 0; i--)
	{
		if (arr[i] < arr[i-1])
		{
			max = i;
		}

	}
	printf("%d", max);

	return 0;
}