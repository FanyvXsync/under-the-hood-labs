#pragma once


#define NAME_MAX 20
#define GENDER_MAX 10

#define TALE_MAX 20
//

#define ADD_MAX 100

typedef struct perinfo
{
	char name[NAME_MAX];
	
	char gender[GENDER_MAX];

	int age;
	
	char tale[TALE_MAX];

	char add[ADD_MAX];
}pinfo;



