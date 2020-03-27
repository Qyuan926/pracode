#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void  _spiralOrder(int** matrix, int row, int col, int* ret, int* start, int* Index)
{
	int endX = col - 1 - *start;
	int endY = row - 1 - *start;

	//从左到右打印
	for (int i = *start; i <= endX; ++i)
	{
		ret[(*Index)++] = matrix[*start][i];
	}
	//最后一列从上到下
	if (*start<endY)
	{
		for (int j = *start + 1; j <= endY; ++j)
		{
			ret[(*Index)++] = matrix[j][endX];
		}
	}



	//最后一行从右到左
	if (*start<endX&&*start<endY)
	{
		for (int k = endX - 1; k >= *start; k--)
		{
			ret[(*Index)++] = matrix[endY][k];
		}
	}

	//第一列从下到上
	if (*start<endX&&*start<endY - 1)
	{
		for (int x = endY - 1; x>*start; --x)
		{
			ret[(*Index)++] = matrix[x][*start];
		}
	}

}
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
	if (matrixSize <= 0)
	{
		*returnSize = 0;
		return NULL;
	}
	int row = matrixSize;
	int col = *matrixColSize;
	int* ret = (int*)malloc(sizeof(int)*row*col);
	*returnSize = 0;
	int start = 0;
	int Index = 0;
	while (start * 2<row  && start * 2<col)
	{
		_spiralOrder(matrix, row, col, ret, &start, returnSize);
		++start;

	}
	return ret;

}


int main()
{
	int** matrix = (int**)malloc(sizeof(int*)* 3);
	int a1[3] = { 1, 2, 3 };
	int a2[3] = { 4, 5, 6 };
	int a3[3] = { 7, 8, 9 };
	matrix[0] = a1;
	matrix[1] = a2;
	matrix[2] = a3;
	int n = 0;
	int x = 3;
	int* ret=spiralOrder(matrix, 3,&x , &n);
	for (int i = 0; i < n; ++i)
		printf("%d ", ret[i]);
	return 0;
}