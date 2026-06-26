#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//
//
//int  remove_num(int* nums, int numsize, int val)
//{
//	int src = 0, dst = 0;
//
//	int tmp = 0;
//
//	while (src < numsize)
//	{
//		if (nums[src] != val)
//		{
//			nums[dst] = nums[src];
//			dst++;
//		}
//		src++;
//	
//	}
//	return dst;
//
//}
//
//
//int main()
//{
//	int nums[100] = { 0 };
//	int i = 0;
//	int n = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &nums[i]);
//	}
//	int val = 3;
//	int ret=remove_num(nums,n,val);
//
//	int j = 0;
//	for (j = 0; j < n; j++)
//	{
//		printf("%d", nums[j]);
//	}
//
//	return 0;
//}