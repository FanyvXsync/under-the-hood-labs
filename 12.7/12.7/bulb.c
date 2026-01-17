#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int n = 0,  t = 0;
//	
//	double a = 0;
//
//	int max_n = 0, x = 0;
//	
//	scanf("%d", &n);
//
//	char bulb[2000001] = { 0 };
//
//	while (n--)
//	{
//		scanf("%lf%d", &a, &t);
//
//		int i = 0;
//		for (i = 1; i <= t; i++)
//		{
//			
//			x = (int)floor(a * i);
//
//			/*if (bulb[x] == 0)
//			{
//				bulb[x] = 1;
//
//			}
//			else 
//			{
//				bulb[x] = 0;
//			
//			}*/
//			bulb[x] = 1 - bulb[x];
//
//			if (x > max_n)
//			{
//				max_n = x;
//			}
//		
//		
//		
//		}
//
//
//
//	}
//
//
//	int j = 0;
//	for (j = 1; j <=x; j++)
//	{
//		if (bulb[j] == 1)
//		{
//			printf("%d  \n", j);
//			break;
//		
//		}
//	
//	}
//
//
//
//
//	return 0;
//}


//
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//
//    
//    int bulb[2000001] = { 0 };
//
//    while (n--)
//    {
//        double a = 0;
//        int t = 0;
//        scanf("%lf%d", &a, &t);
//
//        for (int i = 1; i <= t; i++)
//        {
//            int x = (int)floor(a * i);
//            
//            bulb[x] ^= 1;
//        }
//    }
//
//    
//    for (int j = 1; j <= 2000000; j++)
//    {
//        if (bulb[j] == 1)
//        {
//            printf("%d\n", j);
//            break;
//        }
//    }
//
//    return 0;
//}


#include <stdio.h>

int main()
{
	printf("hehe\n");



	return 0;
}