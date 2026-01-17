#define _CRT_SECURE_NO_WARNINGS 1

//#if 0
//
//
//#include <stdio.h>
//int main()
//{
//	int s1 = 0, s2 = 0, s3 = 0;
//	scanf("%d%d%d", &s1, &s2, &s3);
//
//	int arr[81] = { 0 };
//
//	int i = 0;
//	
//	int tmp = 0, result = 3;
//
//	int max_count = 0;
//
//
//	for (i = 1; i <= s1; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= s2; j++)
//		{
//			int k = 0;
//			for (k = 1; k <= s3; k++)
//			{
//				tmp = i + k + j;
//				arr[tmp]++;
//			
//			
//			}
//		
//		
//		}
//	
//	
//	}
//
//	for (i = 3; i <= s1 + s2 + s3; i++)
//	{
//
//		if (arr[i] > max_count)
//		{
//			max_count = arr[i];
//			result = i;
//
//
//		}
//
//	
//	
//	}
//
//	printf("%d", result);
//
//
//
//
//	return 0;
//}
//
//#endif;