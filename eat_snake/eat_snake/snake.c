#define _CRT_SECURE_NO_WARNINGS 1

#include "snake.h"

void Set_cursor_P(int x, int y)
{

	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD pos = { x,y };

	CONSOLE_CURSOR_INFO cursor;

	GetConsoleCursorInfo(output, &cursor);
	cursor.bVisible = false;
	
	SetConsoleCursorInfo(output, &cursor);

	SetConsoleCursorPosition(output, pos);

}


void Print_Map()
{
	int i = 0;
	Set_cursor_P(0, 0);
	for (i = 0; i < 58; i++)
	{	
		wprintf(L"%lc",WALL);
	}
	Set_cursor_P(0, 26);
	for (i = 0; i < 58; i++)
	{
		wprintf(L"%lc", WALL);
	}

	for (i = 1; i < 26; i++)
	{
		Set_cursor_P(0, i);
		wprintf(L"%lc", WALL);
	}

	for (i = 1; i < 26; i++)
	{
		Set_cursor_P(57, i);
		wprintf(L"%lc", WALL);
	}


}

void Print_Help()
{
	Set_cursor_P(70, 15);
	wprintf(L"%ls", L"按F3加速，F4减速");

	Set_cursor_P(70, 16);
	wprintf(L"%ls", L"用↑，↓，←，→来控制蛇的方向");

	Set_cursor_P(70, 17);
	wprintf(L"%ls", L"按↑，↓，←，→来控制方向");
	Set_cursor_P(70, 18);
	wprintf(L"%ls", L"按esc退出，按空格暂停");


}







void Snake_Init(psnake ps)
{
	int i = 0;

	ps->p_snake=(psnakenode)malloc(sizeof(snakenode));
	
	
	if (ps->p_snake == NULL)
	{
		perror("fail");
		return;
	}
	ps->p_snake->x = POS_X;
	ps->p_snake->y = POS_Y;
	ps->p_snake->next = NULL;

	psnakenode pnode = NULL;

	for(i=0;i<4;i++)
	{
		 pnode = (psnakenode)malloc(sizeof(snakenode));

		if (pnode == NULL)
		{
			perror("Snake_Init::malloc::()");
			exit(1);
		}
		
		pnode->x = POS_X + 2 * (i+1);
		pnode->y = POS_Y;
		pnode->next = NULL;

		pnode->next = ps->p_snake;
		ps->p_snake = pnode;
	
	
	}
	

	

	ps->dir_snake = RIGHT;
	ps->food_weight = 10;
	ps->score_a = 0;
	ps->sleep_t = 200;
	ps->st_game = OK;
	


}



void Print_Snake(psnake ps)
{
	psnakenode pcur = ps->p_snake;
	
	while (pcur)
	{
		Set_cursor_P(pcur->x, pcur->y);
		
		
		wprintf(L"%lc", BODY);
		
		pcur = pcur->next;

	}
	


}


void Print_Food(psnake ps)
{
	int x = 0;
	int y = 0;
	
again :	
	do
	{
		x = rand() % 53 + 2;
		y = rand() % 25 + 1;
	
	} while (x % 2 != 0);

	//x和y的坐标不能和蛇冲突
	psnakenode pcur = ps->p_snake;
	while (pcur)
	{
		if (x == pcur->x && y == pcur->y)
		{
			goto again;
		}

		pcur = pcur->next;
	}


	psnakenode pfood = (psnakenode)malloc(sizeof(snakenode));
	
	if (pfood==NULL)
	{
		perror("pfood()::malloc");
		return;

	}
	
	pfood->x = x;
	pfood->y = y;
	pfood->next=NULL;

	Set_cursor_P(pfood->x, pfood->y);
	wprintf(L"%lc", FOOD);

	ps->p_food = pfood;
}



//void SnakeMove(psnake ps)
//{
//	while (ps->st_game == OK)
//	{
//		if (ps->p_food->x == ps->p_snake->x && ps->p_food->y == ps->p_snake->y)
//		{
//			ps->p_food->next = ps->p_snake;
//			ps->p_snake = ps->p_food;
//
//		}
//		else
//		{
//			psnakenode pn = (psnakenode)malloc(sizeof(snakenode));
//			pn->next = ps->p_snake;
//			ps->p_snake = pn;
//
//			psnakenode ptail = ps->p_snake;
//			while (ptail->next->next)
//			{
//				ptail = ptail->next;
//			}
//			free(ptail);
//			ptail = NULL;
//
//			Print_Snake(ps);
//
//
//		}
//		
//		Sleep(ps->sleep_t);
//	
//	}
//
//
//}



void Game_Init(psnake ps)
{
	system("title 贪吃蛇");
	system("mode con cols=100 lines=29");

	//打印
	Set_cursor_P(50, 13);
	wprintf(L"欢迎来到贪吃蛇小游戏\n");
	Set_cursor_P(50, 16);

	system("pause");

	system("cls");

	Set_cursor_P(42, 13);
	wprintf(L"按F3加速，F4减速，加速获得的分数更多");
	Set_cursor_P(42, 15);
	wprintf(L"按↑，↓，←，→来控制方向");


	Set_cursor_P(42, 17);
	system("pause");
	system("cls");

	Print_Map();

	Print_Help();

	//创建蛇；
	Snake_Init(ps);

	//打印蛇
	Print_Snake(ps);

	//打印食物
	Print_Food(ps);


}



