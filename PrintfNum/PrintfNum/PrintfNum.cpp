#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
bool increment(char* num)
{
	if (num == NULL)
		return 0;
	int length = strlen(num);
	int ntakeover = 0;//要进位的值
	for (int i = length - 1; i >= 0; --i)
	{
		int nsum = num[i] - '0' + ntakeover;
		if (i == length - 1)
		{
			nsum += 1;
		}

		if (nsum >= 10)
		{
			if (i == 0)
			{
				return true;
			}
			//要产生进位
			nsum -= 10;
			ntakeover = 1;
			num[i] = nsum + '0';
		}
		else
		{
			num[i] = nsum + '0';
			break;

		}
	}
	return false;
}
void   printfnum(char*num, int*  ret, int* Index)
{
	bool isbegin0 = true;
	int length = strlen(num);
	for (int i = 0; i<length; ++i)
	{
		if (isbegin0&&num[i] != '\0')
			isbegin0 = false;
		while (!isbegin0)
		{
			ret[(*Index)++] = atoi((const char*)num);
			return;
		}
		++num;
	}

}
int* printNumbers(int n, int* returnSize){

	if (n <= 0)
	{
		int* ret1 = (int*)malloc(sizeof(int));
		*returnSize = 0;
		return ret1;
	}
	int retSize = 1;
	for (int i = 0; i < n; ++i)
	{
		retSize *= 10;
	}
	int* ret = (int*)malloc(sizeof(int)*retSize);
	int Index = 0;
	*returnSize = retSize - 1;
	char* num = (char*)malloc(sizeof(char)*(n + 1));
	memset(num, '0', n + 1);
	num[n] = '\0';
	while (!increment(num))
	{
		printfnum(num, ret, &Index);
	}
	free(num);
	return ret;

}

int main()
{
	int n = 0;
	int* ret = printNumbers(1, &n);
	return 0;
}