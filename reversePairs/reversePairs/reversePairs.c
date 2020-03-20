#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void  _reversePairs(int* nums, int begin, int end, int*tmp, int* count)
{
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;
	_reversePairs(nums, begin, mid, tmp, count);
	_reversePairs(nums, mid + 1, end, tmp, count);
	int begin1 = begin;
	int begin2 = mid + 1;
	int end1 = mid;
	int end2 = end;
	int Index = end;
	while (begin1 <= end1&&begin2 <= end2)
	{
		if (nums[end1]>nums[end2])
		{
			tmp[Index--] = nums[end1--];
			(*count) += (end2 - begin2 + 1);
		}
		else
		{
			tmp[Index--] = nums[end2--];
		}
	}
	while (begin1 <= end1)
	{
		tmp[Index--] = nums[end1--];
	}
	while (begin2 <= end2)
	{
		tmp[Index--] = nums[end2--];
	}

	memcpy(nums + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}


int reversePairs(int* nums, int numsSize){
	if (nums == NULL || numsSize <= 0)
		return 0;
	int count = 0;

	int* tmp = (int*)malloc(sizeof(int)*numsSize);
	_reversePairs(nums, 0, numsSize - 1, tmp, &count);
	free(tmp);
	return count;
}


int main()
{
	int arr[6] = { 1, 6, 3, 4, 5, 2 };
	reversePairs(arr, 6);
	return 0;
}