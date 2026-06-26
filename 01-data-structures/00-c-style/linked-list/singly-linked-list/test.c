#define _CRT_SECURE_NO_WARNINGS 1

#include "sllist.h"


void test01()
{
	node* node1 = (node*)malloc(sizeof(SLDtype));

	node1->data = 1;

	

	node* node2 = (node*)malloc(sizeof(SLDtype));

	node2->data = 2;

	//Á´½Ó
	
	
	node1->next = node2;
	node2->next = NULL;

	node* plist = node1;

	slt_print(plist);

	PushBack(plist,5);
}

void test02()
{

	node* plist = NULL;

	/*PushBack(&plist,1);
	PushBack(&plist,2);
	PushBack(&plist,3);
	PushBack(&plist,4);*/
	
	PushFront(&plist, 1);
	PushFront(&plist, 2);


	PushBack(&plist, 6);

	//del_back(&plist);


	slt_print(plist);

}



int main()
{
	//test01();
	test02();

	return 0;
}