#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;



	void Backtrack(vector<vector<string>>&ret, vector<string>& board, size_t row)
	{
		//��������
		if (row == board.size())
		{
			ret.push_back(board);
			return;
		}

		for (size_t col = 0; col<board[row].size(); ++col)
		{
			//�ж����δ֪�Ƿ�Ϸ�
			if (isLaw(board, row, col))
			{
				//ѡ��·��
				board[row][col] = 'Q';
				//������һ��ѡ��
				Backtrack(ret, board, row + 1);
				//����ѡ��
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
		// ������Ϸ��Ƿ��лʺ����ͻ
		for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++)
		{
			if (board[i][j] == 'Q')
				return false;
		}
		// ������Ϸ��Ƿ��лʺ����ͻ
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
		{
			if (board[i][j] == 'Q')
				return false;
		}
		return true;
	}
	vector<vector<string>> solveNQueens(int n) {
		//��ʼ��һ��N*N������
		vector<string> board(n, string(n, '.'));
		//���з����ļ���
		vector<vector<string>>ret;
		Backtrack(ret, board, 0);
		return ret;
	}


