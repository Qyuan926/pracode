#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
Z 字形变换
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
*/

namespace Solution1{
	string convert1(string s, int numRows) {
		if (numRows == 1)
		{
			return s;
		}
		int Cols = s.size();
		int Rows = min(numRows, Cols);
		vector<vector<char>> arr(Rows, vector<char>(Cols, '0'));
		bool Down = true;
		bool Up = false;
		int Index = 0;
		int row = 0;
		int col = 0;
		while (Index<s.size())
		{
			while (Down&&Index<s.size())
			{
				while (row<Rows)
				{
					arr[row][col] = s[Index];
					Index++;
					if (Index >= s.size())
						break;
					row++;
				}

				Up = true;
				Down = false;
				col++;

			}

			while (Up&&Index<s.size())
			{
				while (row == Rows || row == Rows - 1)
				{
					--row;
				}
				while (row != 0)
				{
					arr[row][col] = s[Index];
					Index++;
					if (Index >= s.size())
						break;
					row--;
					col++;
				}
				if (row == 0)
				{
					Down = true;
					Up = false;
					col++;
				}
			}
		}
		string ret = "";
		for (size_t rows = 0; rows<Rows; ++rows)
		{
			for (size_t cols = 0; cols<Cols; ++cols)
			{
				if (arr[rows][cols] != '0')
				{
					ret += arr[rows][cols];
				}
			}
		}

		return ret;
	}
	/*
	L   C   I   R
	E T O E S I I G
	E   D   H   N
	*/


	string convert2(string s, int numRows) {
		if (numRows == 1)
		{
			return s;
		}
		int Rows = min(numRows, (int)s.size());
		vector<string> arr(Rows);
		bool Down = true;
		bool Up = false;
		int Index = 0;
		int row = 0;

		while (Index<s.size())
		{
			while (Down&&Index < s.size())
			{
				arr[row] += s[Index];
				row++;
				Index++;
				if (Index >= s.size())
					break;
				if (row == Rows)
				{
					Down = false;
					Up = true;
				}
			}
			while (Up&&Index < s.size())
			{
				while (row >= Rows - 1)
				{
					--row;
				}
				while (row != 0)
				{
					arr[row] += s[Index];
					row--;
					Index++;
					if (Index >= s.size())
						break;
				}
				if (row == 0)
				{
					Down = true;
					Up = false;
				}
			}
		}
		string ret = "";
		for (size_t i = 0; i < Rows; ++i)
		{
			ret += arr[i];
		}
		return ret;
	}
	string convert(string s, int numRows) {
		if (numRows == 1)
		{
			return s;
		}
		int Rows = min(numRows, (int)s.size());
		vector<string> arr(Rows);
		bool Down = true;
		int row = 0;
		for (auto e : s)
		{
			arr[row] += e;

			if ((row == 0) || (row == Rows - 1))
			{
				Down = !Down;
			}
			row += Down ? 1 : -1;
		}
		string ret = "";
		for (size_t i = 0; i < Rows; ++i)
		{
			ret += arr[i];
		}
		return ret;
	}

}





namespace Solution2{
	string convert(string s, int numRows) {
		if (numRows == 1)
		{
			return s;
		}
		int  EmptyColGap = 2 * numRows - 2;
		string ret = "";
		for (size_t i = 0; i<numRows; ++i)
		{
			for (size_t j = 0; j + i<s.size(); j += EmptyColGap)
			{
				ret += s[i + j];
				//i==0  i==numRows-1行没有空闲的位置
				if (i != 0 && i != numRows - 1 && j + EmptyColGap - i<s.size())
				{
					ret += s[j + EmptyColGap - i];
				}
			}
		}
		return ret;
	} 
}


int main()
{
	string s = "LEETCODEISHIRING";
	string ret =Solution2:: convert(s, 4);
	cout << ret << endl;
	return 0;
}