#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int n = 0, m = 0, k = 0;

	scanf("%d%d%d", &n, &m, &k);

	int arr[100][100] = { 0 };

	while (m--)
	{
		int x = 0,  y = 0;

		scanf("%d%d", &x, &y);

		int i = -1;
		
		
		arr[x - 1 + 2][y - 1] = 1;
		arr[x - 1 - 2][y - 1] = 1;

		for (i = -1; i < 2; i++)
		{
			arr[x - 1 + 1][y - 1 + i] = 1;
			arr[x - 1 - 1][y - 1 + i] = 1;
		}

		int j = -2;

		for (j = -2; j < 3; j++)
		{
			arr[x - 1][y - 1 + j] = 1;
		}


	}
	while (k--)
	{
		int x = 0, y = 0;
		scanf("%d%d", &x, &y);

		int i = -2;

		for (i = -2; i < 3; i++)
		{
			int j = -2;

			for (j = -2; j < 3; j++)
			{
				arr[x - 1 + i][y - 1 + j] = 1;


			}

		
		
		}
		



	}


	int i = 0, j = 0;
	int count = 0;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (arr[i][j] == 0)
			{
				count++;
			}

		}

	}
	

	printf("%d", count);






	return 0;
}