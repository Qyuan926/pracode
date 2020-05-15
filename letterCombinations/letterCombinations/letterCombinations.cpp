#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace  std;
/*����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�

�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��

���룺"23"
�����["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/


//���û����㷨

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
		//ȡ��digit�ַ���������ӳ�䵽map���±�
		int digitsIndex = digits[Index] - '0' + 0;

		for (int j = 0; j<map[digitsIndex].size(); ++j)
		{
			//�����������
			str += map[digitsIndex][j];

			backtrace(digits, Index + 1, str, ret);
			str.pop_back();
		}


	}
};