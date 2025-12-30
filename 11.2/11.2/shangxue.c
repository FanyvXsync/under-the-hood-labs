#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
	double s, v;
	scanf("%lf%lf", &s, &v);
	int z = (int)ceil(s / v) + 10;
	int d = 480 - z;
	if (d < 0)
	{
		d = d + 24 * 60;


	}
	int xiaoshi = d / 60;
	int fenzhong = d % 60;
	printf("%02d:%02d", xiaoshi, fenzhong);


	return 0;
}
