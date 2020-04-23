#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//地上有一个m行n列的方格，从坐标[0, 0] 到坐标[m - 1, n - 1] 。一个机器人从坐标[0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格[35, 37] ，因为3 + 5 + 3 + 7 = 18。但它不能进入方格[35, 38]，因为3 + 5 + 3 + 8 = 19。请问该机器人能够到达多少个格子？

void move(vector<vector<int>>& rountine, int* ret, int row, int col, int m, int n, int k)
{
	//检验是否在方格里面，不在返回，在继续执行
	if (!((row >= 0 && row<m) && (col >= 0 && col<n)))
	{
		return;
	}
	if ((row % 10 + row / 10 + col % 10 + col / 10)>k)
	{
		return;
	}

	if (rountine[row][col] == 1)
		return;

	rountine[row][col] = 1;
	(*ret)++;


	move(rountine, ret, row - 1, col, m, n, k);//上
	move(rountine, ret, row + 1, col, m, n, k);//下
	move(rountine, ret, row, col - 1, m, n, k);//左
	move(rountine, ret, row, col + 1, m, n, k);//右
}
int movingCount(int m, int n, int k) {
	//将整个地图（m*n）记录下来
	vector<vector<int>>rountine(m, vector<int>(n, 0));

	int ret = 0;
	move(rountine, &ret, 0, 0, m, n, k);
	return ret;
}


int main()
{
	cout<<movingCount(2, 3, 1)<<endl;
	return 0;
}