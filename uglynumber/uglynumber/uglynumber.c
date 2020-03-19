#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


int min(int x1, int x2, int x3)
{
	int min = x1>x2 ? x2 : x1;
	min = x3>min ? min : x3;
	return min;

}


int nthUglyNumber(int n){
	if (n <= 0)
	{
		return 0;
	}
	int* ret = (int*)malloc(sizeof(int)*n);
	ret[0] = 1;
	int Index = 1;
	int*Index_2 = ret;
	int*Index_3 = ret;
	int*Index_5 = ret;
	while (Index < n)
	{
		ret[Index] = min(*Index_2 * 2, *Index_3 * 3, *Index_5 * 5);

		while (*Index_2 * 2 <= ret[Index])
			++Index_2;
		while (*Index_3 * 3 <= ret[Index])
			++Index_3;
		while (*Index_5 * 5 <= ret[Index])
			++Index_5;

		++Index;

	}
	int uglynumber = ret[Index - 1];
	free(ret);
	return uglynumber;

}