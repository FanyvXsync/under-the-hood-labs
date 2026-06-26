#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


void hebing(int* nums1, int* nums2, int m, int n)
{
	int l1, l2, l3;
	l1 = m-1;
	l2 = n - 1;
	l3 = m + n - 1;

	while (l1 >= 0 && l2 >= 0)
	{
		if (nums1[l1] > nums2[l2])
		{
			nums1[l3--] = nums1[l1--];
			
			

		}
		else
		{
			nums1[l3--] = nums2[l2--];
			
			

		}

	}

	while (l2 >= 0)
	{
		nums1[l3--] = nums2[l2--];
		
		
	}

	



}


int main()
{



	return 0;
}