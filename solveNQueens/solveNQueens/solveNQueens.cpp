#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;



	void Backtrack(vector<vector<string>>&ret, vector<string>& board, size_t row)
	{
		//结束条件
		if (row == board.size())
		{
			ret.push_back(board);
			return;
		}

		for (size_t col = 0; col<board[row].size(); ++col)
		{
			//判断这个未知是否合法
			if (isLaw(board, row, col))
			{
				//选择路径
				board[row][col] = 'Q';
				//进入下一层选择
				Backtrack(ret, board, row + 1);
				//撤销选择
				board[row][col] = '.';
			}

		}
	}
	bool isLaw(vector<string> board, size_t row, size_t col)
	{

		for (size_t rows = 0; rows<row; ++rows)
		{
			if (board[rows][col] == 'Q')
			{
				return false;
			}
		}
		// 检查右上方是否有皇后互相冲突
		for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++)
		{
			if (board[i][j] == 'Q')
				return false;
		}
		// 检查左上方是否有皇后互相冲突
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
		{
			if (board[i][j] == 'Q')
				return false;
		}
		return true;
	}
	vector<vector<string>> solveNQueens(int n) {
		//初始化一个N*N的棋盘
		vector<string> board(n, string(n, '.'));
		//所有方案的集合
		vector<vector<string>>ret;
		Backtrack(ret, board, 0);
		return ret;
	}


