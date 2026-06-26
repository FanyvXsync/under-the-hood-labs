#define _CRT_SECURE_NO_WARNINGS 1

#include "seq.h"

void init_seq(SE* ps)
{
	ps->arr = NULL;
	ps->size = 0;
	ps->cap = 0;

}


void des_seq(SE* ps)
{
	if (ps->arr)
	{
		free(ps->arr);

	}
	ps->arr = NULL;
	ps->size = 0;
	ps->cap = 0;

}


void broaden_sp(SE* ps)
{
	if (ps->cap == ps->size)
	{
		
		int newcap = ps->cap == 0 ? 4 : ps->cap * 2;
		
		seqtype* newarr = (seqtype*)realloc(ps->arr,newcap * sizeof(seqtype));

		if (newarr == NULL)
		{
			perror("ralloc,failed");
			exit(1);
		}

		ps->arr = newarr;
		ps->cap = newcap;
		


	}




}


//void broaden_sp(SE* ps)
//{
//	if (ps->cap == ps->size)
//	{
//		int newcap = ps->cap == 0 ? 4 : ps->cap * 2;
//		seqtype
//			* newarr = (seqtype*)realloc(ps->arr, newcap * sizeof(seqtype));
//
//		if (newarr == NULL)
//		{
//			perror("realloc failed");
//			exit(1);  // 修正：void函数不能return值
//		}
//
//		ps->arr = newarr;
//		ps->cap = newcap;
//	}
//}




void pushback(SE* ps, seqtype x)
{
	assert(ps);
	broaden_sp(ps);

	ps->arr[ps->size++] = x;

	




}



//void pushback(SE* ps, seqtype x)
//{
//	assert(ps);
//	broaden_sp(ps);
//	ps->arr[ps->size++] = x;
//}

void pushfront(SE* ps, seqtype x)
{

	assert(ps);

	broaden_sp(ps);

	int i = 0;

	for (i = ps->size; i >0 ; i--)
	{
		ps->arr[i] =ps-> arr[i-1];


	}
	ps->arr[0] = x;
	ps->size++;

}


//void print_seq(SE s)
//{
//	int i = 0;
//	for (i = 0; i < s.size; i++)
//	{
//
//		printf("%d ", s.arr[i]);
//
//	}
//
//
//
//
//}


//void print_seq(SE s)
//{
//	for (int i = 0; i < s.size; i++)
//	{
//		printf("%d ", s.arr[i]);
//	}
//	printf("\n");  // 建议加上换行
//}

void popb(SE* ps)
{
	assert(ps);

	ps->size--;




}


void popf(SE* ps)
{
	assert(ps);

	int i = 0;
	for (i = 0;i<ps->size-1; i++)
	{

		ps->arr[i] = ps->arr[i + 1];//

	}

	ps->size--;

		
}


void insert_se(SE* ps, int pos, seqtype x)
{

	assert(ps);

	assert(pos >= 0 && pos <= ps->size);

	broaden_sp(ps);

	int i = 0;
	for (i = ps->size;i>pos-1; i--)
	{
		ps->arr[i] = ps->arr[i - 1];


	}

	ps->arr[pos] = x;

	ps->size++;




}


void erase_se(SE* ps, int pos)
{
	assert(ps);

	assert(pos >= 0 && pos < ps->size);

	int i = 0;
	for (i = pos; i<ps->size; i++)
	{
		ps->arr[i] = ps->arr[i + 1];

	}

	ps->size--;


}
