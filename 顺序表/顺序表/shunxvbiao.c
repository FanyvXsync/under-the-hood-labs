#define _CRT_SECURE_NO_WARNINGS 1

#include "seq.h"

void slinit(SL* ps)
{
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;


}


void sldestory(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
		
	}
	ps->arr = NULL;
	ps->size = ps->capacity = 0;

}

//尾插

void pushb(SL* ps, sldtype x)
{
	//首先开辟空间

	if (ps->capacity == ps->size)//看空间够不够
	{
		
		assert(ps);

		int newcap = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		sldtype *tmp = (sldtype*)realloc(ps->arr, newcap * 2 * sizeof(sldtype));

		if (tmp == NULL)
		{
			perror("realloc,fail");
			exit(1);//return 1;
		}

		ps->arr = tmp;
		ps->capacity = newcap;


	}
	
	
	
	ps->arr[ps->size++] = x;//画图,size就是最后一个的下标。

	//++ps->size;


}

//头插


void check_space(SL* ps)
{
	if (ps->capacity == ps->size)//看空间够不够
	{

		assert(ps);

		int newcap = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		sldtype* tmp = (sldtype*)realloc(ps->arr, newcap * 2 * sizeof(sldtype));

		if (tmp == NULL)
		{
			perror("realloc,fail");
			exit(1);//return 1;
		}

		ps->arr = tmp;
		ps->capacity = newcap;


	}
}




void pushf(SL* ps, sldtype x)
{
	assert(ps);
	check_space(ps);

	for (int i = ps->size;i>0 ; i--)
	{

		ps->arr[i] = ps->arr[i - 1];
	}

	ps->arr[0] = x;

	ps->size++;
	
}

void printsl(SL s)
{

	int i = 0;
	for (i = 0; i < s.size; i++)
	{
		printf("%d ", s.arr[i]);
	}


}


void popb(SL* ps)
{

	assert(ps);
	assert(ps->size);
	--ps->size;
	

}

void popf(SL* ps)
{


	assert(ps);
	assert(ps->size);

	for (int i = 0;i<ps->size-1; i++)//最后一次要是size-2
	{
		ps->arr[i] = ps->arr[i + 1];


	}

	--ps->size;
}

//在指定位置之前插入

void insert_seq (SL* ps, int pos, sldtype x)//pos 下标
{
	assert(ps);

	assert(pos >=  0 && pos<ps->size);

	check_space(ps);




}
