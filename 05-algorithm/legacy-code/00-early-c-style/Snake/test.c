#define _CRT_SECURE_NO_WARNINGS 1


#include "snake.h"

void test()
{
	int ch = 0;
	//初始化游戏
	do
	{

		system("cls");

		psnake snake_a = (psnake)malloc(sizeof(snake));

		Game_Init(snake_a);

		Game_Run(snake_a);

		Game_End(snake_a);

		Set_cursor_P(50, 19);
		
		printf("要再来一次吗？（Y/N）：");
		
		ch = getchar();
		
		while (getchar() != '\n');

		system("cls");

	} while (ch == 'Y' || ch == 'y');

	Set_cursor_P(0, 27);
}



int main()
{
	setlocale(LC_ALL, "");

	srand((unsigned int)time(NULL));

	test();

	



	return 0;
}