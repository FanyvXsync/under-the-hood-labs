#pragma once


#define NAME_MAX 20
#define GENDER_MAX 10
#define NUMBER_MAX 20

#define ADDR_MAX 100

typedef struct contact
{
	char name[NAME_MAX];

	char gender[GENDER_MAX];

	char number[NUMBER_MAX];

	int age;

	char addr[ADDR_MAX];

}peoinfo;


typedef struct SeqList con;

void init_con(con* pc);

void des_con(con* pc);

//插入

//查找，删除，替换，展示

void insert_con(con* pc);

void delete_con(con* pc);

int find_s(con* pc, char* pn);

void check_con(con* pc);