#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
������������ arr ���ҳ�������С�� k ���������磬����4��5��1��6��2��7��3��8��8�����֣�����С��4��������1��2��3��4��
*/

int partation(int* nums, int begin, int end)
{
	int key = nums[begin];
	while (begin<end)
	{
		while (begin<end&&nums[end]>key)
		{
			--end;
		}
		nums[begin] = nums[end];
		while (begin<end&&nums[begin] <= key)
		{
			++begin;
		}
		nums[end] = nums[begin];
	}
	nums[begin] = key;
	return begin;
}
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
	assert(arr&&arrSize>0 && k <= arrSize);

	if (k <= 0)
	{
		*returnSize = 0;
		return NULL;
	}

	int begin = 0;
	int end = arrSize - 1;
	int key = partation(arr, begin, end);
	while (key != k - 1)
	{
		if (key>k - 1)
		{
			end = key - 1;
			key = partation(arr, begin, end);
		}
		if (key<k - 1)
		{
			begin = key + 1;
			key = partation(arr, begin, end);
		}
	}
	int* retarr = (int*)malloc(sizeof(int)*k);
	for (int i = 0; i<k; ++i)
	{
		retarr[i] = arr[i];
	}
	*returnSize = k;
	return retarr;
}

int main()
{
	int arr[4] = { 0, 1, 2, 1 };
	int n = 0;
	int* ret=getLeastNumbers(arr, 4, 2, &n);
	return 0;
}