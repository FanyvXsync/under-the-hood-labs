#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


void initboard(char arr[ROWS][COLS], int row, int col,char set)
{
	int i = 0;
	for (i = 0; i <ROWS; i++)
	{
		int j = 0;
		for (j = 0; j < COLS; j++)
		{
			arr[i][j] = set;
		}

	}


}

int minearound (int a,int b,char mine[ROWS][COLS],int row,int col)

{
	return mine[a - 1][b + 1] + mine[a][b + 1] + mine[a + 1][b + 1] + mine[a - 1][b]  + mine[a + 1][b] + mine[a - 1][b - 1] + mine[a][b - 1] + mine[a + 1][b - 1] - 8 * 48;







}














void printboard (char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	printf("--------扫雷游戏---------\n");
	for (i = 0; i <= COL; i++)
	{
		printf("%d ", i);

	}
	printf("\n");
	
	for (i = 1; i <= ROW; i++)
	{
		
		
		
		
		printf("%d ", i);
		int j = 0;
		for (j = 1; j <=COL; j++)
		{

			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	

}



void initmine(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int count = 0;
	while (count<=10)
	{
		int a = rand() % 9 + 1;
		int b = rand() % 9 + 1;
		if (arr[a][b] == '0')
		{
			arr[a][b] = '1';
			count++;
		}
		
	}
	
	
	
	
		


}

void start(char mine[ROWS][COLS], char show[ROWS][COLS],int row, int col)
{
	int a, b;
	int win = 0;
	while (win<=ROWS*COLS-10)
	{
		printf("请输入要排的坐标:>");
		scanf("%d %d", &a, &b);
		if ((a > 0 && a <= ROW) && (b > 0 && b <= ROW))
		{
			if (mine[a][b] == '1')
			{
				printf("很遗憾，你被炸死了！\n");
				break;
			}
			else
			{
				show[a][b] = (char)(minearound(a, b, mine, ROWS, COLS) + 48);
				win++;
				int i = 0;
				for (i = 0; i <= COL; i++)
				{
					printf("%d ", i);

				}
				printf("\n");

				for (i = 1; i <= ROW; i++)
				{




					printf("%d ", i);
					int j = 0;
					for (j = 1; j <= COL; j++)
					{

						printf("%c ", show[i][j]);
					}
					printf("\n");
				}


			}

		
			
			
			
			





		}
		else
			printf("输入错误，请重新输入:>\n");
	}
}