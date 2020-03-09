#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int ordinary(int* numbers, int numbersSize)
{
	int min = numbers[0];
	for (int i = 1; i<numbersSize; ++i)
	{
		if (min>numbers[i])
		{
			min = numbers[i];
		}
	}
	return min;
}
int minArray(int* numbers, int numbersSize){
	if (numbers == NULL || numbersSize <= 0)
		return;
	int index1 = 0;
	int index2 = numbersSize - 1;
	int index_mid = (index1 + index2) / 2;
	while (index1 <= index2)
	{

		//如果第一个数和第二个数相等，说明将前0个数进行旋转即还是原来的有序数组，第一个元素就是最小的数
		if (numbers[index1]<numbers[index2])
		{
			index_mid = index1;
			break;
		}
		else
		{
			if (index2 - index1 == 1)
			{
				index_mid = index2;
				break;
			}
			int index_mid = (index1 + index2) / 2;
			if (numbers[index1] == numbers[index2] && numbers[index1] == numbers[index_mid])
				return  ordinary(numbers, numbersSize);
			if (numbers[index1] <= numbers[index_mid])
			{
				index1 = index_mid;
			}
			if (numbers[index_mid] <= numbers[index2])
			{
				index2 = index_mid;
			}
		}
	}
	return numbers[index_mid];
}


int main()
{
	int arr[] = { 2, 2, 2, 0, 1 };
	printf("%d", minArray(arr, sizeof(arr) / sizeof(arr[0])));
	return 0;
}