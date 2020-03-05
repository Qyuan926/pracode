#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int findRepeatNumber1(int* nums, int numsSize){
	int * Hash = (int*)malloc(sizeof(int)*numsSize);
	for (int i = 0; i<numsSize; ++i)
	{
		Hash[i] = 0;
	}
	for (int j = 0; j<numsSize; ++j)
	{
		int tmp = nums[j];
		if (Hash[tmp]>0)
		{
			return tmp;
		}
		++Hash[tmp];
	}
	return -1;

}
//������Ϊ��ϣ��   �ռ临�Ӷ�O��1��
int findRepeatNumber2(int* nums, int numsSize){
	for (int i = 0; i<numsSize; ++i)
	{
		while (nums[i] != i)//�����Ӧλ�ô������Ӧ�����֣�������
		{
			if (nums[i] == nums[nums[i]])
				//���Ŀǰλ�ú͹�ϣ���Ӧλ��������ͬ�����ҵ��ظ����ַ��أ���֮���򽻻���
			{
				return nums[i];
			}
			else
			{
				int tmp = nums[i];
				nums[i] = nums[tmp];
				nums[tmp] = tmp;
			}
		}
	}
	return -1;

}


int main()
{
	int arr[] = { 2, 3, 1, 0, 2, 5, 3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n",findRepeatNumber1(arr, len));
	printf("%d\n", findRepeatNumber2(arr, len));
	return 0;
}