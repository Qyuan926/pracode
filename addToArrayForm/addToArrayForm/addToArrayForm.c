#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
数组形式的整数加法
对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1, 2, 3, 1]。

给定非负整数 X 的数组形式 A，返回整数 X + K 的数组形式。
*/

int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
	if (K == 0)
	{
		*returnSize = ASize;
		return A;
	}
	if (A == NULL || ASize <= 0)
	{
		int* retk = (int*)malloc(sizeof(int)* 5);
		*returnSize = 5;
		int Index = *returnSize - 1;
		while (K>0)
		{
			retk[Index--] = K % 10;
			K /= 10;
		}
		*returnSize -= (Index + 1);
		return retk;
	}
	*returnSize = ASize >= 5 ? ASize + 1 : 5;
	int* ret = (int*)malloc(sizeof(int)*(*returnSize));
	memset(ret, 0, sizeof(int)*(*returnSize));
	int IndexA = ASize - 1;
	int Index = *returnSize - 1;
	while (IndexA >= 0)
	{
		ret[Index] += (K % 10 + A[IndexA]);
		if (ret[Index]>9)
		{
			ret[Index] %= 10;
			ret[Index - 1] = 1;
		}
		K = K / 10;
		Index--;
		IndexA--;
	}
	while (K>0)
	{
		ret[Index] += K % 10;
		if (ret[Index]>9)
		{
			ret[Index] %= 10;
			ret[Index - 1] = 1;
		}
		K = K / 10;
		--Index;
	}
	if (ret[0] == 0)
	{
		int i = 0;
		while (ret[i] == 0)
		{
			++i;
		}
		*returnSize = *returnSize - i;
		return ret + i;
	}
	return ret;
}

int main()
{//int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
	int A[] = { 0 };
	int ASize = sizeof(A) / sizeof(A[0]);
	int K = 10000;
	int returnSize = 0;
	 addToArrayForm(A, ASize,K, &returnSize);
	 printf("%d", returnSize);

	return 0;
}