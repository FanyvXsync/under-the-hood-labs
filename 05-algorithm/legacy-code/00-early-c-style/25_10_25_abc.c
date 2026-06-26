#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int a, b, c;
//	scanf("%d%d%d", &a, &b, &c);
//	char arr[20];
//	scanf("%s", arr);
//	int max = 0, mid = 0, min = 0;
//	max = a > b ? a : b;
//	max = max > c ? max : c;
//	min = a < b ? a : b;
//	min = min < c ? min : c;
//	
//	if (a<max && a>min)
//		mid = a;
//	else if (b<max && b>min)
//		mid = b;
//	else if (c<max && c>min)
//		mid = c;
//	if (strcmp(arr, "ABC") == 0)
//		printf("%d %d %d ", min, mid, max);
//	else if (strcmp(arr, "BAC") == 0)
//		printf("%d %d %d ", mid, min, max);
//	else if (strcmp(arr, "CAB") == 0)
//		printf("%d %d %d ", max, min, mid);
//	else if (strcmp(arr, "CBA") == 0)
//		printf("%d %d %d ", max, mid, min);
//	else if (strcmp(arr, "CAB") == 0)
//		printf("%d %d %d ", max,min, mid);
//	else if (strcmp(arr, "BCA") == 0)
//		printf("%d %d %d ", mid, max, min);
//	else if (strcmp(arr, "ACB") == 0)
//		printf("%d %d %d ", min, max, mid);
//
//
//	
//	return 0;
//
//
//
//
//
//
//}