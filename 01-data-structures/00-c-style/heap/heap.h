#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HPDateType;  // 控制的还是数组，逻辑和物理不一样

typedef struct Heap
{
	HPDateType* a;
	int size;
	int capacity;
}HP;    // 想象成树，满足父亲和孩子对应的规则

void HPInit(HP* php);
void HPDestory(HP* php);
void HPPush(HP* php, HPDateType x);
void HPPop(HP* php);

HPDateType HPTop(HP* php);
bool HPEmpty(HP* php);

void AdjustUp(HPDateType* a, int child);
void AdjustDown(HPDateType* a, int parent, int n);

void Swap(HPDateType* s1, HPDateType s2);