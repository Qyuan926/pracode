#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void ADjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child<n)
	{
		if (child + 1<n&&a[child + 1] > a[child])
			child += 1;//ѡ��ֵ��ĺ���

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}

}

void HeapSort(int* a, int n)
{
	//�����
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		ADjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);

		ADjustDown(a, end, 0);
		--end;

	}
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
	if (nums == NULL || numsSize <= 0 || k <= 0)
	{
		*returnSize = 0;
		return NULL;
	}
	int* arr = (int*)malloc(sizeof(int)*k);


	int* ret = (int*)malloc(sizeof(int)*numsSize);
	*returnSize = 0;
	for (int i = 0; i <= numsSize - k; ++i)
	{
		memcpy(arr, nums + i, sizeof(int)*k);

		// �����򣬽����
		HeapSort(arr, k);
		//ȡ�Ѷ������ݣ���Ϊ���ֵ
		ret[(*returnSize)++] = arr[k - 1];
		//pop���Ѷ�������
		//push�������ݡ�ѭ��

	}
	free(arr);


	return ret;
}










int main()
{
	int nums[8] = { 1, 3, -1, -3, 5, 3, 6, 7 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int k = 3;
	int retSize = 0;

	int* ret = maxSlidingWindow(nums,numsSize,k,&retSize);
	for(int i= 0; i < retSize; ++i)
	{
		printf("%d  ", ret[i]);
	}
	printf("\n");

	return 0;
}