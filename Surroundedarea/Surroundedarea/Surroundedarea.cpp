#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;



void dfs(vector<vector<char>>& board, int row, int col, int rows, int cols)
{
	vector<vector<int>> move = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	board[row][col] = '#';
	//cout<<row<<col<<endl;
	for (int i = 0; i<4; ++i)
	{
		int x = row+move[i][0];
		int y = col+move[i][1];
		if (x >= 0 && x<rows&&y >= 0 && y<cols)
		{

			if (board[x][y] == 'O')
				dfs(board, x, y, rows, cols);
		}
	}
}

	void solve(vector<vector<char>>& board) {
		if (board.empty())
		{
			return;
		}
		int rows = board.size();
		int cols = board[0].size();

		for (int i = 0; i<cols; ++i)
		{
			if (board[0][i] == 'O')
			{
				dfs(board, 0, i, rows, cols);
			}
			if (board[rows - 1][i] == 'O')
			{
				dfs(board, rows - 1, i, rows, cols);
			}
		}
		for (int i = 0; i<rows; ++i)
		{
			if (board[i][0] == 'O')
			{
				dfs(board, i, 0, rows, cols);
			}
			if (board[i][cols - 1] == 'O')
			{
				dfs(board, i, cols - 1, rows, cols);
			}
		}


		for (int i = 0; i<rows; ++i)
		{
			for (int j = 0; j<cols; ++j)
			{
				if (board[i][j] == 'O')
				{
					board[i][j] = 'X';
				}
				if (board[i][j] == '#')
				{
					board[i][j] = 'O';
				}
			}
		}

		for (int i = 0; i<rows; ++i)
		{
			for (int j = 0; j<cols; ++j)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		return;

	}




	int main()
	{
		vector<vector<char>> board = { { 'O', 'O', 'O' }, { 'O', 'O', 'O' }, { 'O', 'O', 'O' } };
		solve(board);
		

		return 0;
	}