int Next_Food(psnakenode pn, psnake ps)
{
	return (pn->x == ps->p_food->x && pn->y == ps->p_food->y);

}

void Eat_Food(psnakenode pn, psnake ps)
{
	ps->p_food->next = ps->p_snake;
	ps->p_snake = ps->p_food;

	free(pn);
	pn = NULL;

	psnakenode pcur = ps->p_snake;

	while (pcur)
	{
		
		Set_cursor_P(pcur->x, pcur->y);
		wprintf(L"%lc", BODY);
		pcur = pcur->next;
		

	}

	ps->score_a += ps->food_weight;

	Print_Food(ps);

}


void No_Food(psnakenode pn, psnake ps)
{
	pn->next = ps->p_snake;
	ps->p_snake = pn;

	psnakenode ptail = ps->p_snake;

	while (ptail->next->next)
	{
		Set_cursor_P(ptail->x, ptail->y);
		wprintf(L"%lc", BODY);
		
		ptail = ptail->next;
	}

	Set_cursor_P(ptail->next->x, ptail->next->y);
	printf("  ");

	free(ptail->next);
	ptail->next = NULL;

	


}

void Kill_Wall(psnake ps)
{
	if (ps->p_snake->x == 0 || ps->p_snake->x == 58 || ps->p_snake->y == 0 || ps->p_snake->y == 26)
	{
		ps->st_game = KILL_BY_WALL;
		
	}

}


void Kill_Self(psnake ps)
{
	psnakenode cur = ps->p_snake->next;

	while (cur)
	{
		if (ps->p_snake->x == cur->x && ps->p_snake->y == cur->y)
		{
			ps->st_game = KILL_BY_SELF;
			break;
		}
		cur = cur->next;
	}


}




void Snake_Move(psnake ps)
{
	psnakenode pnext = (psnakenode)malloc(sizeof(snakenode));

	if (pnext == NULL)
	{
		perror("Snake_Move()::malloc()");
		return;
	}


	
	switch (ps->dir_snake)
	{
	case UP:
		pnext->x = ps->p_snake->x;
		pnext->y = ps->p_snake->y - 1;
		break;
	case DOWN:
		pnext->x = ps->p_snake->x;
		pnext->y = ps->p_snake->y + 1;
		break;
	case LEFT:
		pnext->x = ps->p_snake->x-2;
		pnext->y = ps->p_snake->y;
		break;
	case RIGHT:
		pnext->x = ps->p_snake->x+2;
		pnext->y = ps->p_snake->y;
		break;
	
	}

	if (Next_Food(pnext, ps))
	{
		Eat_Food(pnext, ps);

	}
	else
	{
		No_Food(pnext, ps);
	}


	Kill_Wall(ps);

	Kill_Self(ps);


}







void pause()
{
	while (1)
	{
		Sleep(200);
		if (KEY_PRESS(VK_SPACE) == 0)
		{
			break;
		}
	}


}


void Game_Run(psnake ps)
{
	do
	{
		Set_cursor_P(70, 10);
		printf("总分%d", ps->score_a);
		Set_cursor_P(70, 11);
		printf("每个食物的分数%2d", ps->food_weight);

		if (KEY_PRESS(VK_UP)&&ps->dir_snake!=DOWN)
		{
			ps->dir_snake = UP;
		}
		else if (KEY_PRESS(VK_DOWN) && ps->dir_snake != UP)
		{
			ps->dir_snake = DOWN;
		}
		else if (KEY_PRESS(VK_LEFT) && ps->dir_snake != RIGHT)
		{
			ps->dir_snake = LEFT;
		}
		else if (KEY_PRESS(VK_RIGHT) && ps->dir_snake != LEFT)
		{
			ps->dir_snake = RIGHT;
		}
		else if (KEY_PRESS(VK_SPACE))
		{
			pause();
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			ps->st_game = EXIT_NORMAL;
		}
		else if (KEY_PRESS(VK_F3))
		{
			if (ps->sleep_t > 0)
			{
				ps->sleep_t -=30;

				ps->food_weight += 2;

			}
		}
		else if (KEY_PRESS(VK_F4))
		{
			if (ps->sleep_t < 320)
			{
				ps->sleep_t += 30;
				ps->food_weight -= 2;
			}
		}

		Snake_Move(ps);
		Sleep(ps->sleep_t);


	} while (ps->st_game==OK);


	


	

	
	
	



}


void Game_End(psnake ps)
{
	Set_cursor_P(15, 50);
	
	switch (ps->st_game)
	{
	case EXIT_NORMAL:
		printf("退出游戏");
		break;
	case KILL_BY_SELF:
		printf("撞到了自己，游戏结束");
		break;
	case KILL_BY_WALL:
		printf("撞到了墙，游戏结束");
		break;

	}
	
	psnakenode cur = ps->p_snake;
	while (cur)
	{
		psnakenode del = cur;
		cur = cur->next;
		free(del);
	}

}

