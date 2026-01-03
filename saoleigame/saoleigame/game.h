#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2


void initboard(char arr[ROWS][COLS], int row, int col,char set);


void printboard(char arr[ROWS][COLS],int row, int col);

void initmine(char arr[ROWS][COLS], int row, int col);
 
void start(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);