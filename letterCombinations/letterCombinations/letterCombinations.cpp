#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace  std;
/*给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/


//采用回溯算法

class Solution {

public:
	vector<string> map = { " ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	vector<string> letterCombinations(string digits) {
		vector<string> ret;
		if (digits.empty())
		{
			return ret;
		}
		string str;
		backtrace(digits, 0, str, ret);
		return ret;

	}
	void backtrace(string digits, int Index, string str, vector<string>& ret)
	{
		if (Index == digits.size())
		{
			ret.push_back(str);
			return;
		}
		//取出digit字符串中数字映射到map的下标
		int digitsIndex = digits[Index] - '0' + 0;

		for (int j = 0; j<map[digitsIndex].size(); ++j)
		{
			//进入决策树，
			str += map[digitsIndex][j];

			backtrace(digits, Index + 1, str, ret);
			str.pop_back();
		}


	}
};