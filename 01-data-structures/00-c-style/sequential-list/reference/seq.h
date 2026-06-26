#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "contact.h"

typedef pinfo sldtype;

typedef struct seqlist
{
	sldtype* arr;
	int size;
	int capacity;
	

}SL;

void slinit(SL* ps);//初始化  传地址

void sldestory(SL* ps);//销毁

//插入

void pushb(SL* ps, sldtype x);

void pushf(SL* ps, sldtype x);

void check_space(SL* ps);

void printsl(SL s);

//删除

void popb(SL* ps);

void popf(SL* ps);

void insert_seq(SL* ps, int pos, sldtype x);

void SLerase(SL* ps, int pos);