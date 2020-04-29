#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
��һ�� m*n �����̵�ÿһ�񶼷���һ�����ÿ�����ﶼ��һ���ļ�ֵ����ֵ���� 0��
������Դ����̵����Ͻǿ�ʼ�ø�����������ÿ�����һ��������ƶ�һ��ֱ���������̵����½ǡ�
����һ�����̼������������ļ�ֵ���������������õ����ټ�ֵ�����
���� :
[
[1, 3, 1],
[1, 5, 1],
[4, 2, 1]
]
��� : 12
���� : ·�� 1��3��5��2��1 �����õ�����ֵ������*/
//�ռ临�Ӷ�O(m*n)
	int maxValue(vector<vector<int>>& grid)
	{
		if (grid.empty() || grid[0].empty())
		{
			return 0;
		}
		int rows = grid.size();
		int cols = grid[0].size();
		vector<vector<int>> dp(rows, vector<int>(cols, 0));
		dp[0][0] = grid[0][0];
		for (size_t i = 1; i<cols; ++i)
		{
			dp[0][i] = grid[0][i] + dp[0][i - 1];
		}
		for (size_t j = 1; j<rows; ++j)
		{
			dp[j][0] = grid[j][0] + dp[j - 1][0];
		}
		for (size_t i = 1; i<rows; ++i)
		{
			for (size_t j = 1; j<cols; ++j)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
			}
		}
		return dp[rows - 1][cols - 1];
	}

	//�ռ临�Ӷ�O(n)

int maxValue(vector<vector<int>>& grid) {
	if (grid.empty() || grid[0].empty())
	{
		return 0;
	}

	int n = grid[0].size();
	vector<int> dp(n, 0);
	//����һ�������ֵ��������
	for (size_t row = 0; row<grid.size(); ++row)
	{
		for (size_t col = 0; col<n; ++col)
		{
			if (row == 0)
			{
				if (col == 0)
					dp[0] = grid[0][0];
				else
					dp[col] = grid[0][col] + dp[col - 1];
			}
			if (row>0 && col == 0)
			{
				dp[0] = dp[0] + grid[row][0];
			}
			if (row>0 && col>0)
			{
				dp[col] = max(dp[col], dp[col - 1]) + grid[row][col];
			}
		}

	}
	return dp[n - 1];



}
