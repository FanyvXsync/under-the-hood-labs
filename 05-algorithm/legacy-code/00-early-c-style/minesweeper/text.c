#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{

	printf("*********************\n");
	printf("*****  1.play  ******\n");
	printf("*****  2.exit  ******\n");
	printf("*********************\n");
	

}

char mine[ROWS][COLS] = { 0 };
char show[ROWS][COLS] = { 0 };

void game()
{
	initboard(mine, ROWS, COLS, '0');
	initboard(show, ROWS, COLS, '*');
	initmine(mine, ROWS, COLS);
	printboard(show, ROWS, COLS);
	//printboard(mine, ROWS, COLS);
	
	
	start(mine,show,ROWS,COLS);

	
}









void test()
{

	int start = 0;
	do
	{
		menu();
		printf("请输入选项：>");
		scanf("%d", &start);
		switch (start)
		{
		case 1:
			//printf("游戏开始\n");
			
			
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，重新输入\n");
			break;


		}


	} while (start);

}

int main()
{
	srand((unsigned int)time(NULL));

	test();
	return 0;
}



