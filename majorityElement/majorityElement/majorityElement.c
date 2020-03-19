#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
int majorityElement1(int* nums, int numsSize){
	assert(nums&&numsSize>0);
	int result = nums[0];
	int times = 1;
	for (int i = 1; i<numsSize; ++i)
	{
		if (times == 0)
		{
			result = nums[i];
			times = 1;
		}
		else if (result == nums[i])
		{
			times++;
		}
		else
		{
			times -= 1;
		}
	}
	return result;
}

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

int majorityElement(int* nums, int numsSize){
	assert(nums&&numsSize>0);
	int mid = numsSize >> 1;
	int begin = 0;
	int end = numsSize - 1;
	int key = partation(nums, begin, end);
	while (key != mid)
	{
		if (key>mid)
		{
			end = key - 1;
			key = partation(nums, begin, end);
		}
		if (mid>key)
		{
			begin = key + 1;
			key = partation(nums, begin, end);
		}
	}
	return nums[key];
}

int main()
{
	int arr[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	int ret=majorityElement(arr, 9);
	//printf("%d", ret);
	return 0;
}