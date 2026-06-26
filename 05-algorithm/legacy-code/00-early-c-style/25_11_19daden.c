#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n = 0, i = 0;
	int arr[1000];
	scanf("%d", &n);
	for (i = 0; i <n; i++)
	{
		scanf("%d", &arr[i]);

	}
	int max = 0, min = 0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] >= max)
			max = arr[i];
		if (arr[i] <= min)
			min = arr[i];

	}
	int j = 0;
	for (j = 0; j < n; j++)
	{
		if (max == arr[j])
		{
			arr[j] = 0;
			break;
		}

	}
	for (j = 0; j < n; j++)
	{
		if (min == arr[j])
		{
			arr[j] = 0;
			break;
		}

	}

	double x = 0;
	int c = 0;
	for (i = 0; i < n; i++)
	{
		c = c + arr[i];
	}
	x = c * 1.0 / (n - 2);
	printf("%.2f", x);


	return 0;
}