#define _CRT_SECURE_NO_WARNINGS 1
if (c * c + mid * mid == max * max)
printf("Right triangle\n");
if (c * c + mid * mid > max * max)
printf("Acute triangle\n");
if (c * c + mid * mid < max * max)
	printf("Obtuse triangle\n");
if (max == mid || mid == c || max == c)
printf("Isosceles triangle\n");
if (max == mid == c)
printf("Equilateral triangle\n");