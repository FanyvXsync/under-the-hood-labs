#pragma once

#include <stdio.h>
#include <stdlib.h>

#include <windows.h>
#include <stdbool.h>

#include <time.h>

#include <locale.h>


#define WALL L'□'
#define BODY L'●'
#define FOOD L'★'

#define POS_X 24
#define POS_Y 6

#define KEY_PRESS(vk) (GetAsyncKeyState(vk)&1?1:0)
#define add(x,y) x+y

enum DERCTION
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

enum GAME_STATUS
{
	OK,
	KILL_BY_WALL,
	KILL_BY_SELF,
	EXIT_NORMAL

};



typedef struct snakenode
{
	int x;
	int y;
	struct snakenode* next;

}snakenode,*psnakenode;


typedef struct snake
{
	psnakenode p_snake;
	psnakenode p_food;
	enum DERCTION dir_snake;
	enum GAME_STATUS st_game;
	int food_weight;
	int score_a;
	int sleep_t;

}snake,* psnake;

//调整屏幕大小
//打印一下欢迎界面
void Game_Init(psnake ps);

void Set_cursor_P(int x, int y);

void Print_Map();

void Print_Help();

void Game_Run(psnake ps);

void Snake_Init(psnake ps);

void Print_Snake(psnake ps);

void Print_Food(psnake ps);

//void SnakeMove(psnake ps);

void Game_End(psnake ps);

