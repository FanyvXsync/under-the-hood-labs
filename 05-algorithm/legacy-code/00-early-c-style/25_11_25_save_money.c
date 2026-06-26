#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define give_eve_month 300

int main()
{
	int  budget = 0,  total_all_year = 0, remian_las_month = 0, n = 0, remian_this_month = 0;
	int i = 0;
	double total = 0;
	for (i = 0; i < 12; i++)
	{
		scanf("%d", &budget);
		if (budget > (give_eve_month +remian_las_month))
		{
			printf("%d", (i + 1) * (-1));
			return 0;
		}
		else
		{
			remian_this_month = give_eve_month - budget + remian_las_month;
			
			if (remian_this_month >= 100)
			{
				n = remian_this_month / 100;
				remian_las_month =remian_this_month % 100;
				total_all_year += n * 100;
			}
			else
			{
				remian_las_month = remian_this_month;
			}
			
			
			if (i == 11)
			{
				total = total_all_year * 1.2 + remian_las_month;

				printf("%.0f", total);
			}
		
		
		}
		

	}
	


	return 0;
}