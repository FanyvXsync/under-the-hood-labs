#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	char arr[14];
	scanf("%s", arr);
	int k = 0;
	k = ((arr[0]-48) * 1 + (arr[2]-48) * 2 + (arr[3]-48) * 3 + (arr[4]-48) * 4 + (arr[6]-48) * 5 + (arr[7]-48) * 6 + (arr[8]-48) * 7 + (arr[9]-48) * 8 + (arr[10]-48) * 9) % 11;
	if (k==10)
	{
		if (arr[12]=='X')
			printf("Right");
		else
		{
			arr[12] = 'X';
			printf("%s", arr);
		}
	}
	else if (k == arr[12]-48)
	{
		printf("Right");

	}
	else
	{
		arr[12] = k + 48;
		printf("%s", arr);
	}





	return 0;
}
