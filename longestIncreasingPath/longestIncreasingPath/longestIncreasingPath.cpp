﻿#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
矩阵中的最长递增路径
给定一个整数矩阵，找出最长递增路径的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。

示例 1:

输入: nums =
[
[9,9,4],
[6,6,8],
[2,1,1]
]
输出: 4
解释: 最长递增路径为 [1, 2, 6, 9]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
vector<vector<int>> move = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
//记忆化数组的搜索算法
int dfs(vector<vector<int>>& matrix, int row, int col, int rows, int cols, vector<vector<int>>&    visited)
{
	if (visited[row][col] != 0)
		return visited[row][col];
	++visited[row][col];
	for (int i = 0; i<4; ++i)
	{
		int x = row + move[i][0];
		int y = col + move[i][1];
		if (x >= 0 && x<rows&&y >= 0 && y<cols&&matrix[x][y]>matrix[row][col])
		{
			visited[row][col] = max(visited[row][col], dfs(matrix, x, y, rows, cols, visited) + 1);
		}
	}
	return visited[row][col];
}

	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return 0;

		int rows = matrix.size();
		int cols = matrix[0].size();

		int ret = 0;
		vector<vector<int>> visited(rows, vector<int>(cols, 0));
		for (int i = 0; i<rows; ++i)
		{
			for (int j = 0; j<cols; ++j)
			{

				ret = max(ret, dfs(matrix, i, j, rows, cols, visited));
			}
		}
		return ret;
	}