//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	int a = 0, b = 0, c = 0, t = 0, m = 0;
//	scanf("%d%d%d", &a, &b, &c);
//	if (a > b)
//	{
//		t = a;
//		a = b;
//		b = t;
//	}
//	if (a > c)
//	{
//		t = a;
//		a = c;
//		c = t;
//	}
//	if (b > c)
//	{
//		t = b;
//		b = c;
//		c = t;
//	}
//	if (b + a <= c || c - b >= a || c - a >= b) {
//		printf("Not triangle\n");
//		return 0;
//	}
//	if (a * a + b * b == c * c)
//		printf("Right triangle\n");
//	else if (a * a + b * b > c * c)
//		printf("Acute triangle\n");
//	else if (a * a + b * b < c * c)
//		printf("Obtuse triangle\n");
//	if (c == b || b == a || c == a)
//		printf("Isosceles triangle\n");
//	if (c == b&&b==a)
//		printf("Equilateral triangle\n");
//	
//	return 0;
//}