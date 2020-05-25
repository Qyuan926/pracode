#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return;
		int length = matrix.size();
		for (int i = 0; i<length; ++i)
		{
			for (int j = i; j<length; ++j)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = tmp;
			}
		}

		for (int i = 0; i<length; ++i)
		{
			for (int j = 0; i<length / 2; ++j)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[i][length - j - 1];
				matrix[i][length - j - 1] = tmp;
			}
		}


	}
};

int main()
{
	vector<vector<int>> arr = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	Solution s;
	s.rotate(arr);
	return 0;
}