#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int a = 1, b = 1;
	int arr[10000];
	int max = 0;
	for (i = 0; i < n; i++)
	{

		scanf("%d", &arr[i]);
	}
	i = 1;
	
	while (i<n)
	{
		for (i = i; i <= n - 1; i++)
		{
			
			if (arr[i]+1 != arr[i + 1])
			{
				
				break;
			}
			a++;

		}
		for (i = i+1; i <= n - 1; i++)
		{
			
			if (arr[i]+1 != arr[i + 1])
			{
				
				break;
			}
			b++;
				
		}
		max = a > b ? a : b;
		a = 1, b = 1;
		
		
	}
	printf("%d", max);





	
		
		

	



	return 0;
}