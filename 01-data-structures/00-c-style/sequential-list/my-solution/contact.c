#define _CRT_SECURE_NO_WARNINGS 1

#include "seq.h"


void init_con(con* pc)
{
	init_seq(pc);

}

void des_con(con* pc)
{
	des_seq(pc);
}


void insert_con(con* pc )
{
	peoinfo c1;
	printf("请输入姓名");
	scanf("%s", c1.name);

	printf("请输入性别");
	scanf("%s", c1.gender);

	printf("请输入电话号");
	scanf("%s", c1.number);

	printf("请输入年龄");
	scanf("%d", &c1.age);

	printf("请输入地址");
	scanf("%s", c1.addr);

	pushback(pc, c1);


}


int find_s(con* ps, char* pn)
{

	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->arr[i].name == pn)
		{
			return i;
		}
		
	}

	
	return -1;


}



void delete_con(con* pc)
{
	printf("请输入要删除的人的姓名");

	char* pn = NULL;
	scanf("%s", pn);

	int find = find_s(pc, pn);

	if (find >= 0)
	{
		erase_se(pc, find);

	}
	else
	{
		printf("该联系人不存在");
		return;
	}
	


}



void check_con(con* pc)
{
	printf("请输入要查找的人的姓名");

	char* pn = NULL;

	scanf("%s", pn);

	int find = find_s(pc, pn);

	printf("姓名 性别 年龄 电话号 地址\n");

	printf("%s ", pc->arr[find].name);
	printf("%s ", pc->arr[find].gender);
	printf("%d ", pc->arr[find].age);
	printf("%s ", pc->arr[find].number);
	printf("%s ", pc->arr[find].addr);




}


