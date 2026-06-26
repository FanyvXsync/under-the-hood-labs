#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "contact.h"


typedef peoinfo seqtype;

typedef struct SeqList
{
	seqtype* arr;
	int size;
	int cap;

}SE;



void init_seq(SE* ps);

void des_seq(SE* ps);

//≤Â»Î ∑¥≤Â

void broaden_sp(SE* ps);

void pushback(SE* ps, seqtype x);

void pushfront(SE* ps, seqtype x);

//void print_seq(SE s);

void popb(SE* ps);

void popf(SE* ps);

void insert_se(SE* ps, int pos, seqtype x);

void erase_se(SE* ps, int pos);
